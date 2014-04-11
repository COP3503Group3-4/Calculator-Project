/*
 * subtract.h
 *
 *  Created on: Apr 3, 2014
 *      Author: guorui
 */

/*
	 * Fraction a
	 * Fraction b
	 * subtract(a,b) {
	 * 		add(a, b.negative());
	 * }
	 * subtract(b,a) {
	 * 		add(b, a.negative());
	 * }
	 */

#ifndef SUBTRACT_H_
#define SUBTRACT_H_

class subtract {
public:
	subtract();

/*
 * Version 1(Overloading):
 */
	Value subtract(Fraction a, Fraction b);
	Value subtract(Fraction a, Expression b);
	Value subtract(Expression a, Fraction b);
	Value subtract(Fraction a, Number b);
	Value subtract(Number b, Fraction b);
	Value subtract(Fraction a, Log b);
	Value subtract(Log a, Fraction b);
	Value subtract(Fraction a, NthRoot b);
	Value subtract(NthRoot a, Fraction b);
	Value subtract(Expression a, Expression b);
	Value subtract(Expression a, Number b);
	Value subtract(Number a, Expression b);
	Value subtract(Expression a, Log b);
	Value subtract(Log a, Expression b);
	Value subtract(Expression a, NthRoot b);
	Value subtract(NthRoot a, Expression b);
	Value subtract(Number a, Number b);
	Value subtract(Number a, Log b);
	Value subtract(Log a, Number b);
	Value subtract(Number a, NthRoot b);
	Value subtract(NthRoot a, Number b);
	Value subtract(Log a, Log b);
	Value subtract(Log a, NthRoot b);
	Value subtract(NthRoot a, Log b);

/*
 * Version 2(Value Pointer):
 */

	Value* subtract(Value* a, Value* b);




};

#endif /* SUBTRACT_H_ */
