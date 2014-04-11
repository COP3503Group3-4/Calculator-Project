#include <Expression.h>

Expression::Expression()
{
}

Expression::Expression(vector<Value*> vals, vector<string> ops){
	this->ops = ops;
	values = vals;
}

Expression::~Expression()
{

}

Value* Expression::simplify(){

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
