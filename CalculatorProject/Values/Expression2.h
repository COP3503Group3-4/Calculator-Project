/*
 * Expression2.h
 *
 *  Created on: Apr 14, 2014
 *      Author: corya_000
 */

#ifndef EXPRESSION2_H_
#define EXPRESSION2_H_

#include <Value.h>
#include <string>
#include <vector>

class Expression2 {
public:
	Expression2(vector<Value*> sumVals, vector<Value*> prodVals, vector<string> ops);
	Expression2(Value* v1, Value* v2, string op);
	Expression2(Value* v1, Value* v2, char op);
	virtual ~Expression2();

	void minusToPlus();
	void simplifyOps();
private:
	vector<Value*> sums;
	vector<Value*> prods;
	vector<string> sumOps;
};

#endif /* EXPRESSION2_H_ */
