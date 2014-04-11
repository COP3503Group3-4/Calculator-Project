#ifndef NUMBER_H
#define NUMBER_H

#include <Value.h>


class Number : public Value
{
    public:
        Number();
        virtual ~Number();
        virtual Value* getNum1() = 0;
        virtual Value* getNum2() = 0;
        virtual Value* simplify() = 0;
        virtual void printInfo() = 0;
    protected:
    private:
};

#endif // NUMBER_H
