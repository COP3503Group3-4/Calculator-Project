#ifndef LOG_H
#define LOG_H

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
        Value* getNum1();
        Value* getNum2();
        int getBaseValue();
        int getInsideValue();
        int baseNum;
        int insideNum;
        void printInfo();
    protected:
    private:
};

#endif // LOG_H
