#include <RationalNumber.h>
#include <stdlib.h>
#include <sstream>

RationalNumber::RationalNumber()
{
    //ctor
}

RationalNumber::RationalNumber(int n1){
    num = n1;
}
RationalNumber::RationalNumber(string s)
{
	num = atoi(s.c_str());
}
RationalNumber::~RationalNumber()
{
    //dtor
}
int RationalNumber::getNumValue(){
    //cout<<num;
    return num;
}

Value* RationalNumber::getNum1(){
    return this;
}

Value* RationalNumber::getNum2(){
    getNumValue();
}

Value* RationalNumber::simplify(){
    return this;
}

void RationalNumber::printInfo(){
    cout<<num;
}
string RationalNumber::toString(){
	ostringstream c;
	c << num;
	string s = c.str();
	return s;
}

