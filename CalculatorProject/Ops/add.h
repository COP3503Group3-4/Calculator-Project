/*
 * Add.h
 *
 *  Created on: Apr 3, 2014
 *      Author: Kevin
 */

#ifndef ADD_H_
#define ADD_H_

class add{
public: 
	add();
	Value add(Fraction a, Fraction b);
	Value add(Fraction a, Expression b);
	Value add(Fraction a, Number b);
	Value add(Fraction a, Log b);
	Value add(Fraction a, NthRoot b);
	Value add(Expression a, Expression b);
	Value add(Expression a, Number b);
	Value add(Expression a, Log b);
	Value add(Expression a, NthRoot b);
	Value add(Number a, Number b);
	Value add(Number a, Log b);
	Value add(Number a, NthRoot b);
	Value add(Log a, Log b);
	Value add(Log a, NthRoot b);
	Value add(NthRoot a, NthRoot b);






};


//////////////////////////////////
/*
 * Version2
 *
 */

Value* add(Value* a, Value* b);


#endif /* ADD_H_ */
