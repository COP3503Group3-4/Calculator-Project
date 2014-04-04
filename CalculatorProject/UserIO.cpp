/*
 * UserIO.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: corya_000
 */

#include "UserIO.h"

char uniques [13] = {'+','-','*','/','t','_',':','(',')',' ','r','l','^'};

UserIO::UserIO(string userInput)
{

	userIn = userInput;
	splitInput();
	rpnInput();
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
 * Created by Cory Anderson
 */
{
	string s2 = userIn;
	bool space = false;
	bool log = false;
	int ind = 0;

	while(ind < s2.length()) {
		for (int i = 0; i<13; i++) {
			//Flag for getting rid of space and r
			if (s2.at(ind) == ' ' || s2.at(ind) == 'r') space = true;
			//Flag for getting rid of log
			if (s2.at(ind) == '_') log = true;
			//If the char is unique
			if (s2.at(ind) == uniques[i]) {
				//If we are on the first char then just pop it off and adjust
				if (ind == 0) {
					//Adding unique char
					splitUserIn.push_back(s2.substr(0,1));
					//Adjusting string
					s2 = s2.substr(ind+1,s2.length()-1);
				}
				//Otherwise there may be a preceeding number
				else {
					//Adding the preceeding number
					splitUserIn.push_back(s2.substr(0,ind));
					//Adding the unique char
					splitUserIn.push_back(s2.substr(ind,1));
					//Adjusting string
					s2 = s2.substr(ind+1,s2.length() - ind - 1);
				}
				//Will allow ind to become 0 for next loop
				ind = -1;
				//Will end the foor loop
				break;
			}
		}
		ind++;
		if (space) {
			space = false;
			//Getting rid of the space
			splitUserIn.pop_back();
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

	}
	splitUserIn.push_back(s2);
}

void UserIO::rpnInput()
////////////////////////////
//Benjamin Hayden Duncan
//Shunt.cpp
//
//Shunting Yard Algorihm
//You can't imagine the
//number of times the
//debug was accessed
////////////////////////////
{
	//Vector containing Order of Operations for reference.
	string Pemdas [] = {"^", "_", "x", "/", "+", "-", "("};

	//splitUserIn vector, for trial purposes.
	//vector<string> splitUserIn = { "A", "+", "B", "x", "C", "-", "D" };
	//vector<string> splitUserIn = { "3", "+", "4", "x", "2", "/", "(", "1", "-", "5", ")", "^", "2", "^", "3" };

	//Declared in UserIO.h
	//vector<string> splitUserIn;
	//vector<string> rpnUserIn;
	//vector<string> opopStack;

	string working;
	string search;
	string lastop;
	int last = 0;
	int current = 0;
	int s = 0;

	//Start of some complicated shit.
	//Comments may help explain.
	//This works for all the wikipedia examples.

  //Masssive for loop controls which elements to access from splitUserIn
	for (int i = 0; i < splitUserIn.size(); i++)
	{
	  //The working variables is the accessed element
		working = splitUserIn.at(i);

    //Initial if to determine if numeric or operational
		if (working == "^" || working == "_" || working == "x" || working == "/" || working == "+" || working == "-")
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
						search = Pemdas[s];
						s++;
					}
					current = s;
					s = 0;

					while (search != lastop)
					{
						search = Pemdas[s];
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

						lastop = opStack.back();
						search = Pemdas[s];

						//The following code check to make multiple moves from opStack if the incoming working varaible has less precedence.

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
									search = Pemdas[s];
									s++;
								}
								current = s;
								s = 0;

								while (search != lastop)
								{
									search = Pemdas[s];
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
					}
				}

			}

			//Default push, handles all number vaies
			else
			{
				opStack.push_back(working);
			}
		}

		//Else ifs to account for parenthesis
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

  //The following code moves all remaining opStacks to the end of the rpnUserIn, after all numbers move
	while (opStack.size() != 0)
	{
		rpnUserIn.push_back(opStack.back());
		opStack.pop_back();
	}

	//Print out split output
	cout << "splitInput vector: " << endl;
	cout << "{" << splitUserIn[0];
	for (int i = 1; i < splitUserIn.size(); i++)
	{
		cout << ", " << splitUserIn[i];
	}
	cout << "}" << endl;
	//Printing out RPN output
	cout << "RPN vector: " << endl;
	cout << "{" << rpnUserIn[0];
	for (int i = 1; i < rpnUserIn.size(); i++)
	{
		cout << ", " << rpnUserIn[i];
	}
	cout << "}" << endl;
	/*
	for (int i = 0; i < opStack.size(); i++)
	{
		cout << opStack.at(i);
	}
	*/

	//cout << endl;
}


