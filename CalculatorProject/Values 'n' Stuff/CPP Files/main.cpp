#include "Value.h"
#include "Fraction.h"
#include "RationalFraction.h"
#include "add.h"
#include <iostream>

using namespace std;

int main(){
    Value* f1 = new RationalFraction(12,9);
    Value* f2 = new RationalFraction(2,8);
    Value* f3 = new RationalFraction();
    Value* f4 = new RationalFraction();
    Value* rn1 = new RationalNumber(3);
    Value* rn2 = new RationalNumber(19);
    Value* rn3 = new RationalNumber(3);
    Value* rn4 = new RationalNumber(5);
    Value* rn5 = new RationalNumber();
    Value* l1 = new Log(rn1, rn2);
    Value* l2 = new Log(rn3, rn4);
    Value* l3 = new Log();
    string s = "e";
    Value* irN1 = new IrrationalNumber(s);
    Value* irN2 = new IrrationalNumber(s);
    Value* irN3 = new IrrationalNumber();
    //Value* e1 = new Expression();
    add* a1 = new add();
    add* a2 = new add();
    add* a3 = new add();
    add* a4 = new add();


    /*l3 = a1->addFractions(l1, l2);

    f3 = a1->addFractions(rn3,f1);
    f4 = a1->addFractions(f3, rn2);
    f4->simplify();
   // rn5 = a3->addFractions(rn1, rn2);

    //e1 = a3->addFractions(f1, l2);

    //l3->simplify();*/
}
