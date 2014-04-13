#include <Expression.h>

Expression::Expression()
{
}

Expression::Expression(vector<Value*> vals, vector<string> ops)
{
	this->ops = ops;
	values = vals;
}
Expression::Expression(Value* v1, Value* v2, string op)
{
	values.push_back(v1);
	values.push_back(v2);
	ops.push_back(op);
}
Expression::Expression(Value* v1, Value* v2, char op)
{
	values.push_back(v1);
	values.push_back(v2);
	stringstream ss;
	string s;
	ss << op;
	ss >> s;
	ops.push_back(s);
}

Expression::~Expression()
{

}

Value* Expression::simplify(){
	return 0;
}

Value* Expression::getNum1() {
	return 0;
}

Value* Expression::getNum2() {
	return 0;
}

void Expression::printInfo(){
	//Printing first value then op, value, op, value until end
	values[0]->printInfo();
	for (int i = 0; i < ops.size(); i++) {
		cout << " " << ops[i] << " ";
		values[i+1]->printInfo();
	}
}

bool Expression::getValue(string typeName, Value* v)
//Have to make sure that negative rational numbers are still added
{
	//Iterate through the values contained in the expression
	for (int i = 0; i < values.size(); i++) {
		//If the type id name provided matches the id of a value within the expression
		if(typeid(values[i]).name() == typeName) {
			//Give the value to v
			v = values[i];
			//Return true
			return true;
		}
	}
	//Method returns false if Value with provided typeID isn't found in the expression
	return false;
}
