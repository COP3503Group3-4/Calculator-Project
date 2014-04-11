#ifndef VALUE_H
#define VALUE_H

#include <iostream>
#include <string>

#include <Expression.h>
#include <Fraction.h>
#include <IrrationalFraction.h>
#include <IrrationalNumber.h>
#include <Log.h>
#include <NthRoot.h>
#include <Number.h>
#include <RationalFraction.h>
#include <RationalNumber.h>
#include <SquareRoot.h>

using namespace std;

class Value
{
    public:
        Value();
        virtual ~Value();
        virtual Value* getNum1() = 0;
        virtual Value* getNum2() = 0;
        virtual Value* simplify() = 0;
        virtual void printInfo() = 0;
    protected:
    private:


};

#endif // VALUE_H
