#ifndef LOG_H
#define LOG_H

#include <Expression.h>
#include <Fraction.h>
#include <IrrationalFraction.h>
#include <NthRoot.h>
#include <Number.h>
#include <RationalFraction.h>
#include <RationalNumber.h>
#include <SquareRoot.h>
#include <Value.h>

class Log : public Value
{
    public:
        Log(Value* b, Value* insideVal);
        Log();
        Log(int b, int insideVal);
        Value* base;
        Value* insideValue;
        Value* simplify();
        virtual ~Log();
        Value* simplifyLog(Value* a, Value* b);
        void simplifyLogRN(int a, int b, int i);
        Value* logFactor(vector<Value*>, int index1, int index2);
        Value* getNum1();
        Value* getNum2();
        int getBaseValue();
        int getInsideValue();
        int baseNum;
        int insideNum;
        void printInfo();
        string toString();

    protected:
    private:
};

#endif // LOG_H
