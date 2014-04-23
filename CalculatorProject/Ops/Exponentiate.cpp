/*
 * Exponentiate.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: guorui
 */

#include <Exponentiate.h>
#include <Fraction.h>
#include <RationalFraction.h>
#include <Log.h>
#include <Expression.h>
#include <Number.h>
#include <RationalNumber.h>
#include <IrrationalNumber.h>
#include <IrrationalFraction.h>
#include <NthRoot.h>
#include <Divide.h>
#include <sstream>
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
/*
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
    	 int numer = f->getNumerator();
    	     int denom = f->getDenominator();
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

*/

int Exponentiate::expo(int base, int exp)
{
	if(exp >= 1) {
		return base * (expo (base,exp - 1));
	}
	else if (exp == 0) {
		return 1;
	}
   else if (exp <0) {
	   return expo(base, std::abs(exp));
   }
}





//the function that does the exponentiation
Value* Exponentiate::exponentiate(Value* base, Value* exp)
{

	    ostringstream combined;
	    RationalFraction* f1 = dynamic_cast<RationalFraction*>(base);
	    RationalFraction* f2 = dynamic_cast<RationalFraction*>(exp);
	    Log* l1 = dynamic_cast<Log*>(base);
	    Log* l2 = dynamic_cast<Log*>(exp);
	    RationalNumber* rN1 = dynamic_cast<RationalNumber*>(base);
	    RationalNumber* rN2 = dynamic_cast<RationalNumber*>(exp);
	    Expression* ex1 = dynamic_cast<Expression*>(base);
	    Expression* ex2 = dynamic_cast<Expression*>(exp);
	    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(base);
	    IrrationalNumber* iRN2 = dynamic_cast<IrrationalNumber*>(exp);
	    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(base);
	    //IrrationalFraction* iRF2 = dynamic_cast<IrrationalFraction*>(exp);

	    if(f1 && rN2) {
	        int exp = rN2->getNumValue();

	        if(exp>=0)  //if the exponent is not negative, exponentiate both numerator and denominator and return the fraction
	        {
	        	int n1 = f1->getNumerator();
	        	int d1 = f1->getDenominator();
	        	int n = expo(n1, exp );
	        	int d = expo(d1, exp);
	        	Value* f3 = new RationalFraction(n,d);
	        	f3 = f3->simplify();
	        	return f3;
	        }

	        else //if the exponent is negative, exponentiate both numerator and denominator and return the fraction with numerator being the new denominator and denominator being the new numerator
	        {int n1 = f1->getNumerator();
			int d1 = f1->getDenominator();
			int n = expo(n1, exp );
			int d = expo(d1, exp);
			Value* f3 = new RationalFraction(d,n);
				f3 = f3->simplify();
				 return f3;
	        }

	    }

	    if(rN1 && rN2){
			int base = rN1->getNumValue();
			int exp = rN2->getNumValue();
			if(exp>=0) {                  //if the exponent is not negative, just take the nth power and return the result
			int result = expo(base, exp);
			Value* ans = new RationalNumber(result);
			 return ans;
			}
			else {             //if the exponent is negative, take the nth power and return 1 over the result
			int d = expo(base, exp);
			Value* f3 = new RationalFraction(1,d);
			f3 = f3->simplify();
			 return f3;
	            }

	        }

	     if(rN1 && f2) {
	    	 int pow = f2->getNumerator();
	    	 RationalNumber* rN3 = new RationalNumber(expo(rN1->getNumValue(), pow));
	    	 RationalNumber* rN4 = new RationalNumber(f2->getDenominator());
			 if (f2->getNumerator() < 0) {
				 RationalNumber* one = new RationalNumber(1);
				 NthRoot* NR = new NthRoot(rN3, rN4);
				 Value* v = Divide::divide(one, NR->simplify());
				 return v;
			 }
			 else {
				 NthRoot* NR = new NthRoot(rN3,rN4);
				 return NR->simplify();
			 }

	     }

	   if(f1 && f2) {
	    	 int n = f1->getNumerator();
	    	 int d = f1->getDenominator();
	    	 RationalNumber* nn = new RationalNumber(n);
	    	 RationalNumber* dd = new RationalNumber(d);
	    	 if(f2->getNumerator() > 0) {
		    	 Value* nnn = exponentiate(nn, f2);
		    	 Value* ddd = exponentiate(dd, f2);
		    	 Value* result = Divide::divide(nnn, ddd);
		    	 //Simplify is crashing the program for some reason (IrrationalFraction)
		    	 //result = result ->simplify();
		    	 return result;
	    	 }
	    	 else {
	    		 RationalFraction* rF3 = new RationalFraction(f2->getNumerator() * -1, f2->getDenominator());
		    	 Value* nnn = exponentiate(nn, rF3);
		    	 Value* ddd = exponentiate(dd, rF3);
		    	 Value* result = Divide::divide(ddd, nnn);
		    	 //Simplify is crashing the program for some reason (IrrationalFraction::simplify())
		    	 //result = result ->simplify();
		    	 return result;
	    	 }

	     }
	   if(iRN1 && rN2) {
		   cout << "Exponentiating irrational numbers is unsupported." << endl;
		   return iRN1;
	   }
	   if(rN1 && iRN2) {
		   cout << "Raising rational numbers to irrational powers is unsupported." << endl;
		   return rN1;
	   }

}


