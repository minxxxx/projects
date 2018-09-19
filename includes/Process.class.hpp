#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Exceptions.class.hpp"
#include "IOperand.hpp"

#include <fstream>
#include <unistd.h>
#include <regex>
#include <float.h>
#include <climits>
#include <stdint.h>

class Process {
	std::string _processed;

public:
	Process(std::string);
	~Process();

	std::string getProcessed();

	void	setProcessed(std::string str);

	// Remove spaces
	void	delSpaces();

	// Find character location
	std::vector<int> findCharLocation(std::vector<int>, std::string, char);
	eOperandType getType(int j);
	void	findErrors();

};
