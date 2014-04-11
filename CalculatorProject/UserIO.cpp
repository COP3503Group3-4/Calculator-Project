/*
* UserIO.cpp
*
*  created on: apr 2, 2014
*      author: corya_000
*/

#include "UserIO.h"

using namespace std;

char uniques[18] = { '+', '-', '*', '/', 't', '_', ':', '(', ')', ' ', 'r', 's', 'l', '^', 'i', 'p', 'e', 'q'};

UserIO::UserIO(string userInput)
{
	userIn = userInput;
	splitInput();
	printSplit();
	rpnInput();
	printRPN();
}

UserIO::~UserIO() {

}

vector<string> UserIO::getSplitInput()
{
	return splitUserIn;
}

vector<string> UserIO::rpn()
{
	return rpnUserIn;
}

void UserIO::splitInput()
/*
* created by Cory Anderson
*/
{
	string s2 = userIn;
	bool space = false;
	bool log = false;
	bool pi = false;
	bool sqrt = false;
	int ind = 0;

	while (ind < s2.length()) {
		for (int i = 0; i<18; i++) {
			//Flag for getting rid of space and r
			if (s2.at(ind) == ' ' || s2.at(ind) == 'r' || s2.at(ind) == 'i' || s2.at(ind) == 'q') space = true;
			//Flag for getting rid of log
			if (s2.at(ind) == '_') log = true;
			if(s2.at(ind) == 'p') pi = true;
			if(s2.at(ind) == 'q') sqrt = true;
			//If the char is unique
			if (s2.at(ind) == uniques[i]) {
				//If we are on the first char then just pop it off and adjust
				if (ind == 0) {
					//Adding unique char
					splitUserIn.push_back(s2.substr(0, 1));
					//Adjusting string
					s2 = s2.substr(ind + 1, s2.length() - 1);
				}
				//otherwise there may be a preceding number
				else {
					//Adding the preceding number
					splitUserIn.push_back(s2.substr(0, ind));
					//Adding the unique char
					splitUserIn.push_back(s2.substr(ind, 1));
					//Adjusting string
					s2 = s2.substr(ind + 1, s2.length() - ind - 1);
				}
				//Will allow ind to become 0 for next loop
				ind = -1;
				//Will end the for loop
				break;
			}
		}
		ind++;
		if (space) {
			space = false;
			//Getting rid of the space
			splitUserIn.pop_back();
		}
		if(pi) {
			pi = false;
			splitUserIn.pop_back();
			splitUserIn.push_back("pi");
		}
		if (log) {
			log = false;
			//Removing "_"
			splitUserIn.pop_back();
			//Removing "og"
			splitUserIn.pop_back();
			//Removing "l"
			splitUserIn.pop_back();
			//Adding back "_" to signify log
			splitUserIn.push_back("_");
		}
		if(sqrt){
			sqrt = false;
			splitUserIn.pop_back();
			splitUserIn.push_back("2");
		}

	}
	if(s2.length() > 0) splitUserIn.push_back(s2);
}

void UserIO::rpnInput2()
{
	bool logFlag = false;
	string current;
	int ind = 0;
	while (ind < splitUserIn.size()) {
		current = splitUserIn[ind];
		if (isOp(current)) {
			if(opStack.size() > 0) {
				if(logFlag) {
					opStack.push_back(current);
				}
				else if(lessPrecedent(opStack[opStack.size() - 1], current)) {
					opStack.push_back(current);
				}
				else {
					while(!lessPrecedent(opStack[opStack.size()-1], current)) {
						if (opStack.size() == 1) {
							rpnUserIn.push_back(opStack[opStack.size() - 1]);
							opStack.pop_back();
							break;
						}
						else {
							rpnUserIn.push_back(opStack[opStack.size() - 1]);
							opStack.pop_back();
						}
					}
					opStack.push_back(current);
				}
			}
			else {
				opStack.push_back(current);
			}
		}
		else {
			if(current == ")") {
				while(opStack[opStack.size() - 1] != "(") {
					rpnUserIn.push_back(opStack[opStack.size() - 1]);
					opStack.pop_back();
				}
				opStack.pop_back();
			}
			else if (current == "(") {
				opStack.push_back(current);
			}
			else if (current == "_") {
				opStack.push_back(current);
				logFlag = true;
			}
			else if (current == ":") {
				if(logFlag) logFlag = false;
			}
			else {
				rpnUserIn.push_back(current);
			}
		}
		ind++;
	}
	while(opStack.size() > 0) {
		rpnUserIn.push_back(opStack[opStack.size() - 1]);
		opStack.pop_back();
	}
}
bool UserIO::isOp(string token)
{
	string ops [] = { "^", "t", "*", "/", "+", "-", " "};
	for (int i = 0; i < 7; i++) {
		if (token == ops[i])
		{
			return true;
		}
	}
		return false;
}
bool UserIO::lessPrecedent(string op1, string op2)
{
	//If stack op is less precedent than token op, will be adding token op to stack
	int pre1;
	int pre2;
	string pemdas [] = {"-", "+", "/", "*", "t", "_", "^"};
	for (int i = 0; i < 7; i++) {
		if (op1 == pemdas[i]) pre1 = i;
		if (op2 == pemdas[i]) pre2 = i;
	}
	if (pre1 > 3) {
		return false;
	}
	else if((pre1 / 2 - pre2 / 2) > 0) {
		return false;
	}
	else {
		return true;
	}
}

