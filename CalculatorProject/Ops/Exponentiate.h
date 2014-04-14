/*
 * Exponentiate.h
 *
 *  Created on: Apr 14, 2014
 *      Author: guorui
 */

#ifndef EXPONENTIATE_H_
#define EXPONENTIATE_H_

#include <Fraction.h>
#include <RationalFraction.h>
#include <Log.h>
#include <Expression.h>
#include <Number.h>
#include <RationalNumber.h>
#include <IrrationalNumber.h>
#include <IrrationalFraction.h>
#include <Value.h>
#include <NthRoot.h>
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
        virtual ~Exponentiate();
    protected:
    private:
};

#endif /* EXPONENTIATE_H_ */
