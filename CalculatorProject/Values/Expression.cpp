/*
 * Created by Cory Anderson

 */
#include <Expression.h>
#include <RationalNumber.h>
#include <Fraction.h>
#include <RationalFraction.h>
#include <Log.h>
#include <Expression.h>
#include <Number.h>
#include <RationalNumber.h>
#include <Add.h>
#include <Subtract.h>
#include <sstream>
#include <typeinfo>

/*
 Didn't have enough time to fully implement this class. I was unable to get adding rational
 and irrational numbers to work. getRational isn't working for some reason. And I don't have enough time
 to figure out why.

 The general idea I had for Expression was to have mults and adds. mults will hold the values that are
 multiplied together like pi * e * 4 and adds will hold the values that are added.

 I created a shit of helper methods because I restarted this class 5 times trying to figure out how to
 implement it before I finally got fed up with inability of my group to handle the operations of expression
 in the operations classes so I just integrated the operations into the class.
 */

Expression::Expression()
{
}


Expression::Expression(Value* v1, Value* v2, string op)
{
	if(op == "*") {
		mults.push_back(v1);
		mults.push_back(v2);
	}
	if(op == "+" || op == "-") {
		adds.push_back(v1);
		adds.push_back(v2);
		ops.push_back(op);
	}
}
Expression::Expression(Value* v1, Value* v2, char op)
{
	if(op == '*') {
		mults.push_back(v1);
		mults.push_back(v2);
	}
	if(op == '+' || op == '-') {
		adds.push_back(v1);
		adds.push_back(v2);
		stringstream ss;
		string s;
		ss << op;
		ss >> s;
		ops.push_back(s);
	}

	//simplify();
}

Expression::~Expression()
{

}

Value* Expression::simplify(){
	/*
	 Definitely didn't get to the simplify function. I was planning on using simplifyOps to accompany
	minusToPlus() to avoid having to deal with operators.
	 */
	Value* v;
	simplifyOps();
	return this;
}
Value* Expression::getNum1() {
	return 0;
}

Value* Expression::getNum2() {
	return 0;
}
//I thought this was going to be easy to make.
//It's pretty hard having to deal with the fact that their is one less op than there are Values in add
//and also 2 different vectors
void Expression::printInfo(){
	//Printing first value then op, value, op, value until end
	if (mults.size() > 0) mults[0]->printInfo();
	for (int i = 1; i < mults.size(); i++) {
		cout << "*";
		mults[i]->printInfo();
	}
	if(adds.size() > 0 && mults.size() > 0) {
		cout << " " << "+" << " ";
		adds[0]->printInfo();
	}
	else if (adds.size() > 0 && !mults.size() > 0){
		adds[0]->printInfo();
	}
	for (int i = 0; i < ops.size(); i++) {
		cout << " " << ops[i] << " ";
		adds[i+1]->printInfo();
	}
}

string Expression::toString(){
	string s = "";
	if (mults.size() > 0) s.append(mults[0]->toString());
	for (int i = 1; i < mults.size(); i++) {
		s.append("*");
		s.append(mults[i]->toString());
	}
	if(adds.size() > 0 && mults.size() > 0) {
		s.append(" + ");
		s.append(adds[0]->toString());
	}
	else if (adds.size() > 0 && !mults.size() > 0){
		s.append(adds[0]->toString());
	}
	for (int i = 0; i < ops.size(); i++) {
		s.append(" + ");
		s.append(adds[i+1]->toString());
	}
	return s;
}

bool Expression::getValue(string typeName, Value* v, int* ind)
{
	//Iterate through the adds contained in the expression
	for (int i = 0; i < adds.size(); i++) {
		//If the type id name provided matches the id of a value within the expression
		if(typeid(adds[i]).name() == typeName) {
			//Give the value to v
			v = adds[i];
			ind = new int(i);
			//Return true
			return true;
		}
	}
	//Method returns false if Value with provided typeID isn't found in the expression
	return false;
}
//some simple get methods
Value* Expression::getA(int i)
{
	return adds[i];
}
Value* Expression::getM(int i)
{
	return mults[i]
;}
int Expression::sizeA()
{
	return adds.size();
}
int Expression::sizeM()
{
	return mults.size();
}
int Expression::size()
{
	if (mults.size() > 0) {
		return 1 + adds.size();
	}
	else {
		return adds.size();
	}
}
//This function wasn't working with add. I thought it was a pretty cool function :(
bool Expression::getRational(Value* v, int* ind) {
	//Check first
	RationalNumber* rN;
	RationalFraction* f;
	for(int i = 0; i < adds.size() - 1; i++) {
			rN = dynamic_cast<RationalNumber*>(adds[i]);
		    f = dynamic_cast<RationalFraction*>(adds[i]);
		    if (rN) {
		    	ind = new int(i);
		    	v = adds[i];
		    	return true;
		    }
		    if (f) {
		    	ind = new int(i);
		    	v = adds[i];
		    	return true;
		    }
	}

	return false;
}
//Mirrored getRational
bool Expression::getIrrational(IrrationalNumber* iN1, int* ind, string type)
{
	for(int i = 0; i < adds.size(); i++) {
	    IrrationalNumber* iN = dynamic_cast<IrrationalNumber*>(adds[i]);
	    if(iN) {
	    	if (iN->storedVal == type) {
	    		ind = new int(i);
	    		iN1 = iN;
	    		return true;
	    	}
	    }
	}
	return false;
}

