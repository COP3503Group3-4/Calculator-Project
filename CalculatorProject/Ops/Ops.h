/*
 * Ops.h
 *
 *  Created on: Apr 11, 2014
 *      Author: Cory
 */

#ifndef OPS_H_
#define OPS_H_

#include <Add.h>
#include <Multiply.h>
#include <Value.h>

class Ops {
public:
	Ops(Value* v1, Value* v2);
	Ops();
	virtual ~Ops();
	static Value* add(Value* v1, Value* v2);
	Value* add();
	static Value* subtract(Value* v1, Value* v2);
	Value* subtract();
	static Value* multiply(Value* val1, Value* val2);
	Value* multiply();
	static Value* divide(Value* v1, Value* v2);
	Value* divide();
private:
	Value* v1;
	Value* v2;
};

#endif /* OPS_H_ */
