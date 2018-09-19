#include "includes/Process.class.hpp"
#include "includes/Exceptions.class.hpp"
#include "includes/VirtualMachine.class.hpp"

Process::Process(std::string str) : _processed(str) {
	this->_processed = str;
}

Process::~Process () {}

std::string	Process::getProcessed() {
	return (this->_processed);
}

void	Process::setProcessed(std::string str) {
	this->_processed = str;
}

void	Process::delSpaces() {
	std::string temp;
	std::istringstream iss;
	std::string result = "";

	iss.str(this->_processed);
	while (iss >> temp /*>> std::ws*/) {
		if (result != "")
			result += " ";
		result += temp;
	}
	iss.clear();
	if (!result.empty())
		this->setProcessed(result);
}

std::vector<int> Process::findCharLocation(std::vector <int> location, std::string str, char find) {
	size_t 	i;
	i = 0;
	while (i < str.size()) {
		if (str[i] == find)
			location.push_back(i);
		i++;
	}
	if (find != '(' && find != ')')
		location.push_back(str.size());
	return (location);
}

eOperandType Process::getType(int j) {
	if (this->_processed.compare("int8") == 0 && j == 0)
		return (INT8);
	else if (this->_processed.compare("int16") == 0 && j == 0)
		return (INT16);
	else if (this->_processed.compare("int32") == 0 && j == 0)
		return (INT32);
	else if (this->_processed.compare("float") == 0 && j >= 0)
		return (FLOAT);
	else if (this->_processed.compare("double") == 0 && j >= 0)
		return (DOUBLE);
	else if (this->_processed.compare(";") == 0 && j == 0)
		return (COMMENT);
	else
		throw "an error occured";
	return (ERROR);
}

void	Process::findErrors() {
	std::string			checkBack;
	std::vector<int>	count_i;
	std::vector<int>	count_c;

	count_i = this->findCharLocation(count_i, this->_processed, '(');
	count_c = this->findCharLocation(count_c, this->_processed, ')');

	if (count_i.empty() || count_c.empty())
		throw "Bracket error";
	if (count_i.size() > 1 || count_c.size() > 1)
		throw "Too many brackets";
	checkBack = this->_processed.substr(count_c.front(), (this->_processed.size() - (count_c.front() + 1)));
	if (!(checkBack.empty()))
		throw "Invalid type";
}

