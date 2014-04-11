/*
 * multiply->cpp
 *
 *  Created on: Apr 5, 2014
 *      Author: Kevin
 */


multiply::multiply(){

}

/*I do not have any understanding of how Expressions will be treated
 * so any function including or returning an expression
 * is probably wrong as of right now
 */

Value multiply(Fraction a, Fraction b) {
	int n = a->getNumerator() * b->getNumerator;
	int d = a->getDenominator() * b->getDenominator;
	return Fraction(n, d);
}

Value multiply(Fraction a, Expression b) {
	return Expression(a + b);
}

Value multiply(Fraction a, Number b)  {
	int n = a->getNumerator() * b;
	int d = a->getDenominator() * b;
	return Fraction(n, d);
}

Value multiply(Fraction a, Log b)  {
	return Expression(a,b);
}

Value multiply(Fraction a, NthRoot b) {
	return Expression(a,b);
}

Value multiply(Expression a, Expression b) {
	return Expression(a,b);
}

Value multiply(Expression a, Number b) {
	return Expression(a,b);
}

Value multiply(Expression a, Log b) {
	return Expression(a,b);
}

Value multiply(Expression a, NthRoot b) {
	return Expression(a,b);
}

Value multiply(Number a, Number b){
	return Number(a*b);
}

Value multiply(Number a, Log b) {
	return Expression(a,b);
}

Value multiply(Number a, NthRoot b){
	return Expression(a,b);
}

Value multiply(Log a, Log b){  //Not sure how to do this one
	/*int s1=a->getBase();
	int s2=b->getBase();*/
	return Expression(a,b);
}

Value multiply(Log a, NthRoot b) {
	return Expression(a,b);
}

Value multiply(NthRoot a, NthRoot b) {
	return expression; //not sure about this one-> how could i make
	                   //sqrt(2) + sqrt(2) = 2sqrt(2)? Would that be handled
	                   //in the simplify method?
}



///////////////////////////////////////////////////////////
/*
 * Version 2(Pointers)
 */

/*
 * multiply->cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: Kevin
 */

#include "multiply->h"
#include <typeinfo>

multiply::multiply() {}
/*
 * Version 2(Value pointer)
 */
Value* multiply::multiply(Value* a, Value* b){
switch(typeid(Value* a))
	{
	case typeid(Fraction*):
		if(typeid(Value* b) == typeid(Fraction*)){
			int n = a->getNumerator() * b->getNumerator;
			int d = a->getDenominator() * b->getDenominator;
			return Fraction(n , d);
		}

		else if (typeid(Value* b) == typeid(Expression*))
			{return Expression(a , b);}

		else if (typeid(Value* b) == typeid(Number*))
		{
			int n = a->getNumerator() * b;
			int d = a->getDenominator() * b;
			return Fraction(n, d);
		}

		else if (typeid(Value* b) == typeid(Log*))
			return Expression(a,b);

		else if (typeid(Value* b) == typeid(NthRoot*))
			return Expression(a,b);
		break;

	case typeid(Expression*):
		if(typeid(Value* b) == typeid(Fraction*))
				    return Expression(a , b);

		else if (typeid(Value* b) == typeid(Expression*))
			return Expression(a , b);

		else if (typeid(Value* b) == typeid(Number*))
			return Expression(a , b);

		else if (typeid(Value* b) == typeid(Log*))
			return Expression(a , b);

		else if (typeid(Value* b) == typeid(NthRoot*))
		    return Expression(a,b);
		break;

	 case typeid(Number*):
		if(typeid(Value* b) == typeid(Fraction*)) {
			int n = a->getNumerator() * b;
			int d = a->getDenominator() * b;
			return Fraction(n, d);
		}

		else if (typeid(Value* b) == typeid(Expression*))
			return Expression(a,b);

		else if (typeid(Value* b) == typeid(Number*)) {
	   	  return Number(a * b);
		  }

		else if (typeid(Value* b) == typeid(Log*))
			return Expression(a,b);

		else if (typeid(Value* b) == typeid(NthRoot*))
			return Expression(a,b);
		break;

	 case typeid(Log*):
		if(typeid(Value* b) == typeid(Fraction*))
			return Expression(a,b);

		else if (typeid(Value* b) == typeid(Expression*))
			return Expression(a , b);

		else if (typeid(Value* b) == typeid(Number*))
			return Expression(a,b);

		else if (typeid(Value* b) == typeid(Log*))
			return Expression(a,b);

		else if (typeid(Value* b) == typeid(NthRoot*))
			return Expression(a,b);
		break;

	 case typeid(NthRoot*):
		if(typeid(Value* b) == typeid(Fraction*))
			return Expression(a,b);

		else if (typeid(Value* b) == typeid(Expression*))
			return Expression(a , b);

		else if (typeid(Value* b) == typeid(Number*))
		  return Expression(a,b);

		else if (typeid(Value* b) == typeid(Log*))
			return Expression(a,b);

		else if (typeid(Value* b) == typeid(NthRoot*))
			return Expression(a,b);
		break;
	 }

}

