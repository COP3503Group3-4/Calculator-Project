/*
 * divide.h
 *
 *  Created on: Apr 7, 2014
 *      Author: guorui
 */

#ifndef DIVIDE_H_
#define DIVIDE_H_

#include <Fraction.h>
#include <RationalFraction.h>
#include <Log.h>
#include <Expression.h>
#include <Number.h>
#include <RationalNumber.h>
#include <IrrationalNumber.h>
#include <Value.h>
#include <sstream>


class Divide
{
    public:
        Divide();
        static Value* divide(Value* a, Value* b);
        virtual ~Divide();
    protected:
    private:
};


#endif /* DIVIDE_H_ */
