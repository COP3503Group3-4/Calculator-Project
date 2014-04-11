#ifndef IRRATIONALNUMBER_H
#define IRRATIONALNUMBER_H

#include <Number.h>


class IrrationalNumber : public Number
{
    public:
        IrrationalNumber();
        IrrationalNumber(string s);
        string storedVal;
        virtual ~IrrationalNumber();
        Value* getNum1();
        Value* getNum2();
        Value* simplify();
        string getIRNumValue();
        void printInfo();
    protected:
    private:
};

#endif // IRRATIONALNUMBER_H
