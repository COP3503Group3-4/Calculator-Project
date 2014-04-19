/*
 * subtract.h
 *
 *  Created on: Apr 3, 2014
 *      Author: guorui
 */


#ifndef SUBTRACT_H_
#define SUBTRACT_H_

#include <Value.h>


class Subtract {
public:
	Subtract();
	static Value* subtract(Value* a, Value* b);
	virtual ~Subtract();
	static bool isEqual(Value* a, Value* b);
    protected:
    private:
};

#endif /* SUBTRACT_H_ */
