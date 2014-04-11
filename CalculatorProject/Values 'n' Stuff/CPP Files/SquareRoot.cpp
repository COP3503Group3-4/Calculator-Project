#include "SquareRoot.h"

SquareRoot::SquareRoot()
{

}

SquareRoot::SquareRoot(Value* a){
    insideRoot = a;
}

SquareRoot::~SquareRoot()
{
    //dtor
}

Value* SquareRoot::simplify(){
    RationalFraction* f1 = dynamic_cast<RationalFraction*>(insideRoot);
    Log* l1 = dynamic_cast<Log*>(insideRoot);
    RationalNumber* rN1 = dynamic_cast<RationalNumber*>(insideRoot);
    Expression* ex1 = dynamic_cast<Expression*>(insideRoot);
    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(insideRoot);
    IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(insideRoot);

    if(f1){

    }
    if(l1){

    }
    if(rN1){

    }
    if(ex1){

    }
    if(iRN1){

    }
    if(iRF1){

    }


}

Value* SquareRoot::getNum1(){

}

Value* SquareRoot::getNum2(){

}

void SquareRoot::printInfo(){

}
