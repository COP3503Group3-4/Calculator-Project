#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <Value.h>

class Multiply
{
    public:
        Multiply();
        static Value* multiply(Value* a, Value* b);
        virtual ~Multiply();
        static bool isEqual(Value* a, Value* b);
    protected:
    private:
};

#endif
