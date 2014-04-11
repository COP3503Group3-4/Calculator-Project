#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <Value.h>
#include <string>
class Expression : public Value
{
    public:
        Expression();
        Expression(Value* a, Value* b, char op);
        virtual ~Expression();
        string contained;
        int getNumerator();
        int getDenominator();
        int simplifyNumerator(int n, int d, int index);
        int simplifyDenominator(int n, int d);
        Value* simplify();
        Value* getNum1();
        Value* getNum2();
        void printInfo();
    protected:
    private:
};

#endif // EXPRESSION_H
