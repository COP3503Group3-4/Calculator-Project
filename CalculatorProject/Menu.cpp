#include <string>
#include <iostream>

using namespace std;

int yup()
{
	int c;

	cout << endl << "Welcome to MathSys."
		<< endl << "1. Calculation" << endl << "2. View Syntax"
		<< endl << "3. View Stored Data" << endl << "4. Quit" << endl
		<< "Please choose an option: ";

	cin >> c;

	while (c != 4)
	{
		if (c == 1)
		{
			string data = "ssssss";
			//Need to call the calculation method.
			cout << endl << "Calculation."
				<< endl << "Calculation to be done: " << endl;

			cin.ignore();
			getline (cin, data);

			cout << endl << data << endl;

			///UserIO calculation = new UserIO(data);

			cout << endl << "Calculation complete." << endl << "Please choose an option: ";
			cin >> c;
		}
		if (c == 2)
		{
			cout << endl << "Welcome to View Syntax."
				<< endl << "1. Addition" << endl << "2. Subtraction"
				<< endl << "3. Multiplication" << endl << "4. Division" << endl
				<< "5. Root" << endl << "6. Logarithm" << endl << "7. Quit" << endl
				<< "Please choose an option: ";

			cin >> c;

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
		if (c == 3)
		{
			//Needs to call stored data.
			cout << endl << "View Stored." << endl << "Please choose an option: ";
			cin >> c;
		}
	}
	cout << endl << "MathSys Quit.";
}
