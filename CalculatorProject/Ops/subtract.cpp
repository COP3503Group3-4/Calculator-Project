/* subtract.cpp
 * has both version 1 and 2
 *scroll all the way down to see version 2
 *
 *  Created on: Apr 3, 2014
 *      Author: guorui
 */

#include "subtract.h"
#include <typeinfo>

subtract::subtract() {}

/*
 * Version 1(Overloading)
 */
Value subtract::subtract(Fraction a, Fraction b) {
	int n1 = a.getNumerator() * b.getDenominator;
	int n2 = b.getNumerator() * a.getDenominator;
	int d = a.getDenominator() * b.getDenominator;
	return Fraction(n1-n2, d);
}

Value subtract::subtract(Fraction a, Expression b) {
	return Expression(a - b);
}

Value subtract::subtract(Expression a, Fraction b) {
	return Expression(a- b);
}

Value subtract::subtract(Fraction a, Number b)  {
	int n1 = a.getNumerator() * b;
	int n2 = a.getDenominator() * b;
	int d = a.getDenominator() * b;
	return Fraction(n1-n2, d);
}

Value subtract::subtract(Number a, Fraction b)  {
	int n1 = b.getNumerator() * a;
	int n2 = b.getDenominator() * a;
	int d = b.getDenominator() * a;
	return Fraction(n1-n2, d);
}

Value subtract::subtract(Fraction a, Log b)  {
	return Expression(a,b);
}

Value subtract::subtract(Log a, Fraction b)  {
	return Expression(a,b);
}


Value subtract::subtract(Fraction a, NthRoot b) {
	return Expression(a,b);
}

Value subtract::subtract(NthRoot a, Fraction b) {
	return Expression(a,b);
}

Value subtract::subtract(Expression a, Expression b) {
	return Expression(a,b);
}

Value subtract::subtract(Expression a, Number b) {
	return Expression(a,b);
}


Value subtract::subtract(Number a, Expression b) {
	return Expression(a,b);
}


Value subtract::subtract(Expression a, Log b) {
	return Expression(a,b);
}

Value subtract::subtract(Log a, Expression b) {
	return Expression(a,b);
}


Value subtract::subtract(Expression a, NthRoot b) {
	return Expression(a,b);
}

Value subtract::subtract(NthRoot a, Expression b) {
	return Expression(a,b);
}


Value subtract::subtract(Number a, Number b){
	return Number(a+b);
}

Value subtract::subtract(Number a, Log b) {
	return Expression(a,b);
}

Value subtract::subtract(Log a, Number b) {
	return Expression(a,b);
}


Value subtract::subtract(Number a, NthRoot b){
	return Expression(a,b);
}

Value subtract::subtract(NthRoot a, Number b){
	return Expression(a,b);
}


Value subtract::subtract(Log a, Log b){
	return Expression(a,b);
}

Value subtract::subtract(Log a, NthRoot b) {
	return Expression(a,b);
}

Value subtract::subtract(NthRoot a, Log b) {
	return Expression(a,b);
}

Value subtract::subtract(NthRoot a, NthRoot b) {
	return Expression(a,b);
}

/*
 * Version 2(Value pointer)
 */

*Value subtract::subtract(*Value a, *Value b){
switch(typeid(*Value a))
	{
	case typeid(*Fraction):
		if(typeid(*Value b) == typeid(*Fraction))
		       {int n1 = a.getNumerator() * b.getDenominator;
			int n2 = b.getNumerator() * a.getDenominator;
			int d = a.getDenominator() * b.getDenominator;
			return Fraction(n1-n2, d);}

		else if (typeid(*Value b) == typeid(*Expression))
			{return Expression(a - b);}

		else if (typeid(*Value b) == typeid(*Number))
		  {int n1 = a.getNumerator() * b;
		 int n2 = a.getDenominator() * b;
		 int d = a.getDenominator() * b;
		  return Fraction(n1-n2, d);}

		else if (typeid(*Value b) == typeid(*Log))
		  {return Expression(a,b);}

		else if (typeid(*Value b) == typeid(*NthRoot))
		   {return Expression(a,b);}
		break;

	case typeid(*Expression):
		if(typeid(*Value b) == typeid(*Fraction))
				       {int n1 = a.getNumerator() * b.getDenominator;
					int n2 = b.getNumerator() * a.getDenominator;
					int d = a.getDenominator() * b.getDenominator;
					return Fraction(n1-n2, d);}

				else if (typeid(*Value b) == typeid(*Expression))
					{return Expression(a - b);}

				else if (typeid(*Value b) == typeid(*Number))
				  {int n1 = a.getNumerator() * b;
				 int n2 = a.getDenominator() * b;
				 int d = a.getDenominator() * b;
				  return Fraction(n1-n2, d);}

				else if (typeid(*Value b) == typeid(*Log))
				  {return Expression(a,b);}

				else if (typeid(*Value b) == typeid(*NthRoot))
				   {return Expression(a,b);}
				break;

	 case typeid(*Number):
		if(typeid(*Value b) == typeid(*Fraction))
						       {int n1 = a.getNumerator() * b.getDenominator;
							int n2 = b.getNumerator() * a.getDenominator;
							int d = a.getDenominator() * b.getDenominator;
							return Fraction(n1-n2, d);}

						else if (typeid(*Value b) == typeid(*Expression))
							{return Expression(a - b);}

						else if (typeid(*Value b) == typeid(*Number))
						  {int n1 = a.getNumerator() * b;
						 int n2 = a.getDenominator() * b;
						 int d = a.getDenominator() * b;
						  return Fraction(n1-n2, d);}

						else if (typeid(*Value b) == typeid(*Log))
						  {return Expression(a,b);}

						else if (typeid(*Value b) == typeid(*NthRoot))
						   {return Expression(a,b);}
						break;

	 case typeid(*Log):
		if(typeid(*Value b) == typeid(*Fraction))
								       {int n1 = a.getNumerator() * b.getDenominator;
									int n2 = b.getNumerator() * a.getDenominator;
									int d = a.getDenominator() * b.getDenominator;
									return Fraction(n1-n2, d);}
								else if (typeid(*Value b) == typeid(*Expression))
									{return Expression(a - b);}

								else if (typeid(*Value b) == typeid(*Number))
								  {int n1 = a.getNumerator() * b;
								 int n2 = a.getDenominator() * b;
								 int d = a.getDenominator() * b;
								  return Fraction(n1-n2, d);}

								else if (typeid(*Value b) == typeid(*Log))
								  {return Expression(a,b);}

								else if (typeid(*Value b) == typeid(*NthRoot))
								   {return Expression(a,b);}
								break;

	 case typeid(*NthRoot):
		if(typeid(*Value b) == typeid(*Fraction))
								       {int n1 = a.getNumerator() * b.getDenominator;
									int n2 = b.getNumerator() * a.getDenominator;
									int d = a.getDenominator() * b.getDenominator;
									return Fraction(n1-n2, d);}

								else if (typeid(*Value b) == typeid(*Expression))
									{return Expression(a - b);}

								else if (typeid(*Value b) == typeid(*Number))
								  {int n1 = a.getNumerator() * b;
								 int n2 = a.getDenominator() * b;
								 int d = a.getDenominator() * b;
								  return Fraction(n1-n2, d);}

								else if (typeid(*Value b) == typeid(*Log))
								  {return Expression(a,b);}

								else if (typeid(*Value b) == typeid(*NthRoot))
								   {return Expression(a,b);}
								break;
	 }

}




