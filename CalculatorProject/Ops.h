/*
 * Ops.h
 *
 *  Created on: Apr 11, 2014
 *      Author: Cory
 */

#ifndef OPS_H_
#define OPS_H_

#include "Values/Header_Files/Add.h"
#include <Value.h>

class Ops {
public:
	Ops();
	virtual ~Ops();
	Value* add(Value* v1, Value* v2);
};

#endif /* OPS_H_ */
