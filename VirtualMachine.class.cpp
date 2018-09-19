#include "includes/VirtualMachine.class.hpp"
#include "includes/Operand.hpp"
#include "includes/IOperand.hpp"
#include "includes/Exceptions.class.hpp"

VirtualMachine::VirtualMachine() {
	this->_iPointer["pop"]	=	&VirtualMachine::pop;
	this->_iPointer["dump"] = &VirtualMachine::dump;
	this->_iPointer["add"] = &VirtualMachine::add;
	this->_iPointer["sub"] = &VirtualMachine::sub;
	this->_iPointer["mul"] = &VirtualMachine::mul;
	this->_iPointer["div"] = &VirtualMachine::div;
	this->_iPointer["mod"] = &VirtualMachine::mod;
	this->_iPointer["print"] = &VirtualMachine::print;
	this->_tPointer["int8"] = &VirtualMachine::createInt8;
	this->_tPointer["int16"] = &VirtualMachine::createInt16;
	this->_tPointer["int32"] = &VirtualMachine::createInt32;
	this->_tPointer["float"] = &VirtualMachine::createFloat;
	this->_tPointer["double"] = &VirtualMachine::createDouble;
}

VirtualMachine::VirtualMachine(const VirtualMachine & other) {
	this->_operand = other._operand;
	this->_iPointer = other._iPointer;
	this->_tPointer = other._tPointer;
}

VirtualMachine & VirtualMachine::operator=(const VirtualMachine & other) {
	if (&other != this) {
		this->_operand = other._operand;
		this->_iPointer = other._iPointer;
		this->_tPointer = other._tPointer;
	}
	return *this;
}

VirtualMachine::~VirtualMachine() {}

void	VirtualMachine::runVM(std::multimap<int, std::string> instruction) {
	Process *checker;
	std::string compare;
	std::multimap<int, std::string>::iterator pt;

	try {
		for (std::multimap<int, std::string>::iterator it = instruction.begin(); it != instruction.end(); ++it) {
			if (!(it->second.empty())) {
				if (this->_iPointer.find(it->second) == this->_iPointer.end()) {
					if (it->second.compare(0, it->second.size(), "push") == 0 || it->second.compare(0, it->second.size(), "assert") == 0) {
						pt = it;
						++pt;
						checker = new Process(pt->second);
						checker->findErrors();
						this->checkType(pt, it, compare);
					}
					if (this->_tPointer.find(compare) == this->_tPointer.end() && it->second.find(";") == std::string::npos)
						throw "Invalid instruction.";
				}
				else {
					(this->*_iPointer[it->second])();
				}
			}
		}
	} catch (const char* m) {
		std::cerr << "Error: " << m << std::endl;
	}
}

IOperand	*VirtualMachine::extract(const std::string& type, const std::string & str) {
	Process *proc = new Process(type);
	int 	j = 0;
	IOperand *result;
	std::string args;
	std::string valid = "-.0123456789";

	args = str.substr(str.find("(") + 1, (str.find(")") - (str.find("(") + 1)));
	try {
		for (size_t i = 0; i < args.size(); i++) {
			if (valid.find(args[i]) == std::string::npos)
				throw "Invalid operand.";
			if (args[i] == '.')
				j++;
		}
	} catch (const char* m) {
		std::cerr << "Error: " << m << std::endl;
	}
	try {
		if (args.compare(0, args.size(), "-") == 0 || args.compare(0, args.size(), ".") == 0)
			throw "Operand isn't a numerical value.";
	} catch (const char* m) {
		std::cerr << "Error: " << m << std::endl;
	}
	try {
		if (args.empty())
			throw "Error: Empty value declared.";
	} catch (const char* m) {
		std::cerr << "Error: " << m << std::endl;
	}
	result = this->createOperand(proc->getType(j), args);
	delete (proc);
	return (result);
}

// #####################################################
// 		Create Operand
// #####################################################

