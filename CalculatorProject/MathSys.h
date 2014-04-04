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

using namespace std;

class MathSys {
public:
	MathSys();
	virtual ~MathSys();
	void menu();
private:
	vector<string> rpnToCalc;
};

#endif /* MATHSYS_H_ */
