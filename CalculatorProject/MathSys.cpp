/*
 * MathSys.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: corya_000
 */

#include "MathSys.h"
using namespace std;

MathSys::MathSys() {
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
	cout << endl << "Welcome to MathSys."
		<< endl << "1. Calculation" << endl << "2. View Syntax"
		<< endl << "3. View Stored Data" << endl << "4. Quit" << endl
		<< "Please choose an option: ";

	cin >> c;

	//while loop used for menu control
	while (c != 4)
	{
		//Option 1 : Calculation
		if (c == 1)
		{
			string data = "ssssss";
			//Need to call the calculation method.
			cout << endl << "Calculation."
				<< endl << "Calculation to be done: " << endl;

			cin.ignore();
			getline (cin, data);

			cout << endl << "Input:" << endl << data << endl;

			UserIO calculation = UserIO(data);
			rpnToCalc = calculation.rpn();
			//lastAnswer = calculate();

			cout << endl << "Calculation complete." << endl << "Please choose an option: ";
			cin >> c;
		}

		//Option 2 : Syntax Menu
		//Move Into
		if (c == 2)
		{
			//print out Syntax Menu
			cout << endl << "Welcome to View Syntax."
				<< endl << "1. Addition" << endl << "2. Subtraction"
				<< endl << "3. Multiplication" << endl << "4. Division" << endl
				<< "5. Root" << endl << "6. Logarithm" << endl << "7. Quit" << endl
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
						<< endl << "(number)-(number)" << endl
						<< endl << "Please choose an option: ";
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
						<< endl << "(numerator)/(denominator)" << endl
						<< endl << "Please choose an option: ";
					cin >> c;
				}
				if (c == 5)
				{
					cout << endl << "Root Syntax."
						<< endl << "nroot((radicand),index)" << endl
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
			cout << endl << "Syntax Quit." << endl << endl << "Please choose an option: ";
			cin >> c;
		}

		// will be hanled by ans in future.
		if (c == 3)
		{
			//Needs to call stored data.
			cout << endl << "View Stored." << endl << "Please choose an option: ";
			cin >> c;
		}
	}

	//Defaults to Quit when logic is met.
	cout << endl << "MathSys Quit.";
}

/*
Value MathSys::lastAns() {
	return lastAnswer;
}

Value MathSys::calculate() {


	//Created by Cory Anderson

	//vector<string> rpnToCalc
	Value answer;
	Value v1;
	Value v2;
	string current = rpnToCalc[rpnToCalc.size() - 1];
	rpnToCalc.pop_back();

	if(current == "+" || current == "-" || current == "*" || current == "/" || current == "t" || current == "_") {
		v2 = calculate();
		v1 = calculate();
	}
	switch(current) {
		case "+":
			answer = Add.add(v1,v2);
			break;
		case "-":
			answer = Subtract.subtract(v1,v2);
			break;
		case "*":
			answer = Multiply.multiply(v1,v2);
			break;
		case "/":
			answer = Divide.divide(v1,v2);
			break;
		case "t":
			answer = Root(v1,v2);
			break;
		case "_":
			answer = Log(v1,v2);
			break;
		default:
			answer = RationalNumber(current);
	}

	return answer;
}
*/