IOperand *	VirtualMachine::createOperand(eOperandType type, const std::string & value) const {
	IOperand *result;
	try {
		switch (type) {
			case INT8:
				result = this->createInt8(value);
				break;
			case INT16:
				result = this->createInt16(value);
				break;
			case INT32:
				result = this->createInt32(value);
				break;
			case FLOAT:
				result = this->createFloat(value);
				break;
			case DOUBLE:
				result = this->createDouble(value);
				break;
			case ERROR:
				throw "An error occured";
			case COMMENT:
				throw "comment detected";
				break;
		}
	} catch (const char* e) {
		std::cerr << "Error: " << e << std::endl;
	}
	return (result);
}

// #####################################################
// 		Instructions and such
// #####################################################

void	VirtualMachine::push(IOperand *op) {
	this->_operand.push_back(op);
}

void	VirtualMachine::pop() {
	if (this->_operand.empty())
		std::cout << "Error: the stack is empty." << std::endl;
	if (!(this->_operand.empty()))
		this->_operand.pop_back();
}

void	VirtualMachine::dump() {
	std::vector<const IOperand *> *op = new std::vector<const IOperand *>;

	(*op) = this->_operand;
	while (!(op->empty())) {
		std::cout << op->back()->toString() << std::endl;
		op->pop_back();
	}
	delete (op);
}

void	VirtualMachine::add() {
	const IOperand *val1;
	const IOperand *val2;

	if (this->_operand.size() >= 2) {
		val1 = this->_operand.back();
		this->_operand.pop_back();
		val2 = this->_operand.back();
		this->_operand.pop_back();
		this->_operand.push_back((*val2) + (*val1));
	} else
		throw "Error: the stack does not contain enough values.";
}

void	VirtualMachine::sub() {
	const IOperand *val1;
	const IOperand *val2;

	if (this->_operand.size() >= 2) {
		val1 = this->_operand.back();
		this->_operand.pop_back();
		val2 = this->_operand.back();
		this->_operand.pop_back();
		this->_operand.push_back((*val2) - (*val1));
	} else
		throw "Error: the stack does not contain enough values.";
}

void	VirtualMachine::mul() {
	const IOperand *val1;
	const IOperand *val2;

	if (this->_operand.size() >= 2) {
		val1 = this->_operand.back();
		this->_operand.pop_back();
		val2 = this->_operand.back();
		this->_operand.pop_back();
		this->_operand.push_back((*val2) * (*val1));
	} else
		throw "Error: the stack does not contain enough values.";
}

void	VirtualMachine::div() {
	const IOperand *val1;
	const IOperand *val2;

	if (this->_operand.size() >= 2) {
		val1 = this->_operand.back();
		this->_operand.pop_back();
		val2 = this->_operand.back();
		this->_operand.pop_back();
		this->_operand.push_back((*val2) / (*val1));
	} else
		throw "Error: the stack does not contain enough values.";
}

void	VirtualMachine::mod() {
	const IOperand *val1;
	const IOperand *val2;

	if (this->_operand.size() >= 2) {
		val1 = this->_operand.back();
		this->_operand.pop_back();
		val2 = this->_operand.back();
		this->_operand.pop_back();
		this->_operand.push_back((*val2) % (*val1));
	} else
		throw "Error: the stack does not contain enough values.";
}

//void	assert(IOperand *);

// void	VirtualMachine::assert(IOperand *rhs) {
// 	if (!this->_operand.empty()) {
// 		if (this->_operand.back() != rhs)
// 			std::cout << "Error: The values do not match." << std::endl;
// 	} else
// 		std::cout << "Error: The stack is empty." << std::endl;
// }

void	VirtualMachine::assert(IOperand *rhs) {
	const IOperand *v1;
	const IOperand *v2;
	if (this->_operand.size() >= 1) {
		v1 = this->_operand.back();
		this->_operand.pop_back();
		this->_operand.push_back(rhs);
		v2 = this->_operand.back();
		this->_operand.pop_back();
		this->_operand.push_back(v1);
		if (*v1 != *v2)
			throw "Assert instruction is not true.";
	} else
		throw "Error: the stack does not contain enough values.";
}

