#ifndef LOG_H
#define LOG_H

#include <Value.h>
#include <RationalFraction.h>
#include <vector>

class Log : public Value
{
    public:
        Log(Value* b, Value* insideVal);
        Log();
        Log(int b, int insideVal);
        Log(int coeff, Value* b, Value* insideVal);
        int coefficient;
        Value* base;
        Value* insideValue;
        Value* simplify();
        virtual ~Log();
        Value* simplifyLog(Value* a, Value* b);
        void simplifyLogRN(int a, int b, int i);
        Value* logFactor(vector<int> a, int index1, int index2);
        Value* simplifyLogFactor(vector<Log> a, int index);
        Value* getNum1();
        Value* getNum2();
        int getBaseValue();
        int getInsideValue();
        int baseNum;
        int getCoefficient();
        int insideNum;
        void printInfo();
        string toString();
        Value* createSimpExpression(vector<int> a, Value* b);
        Value* addToCombine(vector<Value*> &a);
        bool isWholeLog(int b, int c);
        bool isPerfectLogRTF(int b, int c);
    protected:
    private:
        int perfectLog;
        RationalFraction perfectLogRTF;
};

#endif // LOG_H
