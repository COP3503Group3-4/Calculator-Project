#ifndef VALUE_H
#define VALUE_H

#include <iostream>
#include <string>

using namespace std;

class Value
{
    public:
        Value();
        virtual ~Value();
        virtual Value* getNum1() = 0;
        virtual Value* getNum2() = 0;
        virtual Value* simplify() = 0;
        virtual void printInfo() = 0;
    protected:
    private:


};

#endif // VALUE_H
