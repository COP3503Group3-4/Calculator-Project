/*
 * subtract.h
 *
 *  Created on: Apr 3, 2014
 *      Author: guorui
 */


#ifndef SUBTRACT_H_
#define SUBTRACT_H_

#include <Expression.h>
#include <Fraction.h>
#include <IrrationalFraction.h>
#include <Log.h>
#include <NthRoot.h>
#include <Number.h>
#include <RationalFraction.h>
#include <RationalNumber.h>
#include <SquareRoot.h>
#include <Value.h>
#include <Add.h>


class Subtract {
public:
	Subtract();
	static Value* subtract(Value* a, Value* b);
	virtual ~Subtract();
    protected:
    private:
};

#endif /* SUBTRACT_H_ */
