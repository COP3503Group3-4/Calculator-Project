#include "Expression.h"
#include <sstream>
#include <string>

Expression::Expression()
{
}

Expression::Expression(Value* a, Value* b, char op){

}

Expression::~Expression()
{
    //dtor
}

int Expression::getNumerator(){
    return 1;
}

int Expression::getDenominator(){
    return 1;
}

int Expression::simplifyNumerator(int n, int d, int index){
    return 1;
}

int Expression::simplifyDenominator(int n, int d){
    return 1;
}

Value* Expression::getNum1(){

}

Value* Expression::getNum2(){

}

Value* Expression::simplify(){

}

void Expression::printInfo(){

}
