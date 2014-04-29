/*
 * divide.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: guorui
 */

#include <Divide.h>
#include <Fraction.h>
#include <RationalFraction.h>
#include <IrrationalFraction.h>
#include <Log.h>
#include <Expression.h>
#include <Number.h>
#include <RationalNumber.h>
#include <IrrationalNumber.h>
#include <NthRoot.h>
#include <sstream>
#include <typeinfo>

Divide::Divide() {}
Divide::~Divide() {}

Value* Divide::divide(Value* a, Value* b){
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
    IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(a);
    IrrationalFraction* iRF2 = dynamic_cast<IrrationalFraction*>(b);
    NthRoot* nR1 = dynamic_cast<NthRoot*>(a);
    NthRoot* nR2 = dynamic_cast<NthRoot*>(b);
	
	
    if(rN2){
    	if(rN2->getNumValue() == 0){
    		cout << "Dividing by zero is not allowed!" << endl;
    		RationalNumber* zero = new RationalNumber(0);
    		return zero;
    	}
    }	
    if(f1 && f2){
        int n1 = f1->getNumerator();
		int n2 = f2->getNumerator();
        int d1 = f1->getDenominator();
		int d2 = f2->getDenominator();
		int n = n1 * d2;
		int d = d1 * n2;
        Value* f3 = new RationalFraction(n,d);
		f3 = f3->simplify();
        return f3;
    }
    
    else if(rN1 && rN2){
        int nn = rN1->getNumValue();
        int dd = rN2->getNumValue();
        Value* quotient = new RationalFraction(nn,dd);
        quotient = quotient->simplify();
        //quotient->printInfo();
        return quotient;
    }


    else if( f1 && rN2 ){
		int n1 = f1->getNumerator();
		int d1 = f1->getDenominator();
		int d2 = rN2->getNumValue();
		int d = d1 *d2;
		Value* f3 = new RationalFraction(n1,d);
		f3 = f3->simplify();
		return f3;
	}
    else if( f2 && rN1 ){
		int n1 = f2->getNumerator();
		int d1 = f2->getDenominator();
		int d2 = rN1->getNumValue();
		int d = d1 *d2;
		Value* f3 = new RationalFraction(n1,d);
		f3 = f3->simplify();
		return f3;
	}

    else if(iRN1 && iRN2){
        if(iRN1->getIRNumValue() == iRN2->getIRNumValue()) {
        	Value* coeff = new RationalFraction(iRN1->coefficient, iRN2->coefficient);
        	RationalNumber* rCoeff = dynamic_cast<RationalNumber*>(coeff);
        	if(rCoeff) {
        		return new IrrationalNumber(rCoeff->getNumValue(), iRN1->getIRNumValue());
        	}
        	else {
        		cout << "Non integer coefficients with IrrationalNumbers are unsupported." << endl;
        		return iRN1;
        	}
        }
   }
    else {
    	cout << "This operation is currently unsupported: " << a->toString() << " / " << b->toString() << endl;
    	return a;
    }
}

bool Divide::isEqual(Value* a, Value* b){
    RationalNumber* rnTestA = dynamic_cast<RationalNumber*>(a);
    RationalNumber* rnTestB = dynamic_cast<RationalNumber*>(b);
    RationalFraction* rfTestA = dynamic_cast<RationalFraction*>(a);
    RationalFraction* rfTestB = dynamic_cast<RationalFraction*>(b);
    Log* logTestA = dynamic_cast<Log*>(a);
    Log* logTestB = dynamic_cast<Log*>(b);
    Expression* exTestA = dynamic_cast<Expression*>(a);
    Expression* exTestB = dynamic_cast<Expression*>(b);
    IrrationalNumber* inTestA = dynamic_cast<IrrationalNumber*>(a);
    IrrationalNumber* inTestB = dynamic_cast<IrrationalNumber*>(b);
    //IrrationalFraction* irfTestA = dynamic_cast<IrrationalFraction*>(a);
    //IrrationalFraction* irfTestB = dynamic_cast<IrrationalFraction*>(b);
    if(rnTestA && rnTestB){
        Value* num1 = new RationalNumber();
        Value* num2 = new RationalNumber();
        num1 = a;
        num2 = b;
        if(num1->getNum1() == num2->getNum1()){
            return true;
        }
    }
    else if(rfTestA && rfTestB){
    	Value* num1 = new RationalFraction();
    	Value* num2 = new RationalFraction();
    	num1 = a;
    	num2 = b;
    	if(num1->getNum1() == num2->getNum1() && num2->getNum2() == num1->getNum2()){
    		return true;
    		}
    	}
    else if(logTestA && logTestB){
    	Value* num1 = new Log();
    	Value* num2 = new Log();
    	num1 = a;
    	num2 = b;
    	if(num1->getNum1() == num2->getNum1() && num2->getNum2() == num1->getNum2()){
    	    return true;
    	    }
    	}
    else if(exTestA && exTestB) {
    	Value* num1 = new Expression();
    	Value* num2 = new Expression();
    	num1 = a;
    	num2 = b;
    	if(num1->getNum1() == num2->getNum1() && num2->getNum2() == num1->getNum2()){
    	    return true;
    	    }
    	}
    else if(inTestA && inTestB) {
    	Value* num1 = new IrrationalNumber();
    	Value* num2 = new IrrationalNumber();
    	num1 = a;
    	num2 = b;
    	if(num1->getNum1() == num2->getNum1()){
    		return true;
    	    }
    	}
   /* else if(irfTestA && irfTestB) {
    	Value* num1 = new RationalFraction();
    	Value* num2 = new RationalFraction();
    	num1 = a;
    	num2 = b;
    	if(num1->getNum1() == num2->getNum1() && num2->getNum2() == num1->getNum2()){
    		return true;
    	    }
    	}*/
    else{ return false; }

}

