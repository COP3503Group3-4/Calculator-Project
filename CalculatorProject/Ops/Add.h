#ifndef ADD_H
#define ADD_H

#include <Value.h>

class Add
{
    public:
        Add();
        static Value* add(Value* a, Value* b);
        virtual ~Add();
        static bool isEqual(Value* a, Value* b);
    protected:
    private:
};

#endif // ADD_H