void UserIO::printRPN()
{
	//printing out rpn output
	cout << "RPN vector: " << endl;
	cout << "{" << rpnUserIn[0];
	for (int i = 1; i < rpnUserIn.size(); i++)
	{
		cout << ", " << rpnUserIn[i];
	}
	cout << "}" << endl;
}

void UserIO::printSplit()
{
	//print out split output
	cout << "splitInput vector: " << endl;
	cout << "{" << splitUserIn[0];
	for (int i = 1; i < splitUserIn.size(); i++)
	{
		cout << ", " << splitUserIn[i];
	}
	cout << "}" << endl;
}

void UserIO::rpnInput()
////////////////////////////
//Benjamin Hayden Duncan
//shunt.cpp
//
//shunting yard algorithm
//you can't imagine the
//number of times the
//debug was accessed
////////////////////////////
{
	//vector containing order of operations for reference.
	string pemdas[] = { "^", "_", "t", "sqrt", "*", "/", "+", "-", "(" };

	string working;
	string search;
	string lastop;
	int last = 0;
	int current = 0;
	int s = 0;

	//Start of some complicated shit.
	//Comments may help explain.
	//This works for all the wikipedia examples.

	//massive for loop controls which elements to access from splitUserIn
	for (int i = 0; i < splitUserIn.size(); i++)
	{
		//the working variables is the accessed element
		working = splitUserIn.at(i);

		//initial if to determine if numeric or operational
		if (working == "^" || working == "_" || working =="t" || working =="sqrt" || working == "*" || working == "/" || working == "+" || working == "-")
		{
			if (opStack.size() != 0)
			{
				lastop = opStack.back();

				if (lastop == working)
				{
					opStack.push_back(working);
				}
				else
				{
					while (search != working)
					{
						search = pemdas[s];
						s++;
					}
					current = s;
					s = 0;

					while (search != lastop)
					{
						search = pemdas[s];
						s++;
					}
					last = s;
					s = 0;

					if (current < last)
					{
						opStack.push_back(working);
					}
					else
					{
						rpnUserIn.push_back(lastop);
						opStack.pop_back();

						search = pemdas[s];

						//the following code check to make multiple moves from opStack if the incoming working varaible has less precedence.

						if (opStack.size() != 0)
						{
							lastop = opStack.back();

							if (lastop == working)
							{
								opStack.push_back(working);
							}
							else
							{

								while (search != working)
								{
									search = pemdas[s];
									s++;
								}
								current = s;
								s = 0;

								while (search != lastop)
								{
									search = pemdas[s];
									s++;
								}
								last = s;
								s = 0;

								if (current < last)
								{
									opStack.push_back(working);
								}
								else if (current == last)
								{
									opStack.push_back(working);
								}
								else
								{
									rpnUserIn.push_back(lastop);
									opStack.pop_back();
									opStack.push_back(working);

								}

							}
						}
						else
						{
							opStack.push_back(working);
						}

					}
				}

			}

			//default push, handles all number vaies
			else
			{
				opStack.push_back(working);
			}
		}

		//else ifs to account for parenthesis
		else if (working == ":")
		{
			
		}
		else if (working == "(")
		{
			opStack.push_back(working);
		}
		else if (working == ")")
		{
			while (opStack.back() != "(")
			{
				rpnUserIn.push_back(opStack.back());
				opStack.pop_back();
			}
			opStack.pop_back();
		}
		else
		{
			rpnUserIn.push_back(working);
		}
	}

	//the following code moves all remaining opStacks to the end of the rpnUserIn, after all numbers move
	while (opStack.size() != 0)
	{
		rpnUserIn.push_back(opStack.back());
		opStack.pop_back();
	}
}
