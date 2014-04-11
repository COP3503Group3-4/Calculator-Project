#ifndef RATIONALFRACTION_H
#define RATIONALFRACTION_H
#include "Fraction.h"
#include "RationalNumber.h"
class RationalFraction: public Fraction
{
    public:
        RationalFraction();
        RationalFraction(int n, int d);
        virtual ~RationalFraction();
        int numer;
        int denom;
        int getNumerator();
        int getDenominator();
        Value* getNum1();
        Value* getNum2();
        Value* simplify();
        int simplifyNum(int n, int d, int i);
        int simplifyDen(int n, int d, int i);
        void printInfo();
    protected:
    private:

};

#endif // RATIONALFRACTION_H
