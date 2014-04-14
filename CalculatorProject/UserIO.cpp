/*
* UserIO.cpp
*
*  created on: apr 2, 2014
*      author: corya_000
*/

#include "UserIO.h"

using namespace std;

char uniques[19] = { '+', '-', '*', '/', 't', '_', ':', '(', ')', ' ', 'r', 's', 'l', '^', 'i', 'q', 'a', 'p', 'e'};

UserIO::UserIO(string userInput, Value* lastAnswer)
{
	userIn = userInput;
	lastAns = lastAnswer;
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
	string rawUserIn = userIn;
	bool space = false;
	bool log = false;
	bool pi = false;
	bool sqrt = false;
	bool ans = false;
	bool negative = false;
	vector<int> negativeInds;
	int ind = 0;

	while (ind < rawUserIn.length()) {
		//Flag for getting rid of the character
		if (rawUserIn.at(ind) == ' ' || rawUserIn.at(ind) == 'r' || rawUserIn.at(ind) == 'i' || rawUserIn.at(ind) == 'q') space = true;
		//Flag for getting rid of log
		if (rawUserIn.at(ind) == '_') log = true;
		//Flag for pi
		if(rawUserIn.at(ind) == 'p') pi = true;
		//Flag for converting sq in sqrt to 2
		if(rawUserIn.at(ind) == 'q') sqrt = true;
		if(rawUserIn.at(ind) == 'a') ans = true;
		if(rawUserIn.at(ind) == '-') negative = true;
		for (int i = 0; i < 19; i++) {
			//If the char is unique
			if (rawUserIn.at(ind) == uniques[i]) {
				//If we are on the first char in the string then just pop it off and adjust
				if (ind == 0) {
					//Adding unique char
					splitUserIn.push_back(rawUserIn.substr(0, 1));
					//Adjusting string
					rawUserIn = rawUserIn.substr(ind + 1, rawUserIn.length() - 1);
				}
				//otherwise there may be a preceding number
				else {
					//Adding the preceding number
					splitUserIn.push_back(rawUserIn.substr(0, ind));
					//Adding the unique char
					splitUserIn.push_back(rawUserIn.substr(ind, 1));
					//Adjusting string
					rawUserIn = rawUserIn.substr(ind + 1, rawUserIn.length() - ind - 1);
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
			//Getting rid of p, adding pi
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
			//Getting rid of sq
			splitUserIn.pop_back();
			//Adding 2
			splitUserIn.push_back("2");
			//sqrt(x) will result in 2rtx
		}
		if (ans) {
			ans = false;
			//Need to get rid of n and s in string
			rawUserIn = rawUserIn.substr(2, rawUserIn.length() - 2);
			//Getting rid of 'a'
			splitUserIn.pop_back();
			//Adding the last answer onto the beginning of the input string
			//Essentially, "ans" is replaced with the print out of the lastAnswer in parentheses
			string s = "(";
			//Won't work until Value gets an abstract toString method.
			s.append(lastAns->toString());
			s.append(")");
			s.append(rawUserIn);
			rawUserIn = s;
		}
		if (negative) {
			negative = false;
			bool neg2 = true;
			//Exclude pi and e
			for (int i = 0; i < 17; i++) {
				if(rawUserIn.at(0) == uniques[i]) {
					neg2 = false;
					break;
				}
			}
			//Getting rid of the "-"
			if (neg2) {
				splitUserIn.pop_back();
				negativeInds.push_back(splitUserIn.size());
			}
		}

	}
	if(rawUserIn.length() > 0) splitUserIn.push_back(rawUserIn);
	for (int i = 0; i < negativeInds.size(); i++) {
		string s = "-";
		s.append(splitUserIn[negativeInds[i]]);
		splitUserIn[negativeInds[i]] = s;
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
