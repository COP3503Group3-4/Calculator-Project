/*
 * Ops.cpp
 *
 *  Created on: Apr 11, 2014
 *      Author: Cory
 */

#include "Ops.h"

Ops::Ops(Value* v1, Value* v2)
{
	this->v1 = v1;
	this->v2 = v2;
}
Ops::Ops()
{
	v1 = 0;
	v2 = 0;
}
Ops::~Ops() {
	// TODO Auto-generated destructor stub
}

Value* Ops::add(Value* val1, Value* val2)
{
	Add a1 = Add();
	return a1.addVals(val1,val2);
}
Value* Ops::add()
{
	Add a1 = Add();
	return a1.addVals(v1,v2);
}

Value* subtract(Value* val1, Value* val2)
{
	return 0;
}
Value* Ops::subtract() {
	return 0;
}

Value* multiply(Value* val1, Value* val2)
{
	return 0;
}
Value* Ops::multiply()
{
	return 0;
}

Value* divide(Value* val1, Value* val2)
{
	return 0;
}
Value* Ops::divide()
{
	return 0;
}
