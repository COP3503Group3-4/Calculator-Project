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
#include <NthRoot.h>
#include <SquareRoot.h>
#include <Add.h>
#include <Subtract.h>
#include <sstream>
#include <typeinfo>

Expression::Expression()
{

}


Expression::Expression(Value* v1, Value* v2, string op)
{
	if(op.at(0) == '*') {
		cout << "ERROR! EXPRESSION NO LONGER HANDLES * OR /.";
	}
	if(op.at(0) == '+' || op.at(0) == '-') {
		adds.push_back(v1);
		adds.push_back(v2);
		ops.push_back(op.at(0));
	}
}
Expression::Expression(Value* v1, Value* v2, char op)
{
	if(op == '*') {
		cout << "ERROR! EXPRESSION NO LONGER HANDLES * OR /.";
	}
	if(op == '+' || op == '-') {
		adds.push_back(v1);
		adds.push_back(v2);
		ops.push_back(op);
	}

	//simplify();
}

Expression::~Expression()
{

}

Value* Expression::simplify(){
	minusToPlus();
	simplifyOps();
	zeroCheck();
	if(adds.empty()) {
		return new RationalNumber(0);
	}
	else {
		if(adds.size() > 1) {
			return this;
		}
		else {
			return adds[0];
		}
	}
}

void Expression::zeroCheck() {
	RationalNumber* rN;
	IrrationalNumber* irN;
	Log* l;
	NthRoot* nrt;
	int x = 1;
	for (int i = adds.size() - 1; i >= 0; i--) {
		rN = dynamic_cast<RationalNumber*>(adds[i]);
		irN = dynamic_cast<IrrationalNumber*>(adds[i]);
		l = dynamic_cast<Log*>(adds[i]);
		nrt = dynamic_cast<NthRoot*>(adds[i]);

		if(rN) x = rN->getNumValue();
		if(irN) x = irN->coefficient;
		if(l) x = l->coefficient;
		if(nrt) x = nrt->coefficient;

		if(x == 0) popOffAt(i);
		x = 1;
	}
}

Value* Expression::getNum1() {
	return 0;
}

Value* Expression::getNum2() {
	return 0;
}

void Expression::printInfo(){
	//Printing first value then op, value, op, value until end
	adds[0]->printInfo();
	for (int i = 0; i < ops.size(); i++) {
		cout << " " << ops[i] << " ";
		adds[i+1]->printInfo();
	}
}

