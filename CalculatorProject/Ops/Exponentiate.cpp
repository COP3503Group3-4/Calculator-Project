/*
 * Exponentiate.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: guorui
 */

#include <Exponentiate.h>
#include <cmath>
using namespace std;


Exponentiate::Exponentiate() {
}

Exponentiate::~Exponentiate() {
}

Value* Exponentiate::simplifyNumerator(int a, int b, int c){
  //waiting for Damian's function definition for simplifyNumerator for NthRoot
}

Value* Exponentiate::simplifyDenominator(int a, int b, int c){
//waiting for Damian's function definition for simplifyNumerator for NthRoot
    }

//helper method to take the Nthroot of a rational vaule
Value* Exponentiate::takeNthRoot(Value* base, int root)
{ 	 RationalFraction* f = dynamic_cast<RationalFraction*>(insideRoot);
     Log* l = dynamic_cast<Log*>(insideRoot);
     RationalNumber* rN = dynamic_cast<RationalNumber*>(insideRoot);
     Expression* ex = dynamic_cast<Expression*>(insideRoot);
     IrrationalNumber* iRN = dynamic_cast<IrrationalNumber*>(insideRoot);
     //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(insideRoot);
     int rt = root;
     int coefficient =1;

     if(f && rt) {
    	 int numer = f1->getNumerator();
    	     int denom = f1->getDenominator();
    	         if(pow(numer, 1/root) == float(pow(numer, 1/root)) && pow(denom, 1/root) == float(pow(denom, 1/root))){
    	             int nn = pow(numer, 1/root);
    	             int dd = pow(denom, 1/root);
    	             Value* ans = new RationalFraction(nn,dd);
    	             return ans;
    	         }
    	         else if(pow(numer, 1/root) == float(pow(numer, 1/root)) && pow(denom, 1/root) != float(pow(denom, 1/root))){
    	        	 int nn = pow(numer, 1/root);
    	             Value* newNum = new RationalNumber(nn);
    	             int index = root;
    	             Value* newDem = new NthRoot(denom, root);
    	             newDem = simplifyDenominator(denom, index, coefficient);
    	             Value* simpRoot = new IrrationalFraction(newNum, newDem);
    	             return simpRoot;
    	         }
    	         else if(pow(denom, 1/root) == float(pow(denom, 1/root)) && pow(numer, 1/root) != float(pow(numer, 1/root))){
    	             int dd = pow(denom, 1/root);
    	             Value* newDem = new RationalNumber(dd);
    	             int index = root;
    	             Value* newNum = new NthRoot(newNum, root);
    	             newNum = simplifyNumerator(numer, index, coefficient);
    	             Value* simpRoot = new IrrationalFraction(newNum,newDem);
    	             return simpRoot;
    	         }
    	         else{
    	             Value* newNum = new NthRoot();
    	             Value* newDem = new NthRoot();
    	             int index = root;
    	             newNum = simplifyNumerator(numer, index, coefficient);
    	             newDem = simplifyDenominator(denom, index, coefficient);
    	             Value* simpRoot = new IrrationalFraction(newNum,newDem);
    	             return simpRoot;
    	         }
    	     }

     if(rN && rt){
             int inside = rN1->getNumValue();
             if (pow(inside, 1/root) == floor(pow(inside, 1/root))){
                 int simpRoot = pow(inside, 1/root);
                 Value* rootSim = new RationalNumber(simpRoot);
                 return rootSim;
             }
             else{
                 int index = root;
                 Value* newRoot = new NthRoot(simplifyNumerator(inside, index, coefficient));
                 return newRoot;
             }
         }
     }


//helper function to be called later
int Exponentiate::exp (int base, int exp)
{ if(exp >= 1) {return base * (exp (base,exp - 1));}
   else return 1; }

//the function that does the exponentiation
Value* Exponentiate::exponentiate(Value* base, Value* exp)
{

	    ostringstream combined;
	    RationalFraction* f1 = dynamic_cast<RationalFraction*>(a);
	    RationalFraction* f2 = dynamic_cast<RationalFraction*>(b);
	    Log* l1 = dynamic_cast<Log*>(a);
	    Log* l2 = dynamic_cast<Log*>(b);
	    RationalNumber* rN1 = dynamic_cast<RationalNumber*>(a);
	    RationalNumber* rN2 = dynamic_cast<RationalNumber*>(b);
	    Expression* ex1 = dynamic_cast<Expression*>(a);
	    Expression* ex2 = dynamic_cast<Expression*>(b);
	    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(a);
	    IrrationalNumber* iRN2 = dynamic_cast<IrrationalNumber*>(b);
	    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(a);
	    //IrrationalFraction* iRF2 = dynamic_cast<IrrationalFraction*>(b);

	    if(f1 && rN2) {
	        int exp = rN2->getNumValue();

	        if(exp>=0)  //if the exponent is not negative, exponentiate both numerator and denominator and return the fraction
	        {int n1 = f1->getNumerator();
			int d1 = f1->getDenominator();
			int n = exp(n1, exp );
			int d = exp(d1, exp);
	        Value* f3 = new RationalFraction(n,d);
			f3 = f3->simplify();
	        return f3;}

	        else //if the exponent is negative, exponentiate both numerator and denominator and return the fraction with numerator being the new denominator and denominator being the new numerator
	        {int n1 = f1->getNumerator();
			int d1 = f1->getDenominator();
			int n = exp(n1, exp );
			int d = exp(d1, exp);
			Value* f3 = new RationalFraction(d,n);
				f3 = f3->simplify();
				 return f3;
	        }

	    }

	    if(rN1 && rN2){
	            int base = rN1->getNumValue();
	            int exp = rN2->getNumValue();
	            if(exp>=0)
	            {                  //if the exponent is not negative, just take the nth power and return the result
	            int result = exp(base, exp);
	            Value* ans = new RationalNumber(result);
	             return ans;}
	            else               //if the exponent is negative, take the nth power and return 1 over the result
	            {int d = exp(base, exp);
	            Value* f3 = new RationalFraction(1,d);
	            f3 = f3->simplify();
	             return f3;}

	        }

	     if(rN1 && f2) {
	    	 int base0 = rN1->getNumValue();
	    	 int n2 = f2->getNumerator();
	    	 int d2 = f2->getDenominator();
	    	 int base = exp(base0, n2);
	    	 RationalNumber* rN = dynamic_cast<RationalNumber*>(base);
	    	 return takeNthRoot(rN, d2);


	     }

}