void	VirtualMachine::print() {
	try {
		if (!this->_operand.empty()) {
			const IOperand *op1;
			const Operand<char> *op2;

			op1 = this->_operand.back();
				if (op1->getType() != INT8)
					throw "Cannot print a non-ascii character!";
				op2 = static_cast<const Operand<char>*>(op1);
				std::cout << op2->getValue() << std::endl;
			
		} else
			throw "the stack does not contain enough values.";
	} catch (const char* e) {
		std::cerr << "Error: " << e << std::endl;
	}
}

// #####################################################
// 		Create operands and such
// #####################################################

IOperand *	VirtualMachine::createInt8(const std::string & value) const {
	int8_t nbr = static_cast<int8_t>(atoi(value.c_str()));

	if (nbr < SCHAR_MIN)
		throw "Underflor on a value!";
	if (nbr > SCHAR_MAX)
		throw "Overflow on a value!";
	return (new Operand<int8_t>(INT8, static_cast<int8_t>(nbr)));
}

IOperand *	VirtualMachine::createInt16(const std::string & value) const {
	int16_t nbr = static_cast<int16_t>(atoi(value.c_str()));
	if (nbr == -1)
		throw "Overflow on a value!";
	if (nbr < SHRT_MIN)
		throw "Underflor on a value!";
	return (new Operand<int16_t>(INT16, static_cast<int16_t>(nbr)));
}

IOperand *	VirtualMachine::createInt32(const std::string & value) const {
	int nbr = atoi(value.c_str());
	if (nbr > INT_MAX)
		throw "Overflow on a value!";
	if (nbr < INT_MIN)
		throw "Underflow on a value!";
	return (new Operand<int32_t>(INT32, nbr));
}

IOperand *	VirtualMachine::createFloat(const std::string & value) const {
	double nbr = static_cast<float>(atof(value.c_str()));
	if (nbr > FLT_MAX)
		throw "Overflow on a value!";
	if (nbr < -FLT_MAX)
		throw "Underflow on a value!";
	return (new Operand<float>(FLOAT, static_cast<float>(nbr)));
}

IOperand *	VirtualMachine::createDouble(const std::string & value) const {
	long double nbr = static_cast<double>(atof(value.c_str()));
	if (nbr > DBL_MAX)
		throw "Overflow on a value!";
	if (nbr < -DBL_MAX)
		throw "Underflow on a value!";
	return (new Operand<double>(DOUBLE, static_cast<double>(nbr)));
}

// #####################################################
// 		Other stuff
// #####################################################

void	VirtualMachine::checkType(std::multimap<int, std::string>::iterator pt, std::multimap<int, std::string>::iterator it, std::string &compare) {
	std::multimap<int, std::string>::iterator index;

	if (pt->second.find("(") != std::string::npos && pt->second.find(")") && pt->first == it->first) {
		index = pt;
		++index;
		if (index->first == it->first && index->first)
			throw ("Too many arguments");
		compare = pt->second.substr(0, pt->second.find("("));
		if (this->_tPointer.find(compare) == this->_tPointer.end())
			throw ("Syntax error occured.");
		else {
				if (it->second.compare(0, it->second.size(), "push") == 0) {
				this->push(this->extract(compare, pt->second));
			} else {
				this->assert(this->extract(compare, pt->second));
			}
		}
	} else {
		throw ("Invalid instruction");
	}
}

/*
void Instructions::assert(const std::string &opType)
{
  if (_stackTable.size() == 0)
  {
     throw Exception::AssertOnEmptyStack();
  }

  StackVM v;
  std::string opValue = v.getValue(opType);
  const IOperand &operand = **(_stackTable.rbegin());

  if (opValue != operand.toString())
  {
    throw Exception::AssertError();
  }
  return ;
}
*/
