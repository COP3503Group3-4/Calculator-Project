#ifndef NTHROOT_H
#define NTHROOT_H

#include <Value.h>
#include <vector>

class NthRoot : public Value
{
    public:
        NthRoot();
        NthRoot(Value* a, Value* b);
        NthRoot(int coeff, Value*a, Value* b);
        virtual ~NthRoot();
        Value* getNum1();
        Value* getNum2();
        Value* simplify();
        void printInfo();
        string toString();
        Value* rootNum;
        Value* insideRoot;
        int coefficient = 1;
        int getCoefficient();
        Value* simplifyNumerator(Value* a, Value* b);
        Value* simplifyDenominator(Value* a, Value* b);
        Value* simplifyNumerator(int a, int b, int c);
        Value* rootDenominator(int insideVal, int index, int co, int power, vector<int> storeNum);
        Value* rootNumerator(int insideVal, int index, int co, int power, vector<int> storeNum);

    protected:
    private:
};

#endif // NTHROOT_H
