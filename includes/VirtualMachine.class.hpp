#pragma once

#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdlib>
#include <stack>
#include "IOperand.hpp"
#include "Exceptions.class.hpp"
#include "Process.class.hpp"

#include <fstream>
#include <unistd.h>
#include <sstream>
#include <regex>
#include <float.h>
#include <climits>
#include <stdint.h>

////
// # include <fstream>
// # include <unistd.h>
// # include <sstream>
// # include <regex>
// # include <float.h>
// # include <climits>
// # include <stdint.h>
////

class VirtualMachine{
public:
	// std::vector isntead
	// std::stack<IOperand *> _operand;
	std::vector<const IOperand *> _operand;
	std::map<std::string, void (VirtualMachine::*)()> _iPointer;
	std::map<std::string, IOperand *(VirtualMachine::*)(const std::string &) const> _tPointer; 
	// typedef  const IOperand * (AbstractFactory::*OpFunction)(const std::string &) const;

	// private function
	// std::vector<OpFunction>   _create;

	// cpp f
	// _create.push_back(&AbstractFactory::createInt8);

	VirtualMachine();
	VirtualMachine(const VirtualMachine &);
	VirtualMachine& operator=(const VirtualMachine &);
	~VirtualMachine();

	// execute vm
	void	runVM(std::multimap<int, std::string>);

	void	push(IOperand *);
	void	pop();
	void	dump();
	void	add();
	void	sub();
	void	mul();
	void	div();
	void	mod();
	void	print();
	void	assert(IOperand *);
	// void	exit();

	IOperand *	createOperand(eOperandType type, const std::string & value) const;
	// IOperand const * VirtualMachine::createType(eOperandType type, std::string const & value) const;
	/*
	non-member function ‘IOperand* createType(eOperandType, const string&)’ cannot have cv-qualifier
 IOperand * createType(eOperandType type, const std::string & value) const{
                                                                     ^
VirtualMachine.class.cpp: In function ‘IOperand* createType(eOperandType, const string&)’:
VirtualMachine.class.cpp:128:13: error: invalid use of ‘this’ in non-member function
    result = this->createInt8(value);
	*/

private:
	IOperand *	createInt8(const std::string & value) const;
	IOperand *	createInt16(const std::string & value) const;
	IOperand *	createInt32(const std::string & value) const;
	IOperand *	createFloat(const std::string & value) const;
	IOperand *	createDouble(const std::string & value) const;
	IOperand *	extract(const std::string &, const std::string &);
	void	checkType(std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator, std::string &);
};

/*
IOperand const * createInt8( std::string const & value ) const;
IOperand const * createInt16( std::string const & value ) const;
IOperand const * createInt32( std::string const & value ) const;
IOperand const * createFloat( std::string const & value ) const;
IOperand const * createDouble( std::string const & value ) const;
*/
