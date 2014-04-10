/*
 * UserIO.h
 *
 *  Created on: Apr 2, 2014
 *      Author: corya_000
 */

#ifndef USERIO_H_
#define USERIO_H_

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class UserIO {
public:
	UserIO(string userInput);
	virtual ~UserIO();
	vector<string> getSplitInput();
	vector<string> rpn();

private:
	string userIn;
	vector<string> splitUserIn;
	vector<string> rpnUserIn;
	vector<string> opStack;
	void splitInput();
	void rpnInput();
	void rpnInput2();
	bool lessPrecedent(string op1, string op2);
	bool isOp(string token);
	void printRPN();
	void printSplit();
};

#endif /* USERIO_H_ */
