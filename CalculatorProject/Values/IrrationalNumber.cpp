#include <IrrationalNumber.h>
#include <RationalNumber.h>
#include <sstream>

IrrationalNumber::IrrationalNumber()
{
    //ctor
	coefficient = 0;
	expo = new RationalNumber(1);
}
IrrationalNumber::IrrationalNumber(string s){
	coefficient = 1;
    storedVal = s;
	expo = new RationalNumber(1);
}

IrrationalNumber::IrrationalNumber(int coeff, string s){
    coefficient = coeff;
    storedVal = s;
	expo = new RationalNumber(1);
}
IrrationalNumber::IrrationalNumber(int coeff, string s, Value* pow) {
    coefficient = coeff;
    storedVal = s;
	expo = pow;
}
IrrationalNumber::~IrrationalNumber()
{

}

Value* IrrationalNumber::getNum1(){
    Value* IR = new RationalNumber(coefficient);
    return IR;
}

Value* IrrationalNumber::getNum2(){
    return expo;
}

Value* IrrationalNumber::simplify(){
	if(coefficient == 0) {
		return new RationalNumber(0);
	}
	RationalNumber* rN = dynamic_cast<RationalNumber*>(expo);
	if (rN) {
		if(rN->getNumValue() == 0) {
			return new RationalNumber(1);
		}
	}
	return this;
}

string IrrationalNumber::getIRNumValue(){
    return storedVal;
}

void IrrationalNumber::printInfo(){
    if (coefficient > 1 || coefficient < -1) cout << coefficient << "*";
    if (coefficient == -1) cout << "-";
    cout<<storedVal;
    RationalNumber* rN = dynamic_cast<RationalNumber*>(expo);
    if (rN) {
    	if(rN->getNumValue() != 1) {
    		cout << "^";
    		expo->printInfo();
    	}
    }
    else {
    	cout << "^"; expo->printInfo();
    }

}
string IrrationalNumber::toString() {
	string s = "";
	ostringstream c;
	if (coefficient > 1 || coefficient < -1) {
		c << coefficient;
		s.append(c.str());
		s.append("*");
	}
	if (coefficient == -1) {
		s.append("-");
	}
	s.append(storedVal);
	return s;
}
