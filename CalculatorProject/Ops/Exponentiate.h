/*
 * Exponentiate.h
 *
 *  Created on: Apr 14, 2014
 *      Author: guorui
 */

#ifndef EXPONENTIATE_H_
#define EXPONENTIATE_H_

#include <Value.h>
#include <sstream>

class Exponentiate
{
    public:
	Exponentiate();
	    static Value* simplifyNumerator(int a, int b, int c);
	    static Value* simplifyDenominator(int a, int b, int c);
	    static Value* takeNthRoot(Value* base, int root);
        static Value* exponentiate(Value* base, Value* exp);
        static int expo (int base, int exp);
        static int expo2(int base, int exp);
        virtual ~Exponentiate();
    protected:
    private:
};

#endif /* EXPONENTIATE_H_ */
