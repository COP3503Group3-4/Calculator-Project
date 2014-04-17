#include <IrrationalNumber.h>
#include <RationalNumber.h>
#include <sstream>

IrrationalNumber::IrrationalNumber()
{
    //ctor
}
IrrationalNumber::IrrationalNumber(string s){
	coefficient = 1;
    storedVal = s;
}

IrrationalNumber::IrrationalNumber(int coeff, string s){
    coefficient = coeff;
    storedVal = s;
}
IrrationalNumber::~IrrationalNumber()
{

}

Value* IrrationalNumber::getNum1(){
    Value* IR = new RationalNumber(coefficient);
    return IR;
}

Value* IrrationalNumber::getNum2(){
    Value* IR = new IrrationalNumber(getIRNumValue());
    return IR;
}

Value* IrrationalNumber::simplify(){
    getIRNumValue();
}

string IrrationalNumber::getIRNumValue(){
    return storedVal;
}

void IrrationalNumber::printInfo(){
    if (!coefficient == 1) cout<<coefficient;
    cout<<storedVal;
}
string IrrationalNumber::toString() {
	string s = "";
	ostringstream c;
	if (!coefficient == 1) {
		c << coefficient;
		s.append(c.str());
		s.append("*");
	}
	s.append(storedVal);
	return s;
}
