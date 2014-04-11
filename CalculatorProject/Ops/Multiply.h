/*
 * Multiply.h
 *
 *  Created on: Apr 5, 2014
 *      Author: Kevin
 */

#ifndef MULTIPLY_H_
#define MULTIPLY_H_

class multiply{
public:
	multiply();
	Value multiply(Fraction a, Fraction b);
	Value multiply(Fraction a, Expression b);
	Value multiply(Fraction a, Number b);
	Value multiply(Fraction a, Log b);
	Value multiply(Fraction a, NthRoot b);
	Value multiply(Expression a, Expression b);
	Value multiply(Expression a, Number b);
	Value multiply(Expression a, Log b);
	Value multiply(Expression a, NthRoot b);
	Value multiply(Number a, Number b);
	Value multiply(Number a, Log b);
	Value multiply(Number a, NthRoot b);
	Value multiply(Log a, Log b);
	Value multiply(Log a, NthRoot b);
	Value multiply(NthRoot a, NthRoot b);






};



#endif /* MULTIPLY_H_ */
