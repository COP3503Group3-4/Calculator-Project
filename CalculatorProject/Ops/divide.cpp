/*
 * divide.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: guorui
 */

#include "divide.h"
#include <typeinfo>

divide::divide() {}
/*
 * Version 2(Value pointer)
 */
Value* divide::divide(Value* a, Value* b){
switch(typeid(Value* a))
	{
	case typeid(*Fraction):
		if(typeid(Value* b) == typeid(Fraction*))
		       /*{int n1 = a.getNumerator() * b.getDenominator;
			int n2 = b.getNumerator() * a.getDenominator;
			int d = a.getDenominator() * b.getDenominator;
			return Fraction(n1-n2, d);}*/

		else if (typeid(Value* b) == typeid(*Expression))
			/*{return Expression(a - b);} */

		else if (typeid(Value* b) == typeid(*Number))
		  /*{int n1 = a.getNumerator() * b;
		 int n2 = a.getDenominator() * b;
		 int d = a.getDenominator() * b;
		  return Fraction(n1+n2, d);} */

		else if (typeid(Value* b) == typeid(*Log))
		  /*{return Expression(a,b);}*/

		else if (typeid(Value* b) == typeid(*NthRoot))
		   /*{return Expression(a,b);} */
		break;

	case typeid(*Expression):
		if(typeid(Value* b) == typeid(*Fraction))
				       /*{int n1 = a.getNumerator() * b.getDenominator;
					int n2 = b.getNumerator() * a.getDenominator;
					int d = a.getDenominator() * b.getDenominator;
					return Fraction(n1-n2, d);}*/

				else if (typeid(Value* b) == typeid(*Expression))
					/*{return Expression(a - b);} */

				else if (typeid(Value* b) == typeid(*Number))
				  /*{int n1 = a.getNumerator() * b;
				 int n2 = a.getDenominator() * b;
				 int d = a.getDenominator() * b;
				  return Fraction(n1+n2, d);} */

				else if (typeid(Value* b) == typeid(*Log))
				  /*{return Expression(a,b);}*/

				else if (typeid(Value* b) == typeid(*NthRoot))
				   /*{return Expression(a,b);} */
				break;

	 case typeid(*Number):
		if(typeid(Value* b) == typeid(*Fraction))
				       /*{int n1 = a.getNumerator() * b.getDenominator;
					int n2 = b.getNumerator() * a.getDenominator;
					int d = a.getDenominator() * b.getDenominator;
					return Fraction(n1-n2, d);}*/

				else if (typeid(Value* b) == typeid(*Expression))
					/*{return Expression(a - b);} */

				else if (typeid(Value* b) == typeid(*Number))
				  /*{int n1 = a.getNumerator() * b;
				 int n2 = a.getDenominator() * b;
				 int d = a.getDenominator() * b;
				  return Fraction(n1+n2, d);} */

				else if (typeid(Value* b) == typeid(*Log))
				  /*{return Expression(a,b);}*/

				else if (typeid(Value* b) == typeid(*NthRoot))
				   /*{return Expression(a,b);} */
				break;

	 case typeid(*Log):
		if(typeid(Value* b) == typeid(*Fraction))
				       /*{int n1 = a.getNumerator() * b.getDenominator;
					int n2 = b.getNumerator() * a.getDenominator;
					int d = a.getDenominator() * b.getDenominator;
					return Fraction(n1-n2, d);}*/

				else if (typeid(Value* b) == typeid(*Expression))
					/*{return Expression(a - b);} */

				else if (typeid(Value* b) == typeid(*Number))
				  /*{int n1 = a.getNumerator() * b;
				 int n2 = a.getDenominator() * b;
				 int d = a.getDenominator() * b;
				  return Fraction(n1+n2, d);} */

				else if (typeid(Value* b) == typeid(*Log))
				  /*{return Expression(a,b);}*/

				else if (typeid(Value* b) == typeid(*NthRoot))
				   /*{return Expression(a,b);} */
				break;

	 case typeid(*NthRoot):
		if(typeid(Value* b) == typeid(*Fraction))
				       /*{int n1 = a.getNumerator() * b.getDenominator;
					int n2 = b.getNumerator() * a.getDenominator;
					int d = a.getDenominator() * b.getDenominator;
					return Fraction(n1-n2, d);}*/

				else if (typeid(Value* b) == typeid(*Expression))
					/*{return Expression(a - b);} */

				else if (typeid(Value* b) == typeid(*Number))
				  /*{int n1 = a.getNumerator() * b;
				 int n2 = a.getDenominator() * b;
				 int d = a.getDenominator() * b;
				  return Fraction(n1+n2, d);} */

				else if (typeid(Value* b) == typeid(*Log))
				  /*{return Expression(a,b);}*/

				else if (typeid(Value* b) == typeid(*NthRoot))
				   /*{return Expression(a,b);} */
				break;
	 }

}

