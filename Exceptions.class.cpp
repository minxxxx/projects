#include "includes/Exceptions.class.hpp"

Exception::Exception(std::string &message) throw() {
	this->_message = message;
}

Exception::~Exception() throw() {}

const char*		Exception::what() const throw() {
	return (this->_message.c_str());
}
