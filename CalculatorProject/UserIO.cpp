/*
* userio.cpp
*
*  created on: apr 2, 2014
*      author: corya_000
*/

#include "userio.h"

char uniques[13] = { '+', '-', '*', '/', 't', '_', ':', '(', ')', ' ', 'r', 'l', '^' };

userio::userio(string userinput)
{

	userin = userinput;
	splitinput();
	rpninput();
}

userio::~userio() {

}

vector<string> userio::getsplitinput()
{
	return splituserin;
}

vector<string> userio::rpn()
{
	return rpnuserin;
}

void userio::splitinput()
/*
* created by cory anderson
*/
{
	string s2 = userin;
	bool space = false;
	bool log = false;
	int ind = 0;

	while (ind < s2.length()) {
		for (int i = 0; i<13; i++) {
			//flag for getting rid of space and r
			if (s2.at(ind) == ' ' || s2.at(ind) == 'r') space = true;
			//flag for getting rid of log
			if (s2.at(ind) == '_') log = true;
			//if the char is unique
			if (s2.at(ind) == uniques[i]) {
				//if we are on the first char then just pop it off and adjust
				if (ind == 0) {
					//adding unique char
					splituserin.push_back(s2.substr(0, 1));
					//adjusting string
					s2 = s2.substr(ind + 1, s2.length() - 1);
				}
				//otherwise there may be a preceding number
				else {
					//adding the preceding number
					splituserin.push_back(s2.substr(0, ind));
					//adding the unique char
					splituserin.push_back(s2.substr(ind, 1));
					//adjusting string
					s2 = s2.substr(ind + 1, s2.length() - ind - 1);
				}
				//will allow ind to become 0 for next loop
				ind = -1;
				//will end the for loop
				break;
			}
		}
		ind++;
		if (space) {
			space = false;
			//getting rid of the space
			splituserin.pop_back();
		}
		if (log) {
			log = false;
			//removing "_"
			splituserin.pop_back();
			//removing "og"
			splituserin.pop_back();
			//removing "l"
			splituserin.pop_back();
			//adding back "_" to signify log
			splituserin.push_back("_");
		}

	}
	splituserin.push_back(s2);
}

void userio::rpninput()
////////////////////////////
//benjamin hayden duncan
//shunt.cpp
//
//shunting yard algorithm
//you can't imagine the
//number of times the
//debug was accessed
////////////////////////////
{
	//vector containing order of operations for reference.
	string pemdas[] = { "^", "_", "rt", "*", "/", "+", "-", "(" };

	//splituserin vector, for trial purposes.
	//vector<string> splituserin = { "a", "+", "b", "x", "c", "-", "d" };
	//vector<string> splituserin = { "3", "+", "4", "x", "2", "/", "(", "1", "-", "5", ")", "^", "2", "^", "3" };
	//vector<string> input = {"4", "+","(", "7", "/", "3", "*", "6", ")", "-", "3"};

	//declared in userio.h
	//vector<string> splituserin;
	//vector<string> rpnuserin;
	//vector<string> opopstack;

	string working;
	string search;
	string lastop;
	int last = 0;
	int current = 0;
	int s = 0;

	//start of some complicated shit.
	//comments may help explain.
	//this works for all the wikipedia examples.

	//massive for loop controls which elements to access from splituserin
	for (int i = 0; i < splituserin.size(); i++)
	{
		//the working variables is the accessed element
		working = splituserin.at(i);

		//initial if to determine if numeric or operational
		if (working == "^" || working == "_" || working =="rt" || working == "*" || working == "/" || working == "+" || working == "-")
		{
			if (opstack.size() != 0)
			{
				lastop = opstack.back();

				if (lastop == working)
				{
					opstack.push_back(working);
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
						opstack.push_back(working);
					}
					else
					{
						rpnuserin.push_back(lastop);
						opstack.pop_back();

						search = pemdas[s];

						//the following code check to make multiple moves from opstack if the incoming working varaible has less precedence.

						if (opstack.size() != 0)
						{
							lastop = opstack.back();

							if (lastop == working)
							{
								opstack.push_back(working);
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
									opstack.push_back(working);
								}
								else if (current == last)
								{
									opstack.push_back(working);
								}
								else
								{
									rpnuserin.push_back(lastop);
									opstack.pop_back();
									opstack.push_back(working);

								}

							}
						}
					}
				}

			}

			//default push, handles all number vaies
			else
			{
				opstack.push_back(working);
			}
		}

		//else ifs to account for parenthesis
		else if (working == "(")
		{
			opstack.push_back(working);
		}
		else if (working == ")")
		{
			while (opstack.back() != "(")
			{
				rpnuserin.push_back(opstack.back());
				opstack.pop_back();
			}
			opstack.pop_back();
		}
		else
		{
			rpnuserin.push_back(working);
		}
	}

	//the following code moves all remaining opstacks to the end of the rpnuserin, after all numbers move
	while (opstack.size() != 0)
	{
		rpnuserin.push_back(opstack.back());
		opstack.pop_back();
	}

	//print out split output
	cout << "splitinput vector: " << endl;
	cout << "{" << splituserin[0];
	for (int i = 1; i < splituserin.size(); i++)
	{
		cout << ", " << splituserin[i];
	}
	cout << "}" << endl;
	//printing out rpn output
	cout << "rpn vector: " << endl;
	cout << "{" << rpnuserin[0];
	for (int i = 1; i < rpnuserin.size(); i++)
	{
		cout << ", " << rpnuserin[i];
	}
	cout << "}" << endl;
	/*
	for (int i = 0; i < opstack.size(); i++)
	{
	cout << opstack.at(i);
	}
	*/

	//cout << endl;
}
