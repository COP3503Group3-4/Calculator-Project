/*
 * MathSys.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: corya_000
 */

#include <MathSys.h>
#include <iostream>
#include <UserIO.h>
#include <Value.h>
#include <Add.h>
#include <Multiply.h>
#include <Subtract.h>
#include <Divide.h>
#include <Exponentiate.h>
#include <SquareRoot.h>
#include <NthRoot.h>
#include <RationalNumber.h>
#include <Log.h>

using namespace std;

MathSys::MathSys() {
	lastAnswer = new RationalNumber(0);
	menu();
}

MathSys::~MathSys() {

}

void MathSys::menu()
////////////////////////////
//Benjamin Hayden Duncan
//Menu.cpp
//This is a basic menu
////////////////////////////
{
	//c will hold the user defined choices in the menu
	int c;

	//for printing out the Menu
	cout << "Welcome to MathSys."
		<< endl << "-----------------------------------"
		<< endl << "1. Calculation" << endl << "2. View Syntax"
		<< endl << "3. View Stored Data" << endl << "4. Quit" << endl
		<< "-----------------------------------" << endl
		<< "Please choose an option: ";

	cin >> c;

	//while loop used for menu control
	while (c != 4)
	{
		//Option 1 : Calculation
		if (c == 1)
		{
			string data = "0";
			//Need to call the calculation method.
			cout << endl << "Calculation to be done: " << endl;

			cin.ignore();
			getline (cin, data);

			cout << endl << "Input:" << endl << data << endl;

			UserIO calculation = UserIO(data, lastAnswer);

			rpnToCalc = calculation.rpn();
			lastAnswer = calculate();
			cout << "= ";
			lastAnswer->printInfo();
			Value* v = lastAnswer->simplify();
			//cout << endl;
			//v->printInfo();
			//cout << endl;

			cout << endl << "Calculation complete." << endl
					<< "-----------------------------------" << endl
					<< "Please choose an option: ";
			cin >> c;
		}

		//Option 2 : Syntax Menu
		//Move Into
		if (c == 2)
		{
			//print out Syntax Menu
			cout << endl << "Welcome to View Syntax."
					<< endl << "-----------------------------------"
				<< endl << "1. Addition" << endl << "2. Subtraction"
				<< endl << "3. Multiplication" << endl << "4. Division" << endl
				<< "5. Root" << endl << "6. Logarithm" << endl << "7. Quit"
				<< endl << "-----------------------------------" << endl
				<< "Please choose an option: ";

			cin >> c;

			//While loop used to control the Syntax Menu
			while (c != 7)
			{
				if (c == 1)
				{
					cout << endl << "Addition Syntax."
						<< endl << "(number)+(number)" << endl
						<< endl << "Please choose an option: ";
					cin >> c;
				}
				if (c == 2)
				{
					cout << endl << "Subtraction Syntax."
						<< endl << "(number)-( )(number)"
						<< endl << "The (space) is necessary, -(number) represents a negative number."
						<< endl << endl << "Please choose an option: ";
					cin >> c;
				}
				if (c == 3)
				{
					cout << endl << "Multiplication Syntax."
						<< endl << "(number)*(number)" << endl
						<< endl << "Please choose an option: ";
					cin >> c;
				}
				if (c == 4)
				{
					cout << endl << "Division Syntax."
						<< endl << "(numerator)/(denominator)"
						<< endl << "For negative fractions the sign goes out side parenthesis -(num/den)"
						<< endl << "Please choose an option: ";
					cin >> c;
				}
				if (c == 5)
				{
					cout << endl << "Root Syntax."
						<< endl << "(index)rt(radicand)" << endl
						<< endl << "Please choose an option: ";
					cin >> c;
				}
				if (c == 6)
				{
					cout << endl << "Logarithm Syntax."
						<< endl << "log((base),(number))" << endl
						<< endl << "Please choose an option: ";
					cin >> c;
				}
			}
			cout << endl << "-----------------------------------" << endl << "Syntax Quit." << endl << endl << "Please choose an option: ";
			cin >> c;
		}

		// will be hanled by ans in future.
		if (c == 3)
		{
			//Needs to call stored data.
			cout << endl << "View Stored." << endl;
					lastAnswer->printInfo();
					cout << endl << "-----------------------------------"
					<< endl << "Please choose an option: ";
			cin >> c;
		}
	}

	//Defaults to Quit when logic is met.
	cout << endl << "-----------------------------------"
	<< endl << "MathSys Quit."
	<< endl << "-----------------------------------";
}


Value* MathSys::lastAns() {
	return lastAnswer;
}

Value* MathSys::calculate() {
	//Created by Cory Anderson

	//This function is not that complicated
	//MathSys takes the RPN vector from the UserIO object := rpnToCalc
	//This function simply recursively pops off the last item of that vector
	//And does something based on what it is

	//Three values being used
	Value* answer;
	Value* v1;
	Value* v2;
	RationalNumber* n;
	if(rpnToCalc.empty()) return lastAnswer;
	string current = rpnToCalc[rpnToCalc.size() - 1];
	rpnToCalc.pop_back();

	if (current.length() == 1) {
		if(current == "+" || current == "-" || current == "*" || current == "/" || current == "t" || current == "_" || current == "^") {
			v2 = calculate();
			v1 = calculate();

				/*
				cout << "V1= ";
				v1->printInfo();
				cout << endl;
				cout << "Op= " << current << endl;
				cout << "V2= ";
				v2->printInfo();
				cout << endl;
				*/


				n = dynamic_cast<RationalNumber*>(v1);
		}
		if (current == "~") {
			v1 = new RationalNumber("0");
			v2 = calculate();
		}
		switch(current.at(0)) {
			case '+':
				answer = Add::add(v1,v2);
				break;
			case '-':
				answer = Subtract::subtract(v1,v2);
				break;
			case '*':
				answer = Multiply::multiply(v1,v2);
				break;
			case '/':
				answer = Divide::divide(v1,v2);
				break;
			case 't':
				if(n->getNumValue() == 2) {
					answer = new SquareRoot(v2);
				}
				else if(n->getNumValue() < 0) {
					RationalFraction* rF = new RationalFraction(-1,n->getNumValue() * -1);
					answer = Exponentiate::exponentiate(v2,rF);
				}
				else answer = new NthRoot(v2,v1);
				answer = answer->simplify();
				break;
			case '^':
				answer = Exponentiate::exponentiate(v1, v2);
				break;
			case '_':
				answer = new Log(v1,v2);
				answer = answer->simplify();
				break;
			case '~':
				answer = Subtract::subtract(v1,v2);
				break;
			default:
				if (current == "e") {
					answer = new IrrationalNumber("e");
				}
				else {
					answer = new RationalNumber(current);
				}
		}
	}
	else {
		if (current == "pi") {
			answer = new IrrationalNumber("pi");
		}
		else if (current == "-pi") {
			answer = new IrrationalNumber(-1,"pi");
		}
		else if (current == "-e") {
			answer = new IrrationalNumber(-1,"e");
		}
		else if(current == "ans") {
			answer = lastAnswer;
		}
		else if(current == "-ans") {
			RationalNumber* zero = new RationalNumber(0);
			answer = Subtract::subtract(zero,lastAnswer);
		}
		else {
			answer = new RationalNumber(current);
		}
	}

	return answer;
}
