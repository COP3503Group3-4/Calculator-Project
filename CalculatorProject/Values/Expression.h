#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <Value.h>
#include <string>
#include <vector>
#include <IrrationalNumber.h>

class Expression : public Value
{
    public:
        Expression();
        //Vals will hold n values, ops will hold n-1 ops
        //Ex: pi + 3e + 2
        //Vals: pi, 3, e, 2
        //Ops: +,*,+
        Expression(Value* v1, Value* v2, string op);
        Expression(Value* v1, Value* v2, char op);
        virtual ~Expression();
        Value* simplify();
        Value* getNum1();
        Value* getNum2();
        void add(Value* v);
        void subtract(Value* v);
        void multiply(Value* v);
        void divide(Value* v);
        void printInfo();
        string toString();
        bool hasValue(string typeName);
        bool getValue(string typeName, Value* v, int* i);
        Value* getA(int i);
        int sizeA();
        int size();
        void minusToPlus();
        void makeNegative();
        void foil();
        void popOff(int ind, Value* vPtr);
        void popOff(int ind);
        void simplifyOps();
        bool getRational(Value* v, int* ind);
        bool getIrrational(IrrationalNumber* iN1, int* ind, string type);

    protected:
    private:
        vector<char> ops;
        vector<Value*> adds;
};

#endif // EXPRESSION_H