void Expression::popOff(int ind, Value* vPtr)
{
	Value* v = adds[ind];
	for(int i = ind; i < adds.size()-1; i++) {
		//overwrite this guy with next guy
		//this guy will have already overwritten the guy before it
		//except for the poor guy that got popped
		adds[i] = adds[i+1];
	}
	adds.pop_back();
	for(int i = ind+1; i < ops.size() - 1; i++) {
		ops[i] = ops[i+1];
	}
	ops.pop_back();
	vPtr = v;
}
void Expression::popOff(int ind)
{
	for(int i = ind; i < adds.size()-1; i++) {
		//overwrite this guy with next guy
		//this guy will have already overwritten the guy before it
		//except for the poor guy that got popped
		adds[i] = adds[i+1];
	}
	adds.pop_back();
	for(int i = ind+1; i < ops.size() - 1; i++) {
		ops[i] = ops[i+1];
	}
	ops.pop_back();
}

void Expression::minusToPlus()
{
	//This function is changing all of the ops to +
	for (int i = 0; i < ops.size(); i++) {
		//If the op is negative
		if(ops[i] == "-") {
			ops[i] = "+";

			RationalNumber* rN1 = dynamic_cast<RationalNumber*>(adds[i+1]);
		    RationalFraction* f1 = dynamic_cast<RationalFraction*>(adds[i+1]);
		    Log* l1 = dynamic_cast<Log*>(adds[i+1]);
		    Expression* ex1 = dynamic_cast<Expression*>(adds[i+1]);
		    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(adds[i+1]);
		    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(adds[i+1]);

		    if (rN1) {
				int x = (-1 * rN1->getNumValue());
				adds[i+1] = new RationalNumber(x);
				delete rN1;
		    }
		    if (f1) {
				int x = (-1 * f1->getNumerator());
				adds[i+1] = new RationalFraction(x, f1->getDenominator());
				delete f1;
		    }
		    if (l1) {
		    	//Cannot implement until log is implemented
		    }
		    if (ex1) {
		    	ex1->minusToPlus();
		    	ex1->makeNegative();
		    	ex1 = 0;
		    }
		    if (iRN1) {
		    	string s = iRN1->getIRNumValue();
		    	//adds[i+1] = new IrrationalNumber(-1, s);
		    	delete iRN1;
		    }
		    //if (iRF1) {

		    //}
		}
	}
}
void Expression::makeNegative()
{
	for (int i = 0; i < adds.size(); i++) {

		RationalNumber* rN1 = dynamic_cast<RationalNumber*>(adds[i+1]);
	    RationalFraction* f1 = dynamic_cast<RationalFraction*>(adds[i+1]);
	    Log* l1 = dynamic_cast<Log*>(adds[i+1]);
	    Expression* ex1 = dynamic_cast<Expression*>(adds[i+1]);
	    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(adds[i+1]);
	    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(adds[i+1]);

	    if (rN1) {
			int x = (-1 * rN1->getNumValue());
			adds[i+1] = new RationalNumber(x);
			delete rN1;
	    }
	    if (f1) {
			int x = (-1 * f1->getNumerator());
			adds[i+1] = new RationalFraction(x, f1->getDenominator());
			delete f1;
	    }
	    if (l1) {
	    	//Cannot implement until log is implemented
	    }
	    if (ex1) {
	    	ex1->minusToPlus();
	    	ex1->makeNegative();
	    	ex1 = 0;
	    }
	    if (iRN1) {
	    	string s = iRN1->getIRNumValue();
	    	//adds[i+1] = new IrrationalNumber(-1, s);
	    	delete iRN1;
	    }
	    //if (iRF1) {

	    //}
	}
}

