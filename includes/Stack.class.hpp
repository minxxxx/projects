#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "Exceptions.class.hpp"
#include "VirtualMachine.class.hpp"

#include <unistd.h>
#include <sstream>
#include <regex>
#include <float.h>
#include <climits>
#include <stdint.h>

typedef int32_t i32;

class	StackVM
{
public:
  StackVM();
  StackVM(const StackVM &);
  StackVM& operator=(const StackVM &);
  
  std::vector<i32> memory;

  // map instructions and return them as a list
  std::multimap<int, std::string> getInstruction();

  // Read from file or standinput
  int read(const std::string);
  void  storeInstructions(int, std::string);

  ~StackVM();

private:
	std::multimap<int, std::string> _instruction;
};

/*
for (std::multimap<char, int>::iterator it = mapOfPos.begin(); it != mapOfPos.end(); it++)
	std::cout << it->first << " :: " << it->second << std::endl;
*/
