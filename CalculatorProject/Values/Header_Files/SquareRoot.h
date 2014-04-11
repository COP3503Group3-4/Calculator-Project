#ifndef SQUAREROOT_H
#define SQUAREROOT_H

#include <Value.h>
#include <RationalFraction.h>
#include <IrrationalNumber.h>
#include <Log.h>
#include <NthRoot.h>
#include <Expression.h>

class SquareRoot : public Value
{
    public:
        SquareRoot();
        SquareRoot(Value* a);
        virtual ~SquareRoot();
        Value* getNum1();
        Value* getNum2();
        Value* simplify();
        Value* insideRoot;
        void printInfo();
    protected:
    private:
};

#endif // SQUAREROOT_H
