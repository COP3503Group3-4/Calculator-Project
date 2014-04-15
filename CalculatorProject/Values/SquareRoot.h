#ifndef SQUAREROOT_H
#define SQUAREROOT_H

#include <Value.h>


class SquareRoot : public Value
{
    public:
        SquareRoot();
        SquareRoot(Value* a);
        SquareRoot(int c, Value* a);
        SquareRoot(int c, Value* a, bool simplified);
        int coefficient = 1;
        virtual ~SquareRoot();
        Value* simplifyNumerator(Value* a, Value* b);
        Value* simplifyDenominator(Value* a, Value* b);
        Value* simplifyNumerator(int a, int b, int c);
        Value* simplifyDenominator(int a, int b, int c);
        Value* getNum1();
        Value* getNum2();
        Value* simplify();
        Value* insideRoot;
        void printInfo();
        string toString();
        int getCoefficient();
    protected:
    private:
        bool simplified;
};

#endif // SQUAREROOT_H
