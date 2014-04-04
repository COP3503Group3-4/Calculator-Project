////////////////////////////
//Benjamin Hayden Duncan
//Shunt.cpp
//
//Shunting Yard Algorihm
//You can't imagine the
//number of times the
//debug was accessed
////////////////////////////

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//Vector containing Order of Operations for reference.
	vector<string> Pemdas = { "^", "_", "x", "/", "+", "-", "("};

	//Input vector, for trial purposes.
	//vector<string> input = { "A", "+", "B", "x", "C", "-", "D" };
	vector<string> input = { "3", "+", "4", "x", "2", "/", "(", "1", "-", "5", ")", "^", "2", "^", "3" };

	//All Variable declarations, will need to be moved to header.
	vector<string> output;
	vector<string> stack;
	string working;
	string search;
	string lastop;
	int last = 0;
	int current = 0;
	int s = 0;

	//Start of some complicated shit.
	//Comments may help explain.
	//This works for all the wikipedia examples.

  //Masssive for loop controls which elements to access from input
	for (int i = 0; i < input.size(); i++)
	{
	  //The working variables is the accessed element
		working = input.at(i);

    //Initial if to determine if numeric or operational
		if (working == "^" || working == "_" || working == "x" || working == "/" || working == "+" || working == "-")
		{
			if (stack.size() != 0)
			{
				lastop = stack.back();

				if (lastop == working)
				{
					stack.push_back(working);
				}
				else
				{
					while (search != working)
					{
						search = Pemdas.at(s);
						s++;
					}
					current = s;
					s = 0;

					while (search != lastop)
					{
						search = Pemdas.at(s);
						s++;
					}
					last = s;
					s = 0;

					if (current < last)
					{
						stack.push_back(working);
					}
					else
					{
						output.push_back(lastop);
						stack.pop_back();

						lastop = stack.back();
						search = Pemdas.at(s);
						
						//The following code check to make multiple moves from stack if the incoming working varaible has less precedence.

						if (stack.size() != 0)
						{
							lastop = stack.back();

							if (lastop == working)
							{
								stack.push_back(working);
							}
							else
							{

								while (search != working)
								{
									search = Pemdas.at(s);
									s++;
								}
								current = s;
								s = 0;

								while (search != lastop)
								{
									search = Pemdas.at(s);
									s++;
								}
								last = s;
								s = 0;

								if (current < last)
								{
									stack.push_back(working);
								}
								else if (current == last)
								{
									stack.push_back(working);
								}
								else
								{
									output.push_back(lastop);
									stack.pop_back();
									stack.push_back(working);

								}

							}
						}
					}
				}

			}
			
			//Default push, handles all number vaies
			else
			{
				stack.push_back(working);
			}
		}
		
		//Else ifs to account for parenthesis
		else if (working == "(")
		{
			stack.push_back(working);
		}
		else if (working == ")")
		{
			while (stack.back() != "(")
			{
				output.push_back(stack.back());
				stack.pop_back();
			}
			stack.pop_back();
		}
		else
			{
				output.push_back(working);
			}
	}
	
  //The following code moves all remaning stacks to the end of the output, after all numbers move
	while (stack.size() != 0)
	{
		output.push_back(stack.back());
		stack.pop_back();
	}

	for (int i = 0; i < output.size(); i++)
	{
		cout << output.at(i);
	}

	cout << endl;

	for (int i = 0; i < stack.size(); i++)
	{
		cout << stack.at(i);
	}
	
	cout << endl;
}
