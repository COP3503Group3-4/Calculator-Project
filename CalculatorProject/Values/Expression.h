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
        Expression(Value* v1, Value* v2, string op);
        Expression(Value* v1, Value* v2, char op);
        virtual ~Expression();
        Value* simplify();
        void zeroCheck();
        Value* getNum1();
        Value* getNum2();
        void add(Value* v);
        void subtract(Value* v);
        void printInfo();
        string toString();
        bool hasValue(string typeName);
        bool getValue(string typeName, Value* v, int* i);
        Value* get(int i);
        void addVal(Value* v);
        int size();
        void minusToPlus();
        void makeNegative();
        void foil();
        void popOffAt(int ind);
        void simplifyOps();
        bool getRational(int& ind);
        bool getIrrational(int& ind, string type);

    protected:
    private:
        vector<char> ops;
        vector<Value*> adds;
};

#endif // EXPRESSION_H
