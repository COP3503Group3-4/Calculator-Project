#ifndef ADD_H
#define ADD_H

#include <Expression.h>
#include <Fraction.h>
#include <IrrationalFraction.h>
#include <Log.h>
#include <NthRoot.h>
#include <Number.h>
#include <RationalFraction.h>
#include <RationalNumber.h>
#include <SquareRoot.h>
#include <Value.h>

class Add
{
    public:
        Add();
        Value* addVals(Value* a, Value* b);
        virtual ~Add();
        bool isEqual(Value* a, Value* b);
    protected:
    private:
};

#endif // ADD_H