string Expression::toString(){
	string s = "";

	s.append(adds[0]->toString());
	ostringstream c;
	for (int i = 0; i < ops.size(); i++) {
		s.append(" ");
		c << ops[i];
		s.append(c.str());
		c.str("");
		c.clear();
		s.append(" ");
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
Value* Expression::get(int i)
{
	return adds[i];
}
int Expression::size()
{

	return adds.size();
}
void Expression::addVal(Value* val)
{
	adds.push_back(val);
	ops.push_back('+');
}
bool Expression::getRational(int& ind) {
	//Going to point v to the Rational and provide the ind
	//May be able to assume this has already been called.
	minusToPlus();
	RationalNumber* rN;
	RationalFraction* rF;

	for(int i = 0; i < adds.size(); i++) {
		rN = dynamic_cast<RationalNumber*>(adds[i]);
		rF = dynamic_cast<RationalFraction*>(adds[i]);
		if(rN) {
			ind = i;
			return true;
		}
		if(rF) {
			ind = i;
			return true;
		}
	}

	return false;
}

bool Expression::getIrrational(int& ind, string irrType)
{
	minusToPlus();
	IrrationalNumber* iN;
	for(int i = 0; i < adds.size(); i++) {
	    iN = dynamic_cast<IrrationalNumber*>(adds[i]);
	    if(iN) {
	    	if (iN->storedVal == irrType) {
	    		ind = i;
	    		return true;
	    	}
	    }
	}
	return false;
}

bool Expression::getLog(int& ind, Value* base, Value* val)
{
    RationalNumber* rN1 = dynamic_cast<RationalNumber*>(base);
    RationalNumber* rN2 = dynamic_cast<RationalNumber*>(val);
    RationalFraction* rF1 = dynamic_cast<RationalFraction*>(base);
    RationalFraction* rF2 = dynamic_cast<RationalFraction*>(val);
    Log* l1 = dynamic_cast<Log*>(base);
    Log* l2 = dynamic_cast<Log*>(val);
    Expression* ex1 = dynamic_cast<Expression*>(base);
    Expression* ex2 = dynamic_cast<Expression*>(val);
    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(base);
    IrrationalNumber* iRN2 = dynamic_cast<IrrationalNumber*>(val);
    //IrrationalFraction* irF1 = dynamic_cast<IrrationalFraction*>(a);
    //IrrationalFraction* irF2 = dynamic_cast<IrrationalFraction*>(b);
    SquareRoot* sqrA = dynamic_cast<SquareRoot*>(base);
    SquareRoot* sqrB = dynamic_cast<SquareRoot*>(val);
    NthRoot* nrtA = dynamic_cast<NthRoot*>(base);
    NthRoot* nrtB = dynamic_cast<NthRoot*>(val);

    Log* exL;

    for(int i = 0; i < adds.size(); i++) {
    	exL = dynamic_cast<Log*>(adds[i]);
    	if(exL) {
            if(rN1 && rN2) {
            	Value* insideBase = exL->getNum1();
            	Value* insideVal = exL->getNum2();
            	if(Add::isEqual(insideBase,rN1)) {
            		if(Add::isEqual(insideVal,rN2)) {
            			ind = i;
            			return true;
            		}
            	}
            }
    	}
    }
    return false;
}

void Expression::popOffAt(int ind)
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
	if(!ops.empty()) {
		//This function is changing all of the ops to +
		for (int i = 0; i < ops.size(); i++) {
			//If the op is negative
			if(ops[i] == '-') {
				ops[i] = '+';

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
				}
				if (iRN1) {
					string s = iRN1->getIRNumValue();
					adds[i+1] = new IrrationalNumber(-1, s);
					delete iRN1;
				}
				//if (iRF1) {

				//}
			}
		}
	}

}
void Expression::makeNegative()
{
	for (int i = 0; i < adds.size(); i++) {

		RationalNumber* rN = dynamic_cast<RationalNumber*>(adds[i]);
	    RationalFraction* f = dynamic_cast<RationalFraction*>(adds[i]);
	    Log* l = dynamic_cast<Log*>(adds[i]);
	    Expression* ex = dynamic_cast<Expression*>(adds[i]);
	    IrrationalNumber* iRN = dynamic_cast<IrrationalNumber*>(adds[i]);
	    NthRoot* nrt = dynamic_cast<NthRoot*>(adds[i]);
	    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(adds[i]);

	    if (rN) {
			adds[i] = new RationalNumber(-1 * rN->getNumValue());
	    }
	    if (f) {
			adds[i] = new RationalFraction(-1 * f->getNumerator(), f->getDenominator());
	    }
	    if (l) {
	    	adds[i] = new Log(l->coefficient * -1, l->getNum1(), l->getNum2());
	    }
	    if (ex) {
	    	ex->minusToPlus();
	    	ex->makeNegative();
	    }
	    if (iRN) {
	    	adds[i] = new IrrationalNumber(iRN->coefficient * -1, iRN->getIRNumValue());
	    }
	    if(nrt) {
	    	adds[i] = new NthRoot(nrt->coefficient * -1, nrt->getNum1(), nrt->getNum2());
	    }
	    //if (iRF1) {

	    //}
	}
}

void Expression::simplifyOps()
{
	for (int i = 0; i < adds.size() - 1; i++) {
		RationalNumber* rN1 = dynamic_cast<RationalNumber*>(adds[i+1]);
	    RationalFraction* f1 = dynamic_cast<RationalFraction*>(adds[i+1]);
	    Log* l1 = dynamic_cast<Log*>(adds[i+1]);
	    Expression* ex1 = dynamic_cast<Expression*>(adds[i+1]);
	    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(adds[i+1]);
	    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(adds[i+1]);

		    if (rN1 && (rN1->getNumValue() < 0)) {
		    	if (ops[i] == '+') ops[i] = '-';
		    	else if (ops[i] == '-') ops[i] = '+';
				int x = (-1 * rN1->getNumValue());
				adds[i+1] = new RationalNumber(x);
		    }
		    if (f1 && (f1->getNumerator() < 0)) {
		    	if (ops[i] == '+') ops[i] = '-';
		    	else if (ops[i] == '-') ops[i] = '+';
				int x = (-1 * f1->getNumerator());
				adds[i+1] = new RationalFraction(x, f1->getDenominator());
				delete f1;
		    }
		    //If log coeff is negative
		    if (l1) {
		    	//Multiply it by -1 and swap the op
		    }
		    if (ex1 && ops[i] == '-') {
		    	ex1->makeNegative();
		    	ex1->simplifyOps();
		    }
		    if (iRN1 && (iRN1->coefficient < 0)) {
		    	if (ops[i] == '+') ops[i] = '-';
		    	else if (ops[i] == '-') ops[i] = '+';
		    	string s = iRN1->getIRNumValue();
		    	adds[i+1] = new IrrationalNumber(-1 * iRN1->coefficient, s);
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
	cout << "Expression->add() no longer supported." << endl;
}
void Expression::subtract(Value* v)
{
	cout << "Expression->subtract() no longer supported." << endl;
}
