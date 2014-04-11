#ifndef NTHROOT_H
#define NTHROOT_H

#include <Value.h>


class NthRoot : public Value
{
    public:
        NthRoot();
        NthRoot(Value* a, Value* b);
        virtual ~NthRoot();
        Value* getNum1();
        Value* getNum2();
        Value* simplify();
        void printInfo();
        Value* rootNum;
        Value* insideRoot;
    protected:
    private:
};

#endif // NTHROOT_H
