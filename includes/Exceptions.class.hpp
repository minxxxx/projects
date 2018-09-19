#pragma once

#include <iostream>
#include <exception>

#include <fstream>
#include <unistd.h>
#include <sstream>
#include <regex>
#include <float.h>
#include <climits>
#include <stdint.h>

class Exception : public std::exception {
	public:
		Exception(std::string &message) throw();
		virtual ~Exception() throw();
		virtual const char* what() const throw();
	
	private:
		std::string _message;
};
