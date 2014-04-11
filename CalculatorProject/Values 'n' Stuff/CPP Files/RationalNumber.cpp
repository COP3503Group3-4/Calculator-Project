#include "RationalNumber.h"

RationalNumber::RationalNumber()
{
    //ctor
}

RationalNumber::RationalNumber(int n1){
    num = n1;
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
    getNumValue();
}

Value* RationalNumber::getNum2(){
    getNumValue();
}

Value* RationalNumber::simplify(){
    getNumValue();
}

void RationalNumber::printInfo(){
    cout<<num;
}

