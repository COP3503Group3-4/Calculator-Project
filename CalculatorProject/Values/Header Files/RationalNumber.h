#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <Number.h>


class RationalNumber : public Number
{
    public:
        RationalNumber();
        RationalNumber(int n1);
        int num;
        virtual ~RationalNumber();
        Value* getNum1();
        Value* getNum2();
        Value* simplify();
        int getNumValue();
        void printInfo();
    protected:
    private:
};

#endif // RATIONALNUMBER_H
