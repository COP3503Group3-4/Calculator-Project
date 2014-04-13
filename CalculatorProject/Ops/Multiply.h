#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <Fraction.h>
#include <RationalFraction.h>
#include <Log.h>
#include <Expression.h>
#include <Number.h>
#include <RationalNumber.h>
#include <IrrationalNumber.h>
#include <Value.h>
#include <sstream>

class Multiply
{
    public:
        Multiply();
        static Value* multiply(Value* a, Value* b);
        virtual ~Multiply();
    protected:
    private:
};

#endif
