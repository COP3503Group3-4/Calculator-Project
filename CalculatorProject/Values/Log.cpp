#include <Log.h>
#include <RationalFraction.h>
#include <RationalNumber.h>
#include <IrrationalNumber.h>
#include <IrrationalFraction.h>
#include <NthRoot.h>
#include <Expression.h>
#include <SquareRoot.h>
#include <sstream>
#include <string>
#include <Add.h>
#include <vector>

Log::Log(Value* b, Value* insideVal)
{
    base = b;
    insideValue = insideVal;
    coefficient = 1;
    /*
        This constructs a long with base equaling value B, an inside value equaling insideVal, and a coefficient of 1.
    */
}
Log::Log(int b, int insideVal){
    baseNum = b;
    insideNum = insideVal;
    coefficient = 1;
    //This is a separate constructor for dealing solely with rational integers, quite easy to simplify and use elsewhere.
}
Log::Log(int coeff, Value* b, Value* insideVal){
    coefficient = coeff;
    base = b;
    insideValue = insideVal;

    //Addition of the coefficient oarameter
}
Log::Log(){

}
Log::~Log()
{
}

Value* Log::simplify(){
    return simplifyLog(base, insideValue);

    //This will call simplifyLog; unfortunately, the method to actually break up the log was unable to be completed, and thus
    //calling this will simply print out the prime factors of the inside value of the log.
}

Value* Log::simplifyLog(Value* a, Value* b){
    RationalFraction* f1 = dynamic_cast<RationalFraction*>(a);
    RationalFraction* f2 = dynamic_cast<RationalFraction*>(b);
    RationalNumber* rN1 = dynamic_cast<RationalNumber*>(a);
    RationalNumber* rN2 = dynamic_cast<RationalNumber*>(b);
    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(a);
    IrrationalNumber* iRN2 = dynamic_cast<IrrationalNumber*>(b);
    vector<int> logValues;
    /*
        This section is for type-checking both the base and the value contained within the log. The Vector "logValues"
        was to be implemented within the method to factor the log.
    */
    if( f1 && f2 ){
        if((f1->getNumerator() && f1->getDenominator()) == (f2->getNumerator() && f2->getDenominator())){
            Value* rNSimp = new RationalNumber(1);
            return rNSimp;
        }
        /*
            A common theme here, IF the base AND the inside value are the same, return 1. The exponent that will return the value
            is one, thus return 1.
        */
    }
    if( (f1 && rN2) || (f2 && rN1) ){
        if (f1 && rN2){
            vector<int> storedVal;
            int index = 2;
            int newVal = rN2->getNumValue();
            return logFactor(storedVal, newVal, index);
        }
        if(rN1 && f2){
            Value* rnSimp = new Log(rN1, f2);
        }
        /*
            Here, check to see if the base and inside values are either a fraction and Rational Number (in that order) or a
            Rational Number and Fraction (in that order). With the former, factor the log into its prime components. With the latter,
            return a new log with the inside value equivalent to the fraction.
        */
    }
    if(rN1 && rN2){
        if(rN1->getNumValue() == rN2->getNumValue()){
            Value* rNSimp = new RationalNumber(1);
            return rNSimp;
        }
        else if( rN1->getNumValue() > rN2->getNumValue() && rN2->getNumValue() != 1){
            Value* simpLog = new Log(base, insideValue);
            return simpLog;
        }
        else{
            vector<int> storedVal;
            int index = 2;
            int newVal = rN2->getNumValue();
            return logFactor(storedVal,newVal, index);
        }
    }
    /*
        Here, the checks are only for Rational Number bases and inside Values. In the first if statement, 1 is returned,
        provided they are both equivalent. The else statement will call factor to split the log up into its components.
    */

    if(iRN1 && iRN2) {
    	//Need to perform power checking
    	if(iRN1->getIRNumValue() == iRN2->getIRNumValue()) {
    		return new RationalNumber(1);
    	}
    }
    if(iRN1 && rN2) {
    	return this;
    }
    if(rN1 && iRN2) {
    	return this;
    }
}

Value* Log::getNum1(){
    return base;
}
/*
    Since the base was the first constructed, getNum1 returns the Value pointer to the base.
*/

Value* Log::getNum2(){
    return insideValue;
}

/*
    Since the inside value was the second constructed, getNum2 returns the Value pointer to the inside value.
*/

void Log::printInfo(){
    if(coefficient != 1) cout<<coefficient;
    if(coefficient == -1) cout << "-";
    cout<<"log_";
    base->printInfo();
    cout<<":";
    insideValue->printInfo();
    //cout<<endl;
    /*
        This method simply prints out the status of the object. Each object type has a printInfo method, and when the base is
        called, for example, that object's method is called (so a RationalNumber base would call [RationalNumber]->printInfo).
    */
}

