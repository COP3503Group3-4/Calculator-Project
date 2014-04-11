#ifndef ADD_H
#define ADD_H

#include "Value.h"
#include "Fraction.h"
#include "RationalFraction.h"
#include "Log.h"
#include "Expression.h"
#include "Number.h"
#include "RationalNumber.h"
#include "IrrationalNumber.h"

class add
{
    public:
        add();
        Value* addFractions(Value* a, Value* b);
        virtual ~add();
        bool isEqual(Value* a, Value* b);
    protected:
    private:
};

#endif // ADD_H
