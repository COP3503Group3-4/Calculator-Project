/*
 * MathSys.h
 *
 *  Created on: Apr 4, 2014
 *      Author: corya_000
 */

#ifndef MATHSYS_H_
#define MATHSYS_H_

#include <string>
#include <iostream>
#include <vector>
#include "UserIO.h"
#include "Ops.h"
#include <value.h>

//#include "Ops/Add.h"
//#include "Ops/Multiply.h"

using namespace std;

class MathSys {
public:
	MathSys();
	virtual ~MathSys();
	void menu();
	Value* lastAns();
private:
	vector<string> rpnToCalc;
	Value* lastAnswer;
	Value* calculate();
};

#endif /* MATHSYS_H_ */
