/*
 * Expression2.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: corya_000
 */

#include <Expression2.h>

#include <RationalNumber.h>
#include <Fraction.h>
#include <RationalFraction.h>
#include <Log.h>
#include <Expression.h>
#include <Number.h>
#include <RationalNumber.h>
#include <Add.h>
#include <sstream>
#include <typeinfo>
#include <IrrationalNumber.h>

Expression2::Expression2(vector<Value*> sumVals, vector<Value*> prodVals, vector<string> ops)
{
	sums = sumVals;
	sumOps = ops;
}
Expression2::Expression2(Value* v1, Value* v2, string op)
{
	if(op == "+" || op == "-") {
		sums.push_back(v1);
		sumOps.push_back(op);
		sums.push_back(v2);
	}
	if(op == "*") {
		prods.push_back(v1);
		prods.push_back(v2);
	}
}
Expression2::Expression2(Value* v1, Value* v2, char op)
{
	stringstream ss;
	string s;
	ss << op;
	ss >> s;
	if(op == '+' || op == '-') {
		sums.push_back(v1);
		sumOps.push_back(s);
		sums.push_back(v2);
	}
	if(op == '*') {
		prods.push_back(v1);
		prods.push_back(v2);
	}
}

Expression2::~Expression2() {
	// TODO Auto-generated destructor stub
}

void Expression2::minusToPlus()
{
	//This function is changing all of the sumOps to +
	for (int i = 0; i < sumOps.size(); i++) {
		//If the op is negative
		if(sumOps[i] == "-") {
			sumOps[i] = "+";

			RationalNumber* rN1 = dynamic_cast<RationalNumber*>(sums[i+1]);
		    RationalFraction* f1 = dynamic_cast<RationalFraction*>(sums[i+1]);
		    Log* l1 = dynamic_cast<Log*>(sums[i+1]);
		    Expression* ex1 = dynamic_cast<Expression*>(sums[i+1]);
		    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(sums[i+1]);
		    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(sums[i+1]);

		    if (rN1) {
				int x = (-1 * rN1->getNumValue());
				sums[i+1] = new RationalNumber(x);
				delete rN1;
		    }
		    if (f1) {
				int x = (-1 * f1->getNumerator());
				sums[i+1] = new RationalFraction(x, f1->getDenominator());
				delete f1;
		    }
		    if (l1) {
		    	//Cannot implement until log constant is implemented
		    }
		    if (ex1) {
		    	ex1->minusToPlus();
		    	ex1->makeNegative();
		    	ex1 = 0;
		    }
		    if (iRN1) {
		    	string s = iRN1->getIRNumValue();
		    	//sums[i+1] = new IrrationalNumber(-1, s);
		    	delete iRN1;
		    }
		    //if (iRF1) {

		    //}
		}
	}
}

void Expression2::simplifyOps()
{
	for (int i = 0; i < sumOps.size(); i++) {
		RationalNumber* rN1 = dynamic_cast<RationalNumber*>(sums[i+1]);
	    RationalFraction* f1 = dynamic_cast<RationalFraction*>(sums[i+1]);
	    Log* l1 = dynamic_cast<Log*>(sums[i+1]);
	    Expression* ex1 = dynamic_cast<Expression*>(sums[i+1]);
	    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(sums[i+1]);
	    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(sums[i+1]);

		    if (rN1 && (rN1->getNumValue() < 0)) {
		    	if (sumOps[i] == "+") sumOps[i] = "-";
		    	if (sumOps[i] == "-") sumOps[i] = "+";
				int x = (-1 * rN1->getNumValue());
				sums[i+1] = new RationalNumber(x);
				delete rN1;
		    }
		    if (f1 && (f1->getNumerator() < 0)) {
		    	if (sumOps[i] == "+") sumOps[i] = "-";
		    	if (sumOps[i] == "-") sumOps[i] = "+";
				int x = (-1 * f1->getNumerator());
				sums[i+1] = new RationalFraction(x, f1->getDenominator());
				delete f1;
		    }
		    if (l1) {
		    	//Cannot implement until log constant is implemented
		    }
		    if (ex1) {
		    	ex1->makeNegative();
		    	ex1->simplifyOps();
		    	ex1 = 0;
		    }
		    if (iRN1) {
		    	string s = iRN1->getIRNumValue();
		    	//sums[i+1] = new IrrationalNumber(-1, s);
		    	delete iRN1;
		    }
		    //if (iRF1) {

		    //}
	}
}
