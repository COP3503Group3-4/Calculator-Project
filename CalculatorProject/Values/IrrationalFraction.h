#ifndef IRRATIONALFRACTION_H
#define IRRATIONALFRACTION_H

#include <Fraction.h>


class IrrationalFraction : public Fraction
{
    public:
        IrrationalFraction();
        IrrationalFraction(Value* a, Value* b);
        virtual ~IrrationalFraction();
        Value* getNum1();
        Value* getNum2();
        Value* simplify();
        void printInfo();
        string toString();
        Value* numerator;
        Value* denominator;
    protected:
    private:
};

#endif // IRRATIONALFRACTION_H