void Expression::simplifyOps()
{
	for (int i = 0; i < ops.size(); i++) {
		RationalNumber* rN1 = dynamic_cast<RationalNumber*>(adds[i+1]);
	    RationalFraction* f1 = dynamic_cast<RationalFraction*>(adds[i+1]);
	    Log* l1 = dynamic_cast<Log*>(adds[i+1]);
	    Expression* ex1 = dynamic_cast<Expression*>(adds[i+1]);
	    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(adds[i+1]);
	    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(adds[i+1]);

		    if (rN1 && (rN1->getNumValue() < 0)) {
		    	if (ops[i] == "+") ops[i] = "-";
		    	if (ops[i] == "-") ops[i] = "+";
				int x = (-1 * rN1->getNumValue());
				adds[i+1] = new RationalNumber(x);
				delete rN1;
		    }
		    if (f1 && (f1->getNumerator() < 0)) {
		    	if (ops[i] == "+") ops[i] = "-";
		    	if (ops[i] == "-") ops[i] = "+";
				int x = (-1 * f1->getNumerator());
				adds[i+1] = new RationalFraction(x, f1->getDenominator());
				delete f1;
		    }
		    //If log coeff is negative
		    if (l1) {
		    	//Multiply it by -1 and swap the op
		    }
		    if (ex1 && ops[i] == "-") {
		    	ex1->makeNegative();
		    	ex1->simplifyOps();

		    	ex1 = 0;
		    }
		    if (iRN1) {
		    	string s = iRN1->getIRNumValue();
		    	//adds[i+1] = new IrrationalNumber(-1, s);
		    	delete iRN1;
		    }
		    //if (iRF1) {

		    //}
	}
}
bool Expression::hasValue(string typeName)
{
	for(int i = 0; i < adds.size(); i++) {
		if (typeid(adds[i]).name() == typeName) return true;
	}
	return false;
}
void Expression::add(Value* v)
{
	minusToPlus();
	if (hasValue(typeid(v).name())) {
		RationalNumber* rN1 = dynamic_cast<RationalNumber*>(v);
		RationalFraction* f1 = dynamic_cast<RationalFraction*>(v);
		Log* l1 = dynamic_cast<Log*>(v);
		Expression* ex1 = dynamic_cast<Expression*>(v);
		IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(v);
		//IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(v);

		Value* v2;
		int* ind;

		if(rN1) {
			if(getRational(v2, ind)) {
				RationalNumber* rN2 = dynamic_cast<RationalNumber*>(v2);
				RationalFraction* f2 = dynamic_cast<RationalFraction*>(v2);
				if (rN2) adds[*ind] = Add::add(rN1,rN2);
				if (f2) adds[*ind] = Add::add(rN1,f2);

			}
		}
		if (f1) {
			if(getRational(v2, ind)) {
				RationalNumber* rN2 = dynamic_cast<RationalNumber*>(v2);
				RationalFraction* f2 = dynamic_cast<RationalFraction*>(v2);
				if (rN2) adds[*ind] = Add::add(f1,rN2); delete rN2;
				if (f2) adds[*ind] = Add::add(f1,f2); delete f2;
				delete f1;
			}
		}
		if(iRN1) {
			IrrationalNumber* iRN2;
			if(getIrrational(iRN2, ind, iRN2->getIRNumValue())) {
				adds[*ind] = Add::add(iRN1,iRN2);
			}
			else {
				adds.push_back(v);
				ops.push_back("+");
			}
			delete iRN1;
		}
		if(ex1) {
			ex1->minusToPlus();
			for(int i = 0; i < ex1->sizeA(); i++) {
				v2 = ex1->getA(i);
				add(v2);
			}

		}
	}
	else {
		adds.push_back(v);
		ops.push_back("+");
	}
}
void Expression::subtract(Value* v)
{
	minusToPlus();
	if (hasValue(typeid(v).name())) {
		RationalNumber* rN1 = dynamic_cast<RationalNumber*>(v);
		RationalFraction* f1 = dynamic_cast<RationalFraction*>(v);
		Log* l1 = dynamic_cast<Log*>(v);
		Expression* ex1 = dynamic_cast<Expression*>(v);
		IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(v);
		//IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(v);

		Value* v2;
		int* ind;

		if(rN1) {
			if(getRational(v2, ind)) {
				RationalNumber* rN2 = dynamic_cast<RationalNumber*>(v2);
				RationalFraction* f2 = dynamic_cast<RationalFraction*>(v2);
				if (rN2) adds[*ind] = Subtract::subtract(rN1,rN2); delete rN2;
				if (f2) adds[*ind] = Subtract::subtract(rN1,f2); delete f2;
				delete rN1;
			}
		}
		if (f1) {
			if(getRational(v2, ind)) {
				RationalNumber* rN2 = dynamic_cast<RationalNumber*>(v2);
				RationalFraction* f2 = dynamic_cast<RationalFraction*>(v2);
				if (rN2) adds[*ind] = Subtract::subtract(f1,rN2); delete rN2;
				if (f2) adds[*ind] = Subtract::subtract(f1,f2); delete f2;
				delete f1;
			}
		}
		if(iRN1) {
			IrrationalNumber* iRN2;
			if(getIrrational(iRN2, ind, iRN2->getIRNumValue())) {
				adds[*ind] = Subtract::subtract(iRN1,iRN2);
			}
			else {
				adds.push_back(v);
				ops.push_back("-");
			}
			delete iRN1;
		}
	}
	else {
		adds.push_back(v);
		ops.push_back("-");
	}
}
void Expression::multiply(Value* v)
{

}
void Expression::divide(Value* v)
{

}
