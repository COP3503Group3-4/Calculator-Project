
#include <Expression.h>
#include <RationalNumber.h>
#include <Fraction.h>
#include <RationalFraction.h>
#include <Log.h>
#include <Expression.h>
#include <Number.h>
#include <RationalNumber.h>
#include <IrrationalNumber.h>

Expression::Expression()
{
}

Expression::Expression(vector<Value*> vals, vector<string> ops)
{
	this->ops = ops;
	values = vals;
}
Expression::Expression(Value* v1, Value* v2, string op)
{
	values.push_back(v1);
	values.push_back(v2);
	ops.push_back(op);
}
Expression::Expression(Value* v1, Value* v2, char op)
{
	values.push_back(v1);
	values.push_back(v2);
	stringstream ss;
	string s;
	ss << op;
	ss >> s;
	ops.push_back(s);
}

Expression::~Expression()
{

}

Value* Expression::simplify(){

}

Value* Expression::getNum1() {
	return 0;
}

Value* Expression::getNum2() {
	return 0;
}

void Expression::printInfo(){
	//Printing first value then op, value, op, value until end
	values[0]->printInfo();
	for (int i = 0; i < ops.size(); i++) {
		cout << " " << ops[i] << " ";
		values[i+1]->printInfo();
	}
}

string Expression::toString(){
	string s = values[0]->toString();
	for (int i = 0; i < ops.size(); i++) {
		s.append(ops[i]);
		s.append(values[i+1]->toString());
	}
	return s;
}

bool Expression::getValue(string typeName, Value* v, int* ind)
//Have to make sure that negative rational numbers are still added
{
	//Iterate through the values contained in the expression
	for (int i = 0; i < values.size(); i++) {
		//If the type id name provided matches the id of a value within the expression
		if(typeid(values[i]).name() == typeName) {
			//Give the value to v
			v = values[i];
			ind = new int(i);
			//Return true
			return true;
		}
	}
	//Method returns false if Value with provided typeID isn't found in the expression
	return false;
}
void Expression::popOff(int ind, Value* vPtr)
{
	Value* v = values[ind];
	for(int i = ind; i < values.size()-1; i++) {
		//overwrite this guy with next guy
		//this guy will have already overwritten the guy before it
		//except for the poor guy that got popped
		values[i] = values[i+1];
	}
	values.pop_back();
	for(int i = ind+1; i < ops.size() - 1; i++) {
		ops[i] = ops[i+1];
	}
	ops.pop_back();
	vPtr = v;
}
void Expression::popOff(int ind)
{
	for(int i = ind; i < values.size()-1; i++) {
		//overwrite this guy with next guy
		//this guy will have already overwritten the guy before it
		//except for the poor guy that got popped
		values[i] = values[i+1];
	}
	values.pop_back();
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

			RationalNumber* rN1 = dynamic_cast<RationalNumber*>(values[i+1]);
		    RationalFraction* f1 = dynamic_cast<RationalFraction*>(values[i+1]);
		    Log* l1 = dynamic_cast<Log*>(values[i+1]);
		    Expression* ex1 = dynamic_cast<Expression*>(values[i+1]);
		    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(values[i+1]);
		    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(values[i+1]);

		    if (rN1) {
				int x = (-1 * rN1->getNumValue());
				values[i+1] = new RationalNumber(x);
				delete rN1;
		    }
		    if (f1) {
				int x = (-1 * f1->getNumerator());
				values[i+1] = new RationalFraction(x, f1->getDenominator());
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
		    	//values[i+1] = new IrrationalNumber(-1, s);
		    	delete iRN1;
		    }
		    //if (iRF1) {

		    //}
		}
	}
}
void Expression::makeNegative()
{
	for (int i = 0; i < values.size(); i++) {

		RationalNumber* rN1 = dynamic_cast<RationalNumber*>(values[i+1]);
	    RationalFraction* f1 = dynamic_cast<RationalFraction*>(values[i+1]);
	    Log* l1 = dynamic_cast<Log*>(values[i+1]);
	    Expression* ex1 = dynamic_cast<Expression*>(values[i+1]);
	    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(values[i+1]);
	    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(values[i+1]);

	    if (rN1) {
			int x = (-1 * rN1->getNumValue());
			values[i+1] = new RationalNumber(x);
			delete rN1;
	    }
	    if (f1) {
			int x = (-1 * f1->getNumerator());
			values[i+1] = new RationalFraction(x, f1->getDenominator());
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
	    	//values[i+1] = new IrrationalNumber(-1, s);
	    	delete iRN1;
	    }
	    //if (iRF1) {

	    //}
	}
}

Value* Expression::add(Value* v)
{
	Value* result;
	RationalNumber* rN1 = dynamic_cast<RationalNumber*>(v);
    RationalFraction* f1 = dynamic_cast<RationalFraction*>(v);
    Log* l1 = dynamic_cast<Log*>(v);
    Expression* ex1 = dynamic_cast<Expression*>(v);
    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(v);
    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(v);
    minusToPlus();

    if (rN1) {
    	RationalNumber* rN2;
    	int* ind = new int(-1);
    	if (getValue(typeid(RationalNumber*).name(), rN2, ind)) {
    		if(!(rN2->getNumValue() + rN1->getNumValue()) == 0) {
    			int x = rN2->getNumValue() + rN1->getNumValue();
    			delete rN2;
    			delete rN1;
    			values[*ind] = new RationalNumber(x);
    		}
    		else {
    			popOff(*ind);
    		}
    	}
    	simplifyOps();
    	delete rN1;
    	delete rN2;
    }
    if (f1) {

    }
}

void Expression::simplifyOps()
{
	for (int i = 0; i < ops.size(); i++) {
		RationalNumber* rN1 = dynamic_cast<RationalNumber*>(values[i+1]);
	    RationalFraction* f1 = dynamic_cast<RationalFraction*>(values[i+1]);
	    Log* l1 = dynamic_cast<Log*>(values[i+1]);
	    Expression* ex1 = dynamic_cast<Expression*>(values[i+1]);
	    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(values[i+1]);
	    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(values[i+1]);

		    if (rN1 && (rN1->getNumValue() < 0)) {
		    	if (ops[i] == "+") ops[i] = "-";
		    	if (ops[i] == "-") ops[i] = "+";
				int x = (-1 * rN1->getNumValue());
				values[i+1] = new RationalNumber(x);
				delete rN1;
		    }
		    if (f1 && (f1->getNumerator() < 0)) {
		    	if (ops[i] == "+") ops[i] = "-";
		    	if (ops[i] == "-") ops[i] = "+";
				int x = (-1 * f1->getNumerator());
				values[i+1] = new RationalFraction(x, f1->getDenominator());
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
		    	//values[i+1] = new IrrationalNumber(-1, s);
		    	delete iRN1;
		    }
		    //if (iRF1) {

		    //}
	}
}
