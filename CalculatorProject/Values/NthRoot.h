#ifndef NTHROOT_H
#define NTHROOT_H

#include <Value.h>

using namespace std;

class NthRoot : public Value {
    public:
        NthRoot();
        NthRoot(Value* a, Value* b);
        virtual ~NthRoot();
        Value* getNum1();
        Value* getNum2();
        Value* simplify();
        void printInfo();
        string toString();
        Value* rootNum;
        Value* insideRoot;
    protected:
    private:
};

#endif // NTHROOT_H
