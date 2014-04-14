#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <Value.h>
#include <Number.h>

class RationalNumber : public Number
{
    public:
        RationalNumber();
        RationalNumber(int n1);
        RationalNumber(string s);
        virtual ~RationalNumber();
        Value* getNum1();
        Value* getNum2();
        Value* simplify();
        int getNumValue();
        void printInfo();
        string toString();
    protected:
    private:
        int num;
};

#endif // RATIONALNUMBER_H
