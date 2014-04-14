#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <Value.h>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>

class Expression : public Value
{
    public:
        Expression();
        //Vals will hold n values, ops will hold n-1 ops
        //Ex: pi + 3e + 2
        //Vals: pi, 3, e, 2
        //Ops: +,*,+
        Expression(vector<Value*> vals, vector<string> ops);
        Expression(Value* v1, Value* v2, string op);
        Expression(Value* v1, Value* v2, char op);
        virtual ~Expression();
        Value* simplify();
        Value* getNum1();
        Value* getNum2();
        void printInfo();
        string toString();
        bool getValue(string typeName, Value* v);
    protected:
    private:
        vector<string> ops;
        vector<Value*> values;
};

#endif // EXPRESSION_H
