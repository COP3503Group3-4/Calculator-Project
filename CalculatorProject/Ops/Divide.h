/*
 * divide.h
 *
 *  Created on: Apr 7, 2014
 *      Author: guorui
 */

#ifndef DIVIDE_H_
#define DIVIDE_H_

#include <Value.h>


class Divide
{
    public:
        Divide();
        static Value* divide(Value* a, Value* b);
        virtual ~Divide();
        static bool isEqual(Value* a, Value* b);
    protected:
    private:
};


#endif /* DIVIDE_H_ */
