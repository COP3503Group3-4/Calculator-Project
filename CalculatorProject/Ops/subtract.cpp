/* subtract.cpp
 * has both version 1 and 2
 *scroll all the way down to see version 2
 *
 *  Created on: Apr 3, 2014
 *      Author: guorui
 */

#include <subtract.h>
#include <typeinfo>
#include <sstream>

//subtract::subtract() {}

/*
 * Version 1(Overloading)
 */
/*
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
*/

/*
 * Version 2(Value pointer)
 */

Value* subtract::subtract(Value* a, Value* b){
	ostringstream combined;
	    RationalFraction* f1 = dynamic_cast<RationalFraction*>(a);
	    RationalFraction* f2 = dynamic_cast<RationalFraction*>(b);
	    Log* l1 = dynamic_cast<Log*>(a);
	    Log* l2 = dynamic_cast<Log*>(b);
	    RationalNumber* rN1 = dynamic_cast<RationalNumber*>(a);
	    RationalNumber* rN2 = dynamic_cast<RationalNumber*>(b);
	    //Expression* ex1 = dynamic_cast<Expression*>(a);
	    //Expression* ex2 = dynamic_cast<Expression*>(b);
	    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(a);
	    IrrationalNumber* iRN2 = dynamic_cast<IrrationalNumber*>(b);
	    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(a);
	    //IrrationalFraction* iRF2 = dynamic_cast<IrrationalFraction*>(b);
switch(typeid(Value* a))
	{
	case typeid(Fraction*):
		if(typeid(Value* b) == typeid(Fraction*))
		       {int n1 = f1->getNumerator() * f2->getDenominator();
		        cout<<"N1: "<<n1<<endl;
		        int n2 = f2->getNumerator() * f1->getDenominator();
		        cout<<"N2: "<<n2<<endl;
		        int d = f1->getDenominator() * f2->getDenominator();
		        cout<<"D: "<<d<<endl;
		        Value* f3 = new RationalFraction(n1-n2,d);
		        return f3;}

		else if (typeid(Value* b) == typeid(Expression*))
			{return Expression(a - b);}

		else if (typeid(Value* b) == typeid(Number*))
		  {int numerFN = rN2->getNumValue();
          RationalFraction* fN2 = new RationalFraction(numerFN,1);
          int n1 = f1->getNumerator() * fN2->getDenominator();
          cout<<"N1: "<<n1<<endl;
          int n2 = fN2->getNumerator() * f1->getDenominator();
          cout<<"N2: "<<n2<<endl;
          int d = f1->getDenominator() * fN2->getDenominator();
          cout<<"d: "<<d<<endl;
          Value* f3 = new RationalFraction(n1-n2,d);
          return f3;}

		else if (typeid(Value* b) == typeid(Log*))
		  {return Expression(a,b);}

		else if (typeid(Value* b) == typeid(NthRoot*))
		   {return Expression(a,b);}
		break;

	case typeid(Expression*):
		if(typeid(Value* b) == typeid(Fraction*))
				       {int n1 = a.getNumerator() * b.getDenominator;
					int n2 = b.getNumerator() * a.getDenominator;
					int d = a.getDenominator() * b.getDenominator;
					return Fraction(n1-n2, d);}

				else if (typeid(Value* b) == typeid(Expression*))
					{return Expression(a - b);}

				else if (typeid(Value* b) == typeid(Number*))
				  {int n1 = a.getNumerator() * b;
				 int n2 = a.getDenominator() * b;
				 int d = a.getDenominator() * b;
				  return Fraction(n1-n2, d);}

				else if (typeid(Value* b) == typeid(Log*))
				  {return Expression(a,b);}

				else if (typeid(Value* b) == typeid(NthRoot*))
				   {return Expression(a,b);}
				break;

	 case typeid(Number*):
		if(typeid(Value* b) == typeid(Fraction*))
						       {int numerFN = rN1->getNumValue();
					            RationalFraction* fN2 = new RationalFraction(numerFN,1);
					            int n1 = f2->getNumerator() * fN2->getDenominator();
					            cout<<"N1: "<<n1<<endl;
					            int n2 = fN2->getNumerator() * f2->getDenominator();
					            cout<<"N2: "<<n2<<endl;
					            int d = f2->getDenominator() * fN2->getDenominator();
					            cout<<"d: "<<d<<endl;
					            Value* f3 = new RationalFraction(n1-n2,d);
					            return f3;}

						else if (typeid(Value* b) == typeid(Expression*))
							{return Expression(a - b);}

						else if (typeid(Value* b) == typeid(Number*))
						  {int num1 = rN1->getNumValue();
					        int num2 = rN2->getNumValue();
					        int numAdded = num1 + num2;
					        Value* summedNum = new RationalNumber(numAdded);
					        cout<<numAdded<<endl;
					        return summedNum;}

						else if (typeid(Value* b) == typeid(Log*))
						  {return Expression(a,b);}

						else if (typeid(Value* b) == typeid(NthRoot*))
						   {return Expression(a,b);}
						break;

	 case typeid(Log*):
		if(typeid(Value* b) == typeid(Fraction*))
								       {return Expression(a,b);}

								else if (typeid(Value* b) == typeid(Number*))
								  {return Expression(a,b);}

								else if (typeid(Value* b) == typeid(Log*))
								  {Value* lB1 = l1->getNum1();
							        Value* lB2 = l2->getNum1();
							        Value* lIV1 = l1->getNum2();
							        Value* lIV2 = l2->getNum2();
							        if(isEqual(lB1,lB2)){
							            RationalNumber* rNB1 = dynamic_cast<RationalNumber*>(lB1);
							            RationalNumber* rNB2 = dynamic_cast<RationalNumber*>(lB2);
							            if( rNB1 && rNB2 ){
							                RationalNumber* rNIV1 = dynamic_cast<RationalNumber*>(lIV1);
							                RationalNumber* rNIV2 = dynamic_cast<RationalNumber*>(lIV2);
							                if( rNIV1 && rNIV2 ){
							                    int value1 = rNIV1->getNumValue();
							                    int value2 = rNIV2->getNumValue();
							                    cout<<value1<<endl;
							                    cout<<value2<<endl;
							                    int finalVal = value1+value2;
							                    cout<<finalVal<<endl;
							                    Value* finalRNIV = new RationalNumber(finalVal);
							                    Value* logSimp = new Log(lB1, finalRNIV);
							                    logSimp->printInfo();
							                    cout<<endl;
							                    return logSimp;
							                }

							            }
							        }
								  }

								else if (typeid(Value* b) == typeid(NthRoot*))
								   {return Expression(a,b);}
								break;

	 case typeid(NthRoot*):
		if(typeid(Value* b) == typeid(Fraction*))
								       {return Expression(a,b);}

								else if (typeid(Value* b) == typeid(Expression*))
									{return Expression(a,b);}

								else if (typeid(Value* b) == typeid(Number*))
								  {return Expression(a,b);}

								else if (typeid(Value* b) == typeid(Log*))
								  {return Expression(a,b);}

								else if (typeid(Value* b) == typeid(NthRoot*))
								   {return Expression(a,b);}
								break;
	 }
	return 0;
}




