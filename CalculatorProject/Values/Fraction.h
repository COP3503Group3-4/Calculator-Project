#ifndef FRACTION_H
#define FRACTION_H
#include <Value.h>

#include <string>

class Fraction: public Value
{
private:
public:
    Fraction();
    virtual ~Fraction();
    virtual Value* getNum1() = 0;
    virtual Value* getNum2() = 0;
    virtual Value* simplify() = 0;
    virtual void printInfo() = 0;

protected:

};

#endif // FRACTION_H
