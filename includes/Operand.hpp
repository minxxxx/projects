#pragma once

#include "VirtualMachine.class.hpp"
#include "IOperand.hpp"
#include "Exceptions.class.hpp"

template <typename T>
class Operand : public IOperand {
public:
	Operand(void) : _type(INT8), _value(0) {
		return ;
	}

	Operand(const eOperandType type, const T value) : _value(value), _type(type) {
		return ;
	}

	~Operand(void){return;}

	Operand& operator=(const Operand &other) {
		return (*new Operand(other));
	}

	// ######################################################
	// IOperand functions start
	// ######################################################

	// IOperand getPrecision funct
	int 	getPrecision(void) const {
		return (_type);
	}

	eOperandType 		getType(void) const {
		return (this->_type);
	}

	T 	getValue(void) const {
		return (this->_value);
	}

	// op adding stuff
	IOperand const *	operator+(IOperand const & rhs) const {
		eOperandType 	type;
		int 			integer = 0;
		double 			r_number = 0;

		if (_type == rhs.getPrecision()) {
			return (new Operand<T>(_type, static_cast<const Operand<T>*>(&rhs)->getValue() + _value));
		} else {
			type = rhs.getType();
			if (type == INT8 || type == INT16 || type == INT32) {
				integer = std::stoi(rhs.toString()) + _value;
				return (_create.createOperand(type, std::to_string(integer)));
			}
			if (type == FLOAT || type == DOUBLE) {
				r_number = std::stod(rhs.toString()) + _value;
				return (_create.createOperand(type, std::to_string(r_number)));
			}
		}
		return (NULL);
	}

	// op ov
	bool	operator!=(IOperand const & rhs) const {
		// return !(static_cast<const Operand<T>*>(&rhs)->getValue() != _value));
		return !(static_cast<const Operand<T>*>(&rhs)->getValue() == _value);
	}

	// op subtract stuff
	IOperand const *	operator-(IOperand const & rhs) const {
		eOperandType 	type;
		int 			integer = 0;
		double 			r_number = 0;

		if (_type == rhs.getPrecision()) {
			return (new Operand<T>(_type, static_cast<const Operand<T>*>(&rhs)->getValue() - _value));
		} else {
			type = rhs.getType();
			if (type == INT8 || type == INT16 || type == INT32) {
				integer = std::stoi(rhs.toString()) - _value;
				return (_create.createOperand(type, std::to_string(integer)));
			}
			if (type == FLOAT || type == DOUBLE) {
				r_number = std::stod(rhs.toString()) - _value;
				return (_create.createOperand(type, std::to_string(r_number)));
			}
		}
		return (NULL);
	}

	// op multiply stuff
	IOperand const *	operator*(IOperand const & rhs) const {
		eOperandType 	type;
		int 			integer = 0;
		double 			r_number = 0;

		if (_type == rhs.getPrecision()) {
			return (new Operand<T>(_type, static_cast<const Operand<T>*>(&rhs)->getValue() * _value));
		} else {
			if (_type > getPrecision())
				type = _type;
			else
				type = rhs.getType();
			if (type == INT8 || type == INT16 || type == INT32) {
				integer = std::stoi(rhs.toString()) * _value;
				return (_create.createOperand(type, std::to_string(integer)));
			}
			if (type == FLOAT || type == DOUBLE) {
				r_number = std::stod(rhs.toString()) * _value;
				return (_create.createOperand(type, std::to_string(r_number)));
			}
		}
		return (NULL);
	}

	// op divide stuff
	IOperand const *	operator/(IOperand const & rhs) const {
		eOperandType 	type;
		int 			integer = 0;
		double 			r_number = 0;

		if (_type == rhs.getPrecision()) {
			if (_value == 0 || !(_value))
				throw "Division/Modulo by 0!";
			return (new Operand<T>(_type, static_cast<const Operand<T>*>(&rhs)->getValue() / _value));
		} else {
			if (_value == 0 || !(_value))
				throw "Division/Modulo by 0!";
			if (_type > getPrecision())
				type = _type;
			else
				type = rhs.getType();
			if (type == INT8 || type == INT16 || type == INT32) {
				integer = std::stoi(rhs.toString()) / _value;
				return (_create.createOperand(type, std::to_string(integer)));
			}
			if (type == FLOAT || type == DOUBLE) {
				r_number = std::stod(rhs.toString()) / _value;
				return (_create.createOperand(type, std::to_string(r_number)));
			}
		}
		return (NULL);
	}

	// op mod on stuff
	IOperand const *	operator%(IOperand const & rhs) const {
		eOperandType 	type;
		int 			integer = 0;
		const Operand<T> *getV = NULL;

		if (_type == rhs.getPrecision()) {
			if (_value == 0 || !(_value))
				throw "Division/Modulo by 0!";
			getV = static_cast<const Operand<T>*>(&rhs);
			return (new Operand<T>(_type, static_cast<long int>(getV->getValue()) % static_cast<long int>(_value)));
			// return (new Operand<T>(_type, static_cast<const Operand<T>*>(&rhs)->getValue()) % static_cast<long int>(_value)));
		} else {
			if (_value == 0 || !(_value))
				throw "Division/Modulo by 0!";
			if (_type > getPrecision())
				type = _type;
			else
				type = rhs.getType();
			if (type == INT8 || type == INT16 || type == INT32) {
				// integer = std::stoi(rhs.toString()) % _value;
				// return (_create.createOperand(type, std::to_string(integer)));
				integer = static_cast<long int>(std::stoi(rhs.toString())) % static_cast<long int>(_value);
        		return (_create.createOperand(type, std::to_string(integer)));
			}
			if (type == FLOAT || type == DOUBLE) {
				throw "Cannot mod floating point values!";
			}
			// if (type == FLOAT) {
			// 	r_number = std::stod(rhs.toString()) % _value;
			// 	return (_create.createOperand(type, std::to_string(r_number)));
			// }
		}
		return (NULL);
	}

	// to string
	std::string const &	toString(void) const {
		std::stringstream ss;
		if (this->_type == INT8)
			ss << static_cast<int32_t>(this->_value);
		else
			ss << this->_value;
		return (*new std::string(ss.str()));
	}

private:
	T 					_value;
	const eOperandType	_type;
	VirtualMachine		_create;
	
};

/*
virtual int getPrecision() const = 0;
virtual eOperandType getType() const = 0;
virtual IOperand const * operator+(IOperand const & rhs) const = 0;
virtual std::string const & toString() const = 0;
virtual ~IOperand(void) {}
*/
