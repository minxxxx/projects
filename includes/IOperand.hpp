#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Exceptions.class.hpp"

// Operand types supported by the VM
typedef enum eOperandType {
	INT8 = 0,
	INT16,
	INT32,
	FLOAT,
	DOUBLE,
	ERROR,
	COMMENT
}	eOperandType;

class IOperand {
public:
	// Returns the precision of the instance's type
	virtual int getPrecision() const = 0;

	virtual eOperandType getType() const = 0;

	// Performs addition on two references of IOperand
	virtual IOperand const * operator+(IOperand const & rhs) const = 0;

	// Performs subtraction
	virtual IOperand const * operator-(IOperand const & rhs ) const = 0;

	// Performs multiplication
	virtual IOperand const * operator*(IOperand const & rhs ) const = 0;

	// Performs division
	virtual IOperand const * operator/(IOperand const & rhs ) const = 0;

	// Performs modulo
	virtual IOperand const * operator%(IOperand const & rhs ) const = 0;

	// op ov
	virtual bool operator!=(IOperand const & rhs ) const = 0;

	// Returns string representation of an instance
	virtual std::string const & toString() const = 0;
	

	// Virtual destructor
	virtual ~IOperand(void) {}
};

/*
class IOperand {
	public:
		virtual int getPrecision( void ) const = 0;
		virtual eOperandType getType( void ) const = 0;
		virtual IOperand const * operator+( IOperand const & virtual IOperand const * operator-( IOperand const & virtual IOperand const * operator*( IOperand const & virtual IOperand const * operator/( IOperand const & virtual IOperand const * operator%( IOperand const &
  // Precision of the type of the instance
  // Type of the instance
rhs ) const = 0; // Sum
rhs ) const = 0; // Difference rhs ) const = 0; // Product rhs ) const = 0; // Quotient rhs ) const = 0; // Modulo
 virtual std::string const & toString( void ) const = 0; // String representation of the instance
virtual ~IOperand( void ) {} };
*/
