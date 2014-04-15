#ifndef IRRATIONALNUMBER_H
#define IRRATIONALNUMBER_H
#include <Value.h>

#include <Number.h>


class IrrationalNumber : public Number
{
    public:
        IrrationalNumber();
        IrrationalNumber(string s);
        IrrationalNumber(int coeff, string s);
        int coefficient = 1;
        string storedVal;
        virtual ~IrrationalNumber();
        Value* getNum1();
        Value* getNum2();
        Value* simplify();
        string getIRNumValue();
        string toString();
        void printInfo();
    protected:
    private:
};

#endif // IRRATIONALNUMBER_H