Value* Log::logFactor(vector<int> a, int index1, int index2){

    vector<int> storedRoots = a;
    int numToSimp = index1;
    int index = index2;
    //base->printInfo();
    vector<Value*> storedLogValues;

    if(numToSimp % index == 0){
        storedRoots.push_back(index);
        return logFactor(storedRoots, numToSimp/index, index);
    }
    else if(index < numToSimp){
        return logFactor(storedRoots, numToSimp, index + 1);
    }
    else{
        for(int i = 0; i < storedRoots.size(); i++){
            Value* logNum = new RationalNumber(storedRoots[i]);
            storedLogValues.push_back(logNum);
        }
    }

    vector<Value*> storedLogs;
    for(int i = 0; i < storedRoots.size(); i++){
        Value* initLog = new Log(base, storedLogValues[i]);
        Value* simpLog = new Log();
        simpLog = initLog->simplify();
        storedLogs.push_back(simpLog);
        //storedLogs[i]->printInfo();
    }
    Value* finalSimplify = addToCombine(storedLogs);
    return finalSimplify;

}

string Log::toString(){
	string s = "";
	ostringstream c;
    if(coefficient > 1 && coefficient < -1) {
    	c << coefficient;
    	s.append(c.str());
    	c.str("");
    	c.clear();
    }
    if(coefficient == -1) s.append("-");
    s.append("log_");
    s.append(base->toString());
    s.append(":");
    s.append(insideValue->toString());
    return s;

    /*
        This was the "failed to be implemented" toString method. This was kind of a slip-up on our parts.
    */
}

/*Value* Log::simplifyLogFactor(vector<Log> a, int index){
    vector<Log> storedLogs = a;

    if(index == storedLogs.size() - 1){
        Value* simpNum = new RationalNumber(1);
        return simpNum;

    }

    */
    /*
        This would pass in the recursive method, and simpNum would temporarily be returned (in order to show that it worked).
        The final implementation would have an expression type passed back to the other functions.
    */

    /*else{
        Log logSimp;
        logSimp = storedLogs[index];
        Log logSimp2;
        logSimp2 = storedLogs[index+1];*/
        /*
            This created log type objects according to their position in the log vector.
        */
        /*if((logSimp.getBaseValue() == logSimp2.getBaseValue()) &&
           (logSimp.getInsideValue() == logSimp2.getInsideValue())){
            int sum1 = logSimp.getCoefficient();
            int sum2 =logSimp2.getCoefficient();
            int finalSum = sum1 + sum2;
            Log simplifiedLog(finalSum, base, insideValue);
            storedLogs.erase (0);
            storedLogs.erase (1);
            storedLogs.insert (simplifiedLog, 0);
            storedLogs.shrink_to_fit();
            return simplifyLogFactor(storedLogs, index++);*/
            /*
                This part of the method, would add the logs together if their bases and inside values were the same to produce
                one log with a coefficient. Then, the vector would shrink, and this piece would be placed at index 0.
            */
      /*  }
        else{
            return simplifyLogFactor(storedLogs, index++);
        }
    }
}
*/
/*Value* Log::createSimpExpression(vector<int> a, Value* b ){
    vector<int> storedVals = a;
    Value* expressionSimp = b;

    if(storedVals.size() > 1){
        int newNum1 = storedVals.back();
        Value* logSimp1 = new Log(baseNum, newNum1);
        storedVals.pop_back();

        int newNum2 = storedVals.back();
        Value* logSimp2 = new Log(baseNum,newNum2);
        storedVals.pop_back();

        Value* simpExp = new Expression(logSimp1,logSimp2, "+");

        return createSimpExpression(storedVals, simpExp);
    }
    else if(storedVals.size() == 1){
        int newNum1 = storedVals.back();
        storedVals.pop_back();
        Value* logSimp = new Log(baseNum, newNum1);
        Value* simpExp = new Expression(expressionSimp, logSimp, "+");
        return simpExp;
    }
    else{
        return expressionSimp;
    }

    This was a preliminary idea for simplifying the logs by producing an Expression straight out of the gate. As I'm sure you can well
    imagine, it didn't work.
}*/

int Log::getCoefficient(){
    return coefficient;
}
/*
    All this method would do is return the coefficient in front of the log object.
*/

Value* Log::addToCombine(vector<Value*>& a){
    //vector<Value*> simpVector = a;
    int simpSize = a.size();

    if(a.size() < 2){
        return a[0];
    }
    else{
        Value* v1 = a[simpSize - 1];
        Value* v2 = a[simpSize-2];
        a.pop_back();
        a.pop_back();
        Value* v3 = new RationalNumber();
        v3 = Add::add(v1, v2);
        a.push_back(v3);
        addToCombine(a);
    }
}
