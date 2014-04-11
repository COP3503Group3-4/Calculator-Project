#include "IrrationalNumber.h"

IrrationalNumber::IrrationalNumber()
{
    //ctor
}
IrrationalNumber::IrrationalNumber(string s){
    storedVal = s;
}
IrrationalNumber::~IrrationalNumber()
{
    //dtor
}

Value* IrrationalNumber::getNum1(){
    getIRNumValue();
}

Value* IrrationalNumber::getNum2(){
    getIRNumValue();
}

Value* IrrationalNumber::simplify(){
    getIRNumValue();
}

string IrrationalNumber::getIRNumValue(){
    return storedVal;
}

void IrrationalNumber::printInfo(){
    cout<<storedVal;
}
