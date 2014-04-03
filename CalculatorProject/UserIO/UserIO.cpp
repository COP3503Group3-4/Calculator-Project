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
	//splitInput();
}

UserIO::~UserIO() {
	// TODO Auto-generated destructor stub
}

vector<string> UserIO::splitInput()
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

	return splitUserIn;
}

vector<string> UserIO::rpn()
{
	//Using rpnUserIn as output
	//opStack is the operator stack
	for (int i = 0; i < splitUserIn.size(); i++) {
		//Adding to operator stack or output
	}
	//Pop the rest of opStack to output

	return rpnUserIn;
}


