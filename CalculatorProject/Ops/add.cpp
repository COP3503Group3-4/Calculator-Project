/*
 * Add->cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: Kevin
 */
//test

add::add(){

}

Value* add::add(Value* a, Value* b) {
	switch(typeid(Value* a))
	{
	case typeid(Fraction*):
			if(typeid(Value* b) == typeid(Fraction*)){
				int n1 = a->getNumerator() * b->getDenominator;
				int n2 = b->getNumerator() * a->getDenominator;
				int d = a->getDenominator() * b->getDenominator;
				return Fraction(n1+n2, d);
				}
	}

Value add(Fraction a, Expression b) {
	return Expression(a + b);
}

Value add(Fraction a, Number b)  {
	int n1 = a->getNumerator() * b;
	int n2 = a->getDenominator() * b;
	int d = a->getDenominator() * b;
	return Fraction(n1+n2, d);
}

Value add(Fraction a, Log b)  {
	return Expression(a,b);
}

Value add(Fraction a, NthRoot b) {
	return Expression(a,b);
}

Value add(Expression a, Expression b) {
	return Expression(a,b);
}

Value add(Expression a, Number b) {
	return Expression(a,b);
}

Value add(Expression a, Log b) {
	return Expression(a,b);
}

Value add(Expression a, NthRoot b) {
	return Expression(a,b);
}

Value add(Number a, Number b){
	return Number(a+b);
}

Value add(Number a, Log b) {
	return Expression(a,b);
}

Value add(Number a, NthRoot b){
	return Expression(a,b);
}

Value add(Log a, Log b){
	/*int s1=a->getBase();
	int s2=b->getBase();*/
	return Expression(a,b);
}

Value add(Log a, NthRoot b) {
	return Expression(a,b);
}

Value add(NthRoot a, NthRoot b) {
	return expression; //not sure about this one-> how could i make
	                   //sqrt(2) + sqrt(2) = 2sqrt(2)? Would that be handled
	                   //in the simplify method?
}


///////////////////////////////////////////////////////////////////////

/*
 * Add->cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: Kevin
 */

#include "Add->h"
#include <typeinfo>

add::add() {}
/*
 * Version 2(Value pointer)
 */
Value* add::add(Value* a, Value* b){
switch(typeid(Value* a))
	{
	case typeid(Fraction*):
		if(typeid(Value* b) == typeid(Fraction*)){
			int n1 = a->getNumerator() * b->getDenominator;
			int n2 = b->getNumerator() * a->getDenominator;
			int d = a->getDenominator() * b->getDenominator;
			return Fraction(n1+n2, d);
		}

		else if (typeid(Value* b) == typeid(Expression*))
			{return Expression(a , b);}

		else if (typeid(Value* b) == typeid(Number*))
		{
			int n1 = a->getNumerator() * b;
			int n2 = a->getDenominator() * b;
			int d = a->getDenominator() * b;
			return Fraction(n1+n2, d);
		}

		else if (typeid(Value* b) == typeid(Log*))
		  {return Expression(a,b);}

		else if (typeid(Value* b) == typeid(NthRoot*))
		   {return Expression(a,b);}
		break;

	case typeid(Expression*):
		if(typeid(Value* b) == typeid(Fraction*))
				    return Expression(a , b);

				else if (typeid(Value* b) == typeid(Expression*))
					return Expression(a , b);

				else if (typeid(Value* b) == typeid(Number*))
					return Expression(a , b);

				else if (typeid(Value* b) == typeid(Log*))
					return Expression(a,b);

				else if (typeid(Value* b) == typeid(NthRoot*))
				    return Expression(a,b);
				break;

	 case typeid(Number*):
		if(typeid(Value* b) == typeid(Fraction*)) {
			int n1 = b->getNumerator() * a;
			int n2 = b->getDenominator() * a;
			int d = b->getDenominator() * a;
			return Fraction(n1+n2, d);
		}

		else if (typeid(Value* b) == typeid(Expression*))
			return Expression(a,b);

		else if (typeid(Value* b) == typeid(Number*)) {
	   	  return Number(a + b);
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

