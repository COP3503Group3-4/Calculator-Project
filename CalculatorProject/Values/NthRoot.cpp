#include "NthRoot.h"
#include <RationalFraction.h>
#include <IrrationalNumber.h>
#include <IrrationalFraction.h>
#include <Log.h>
#include <NthRoot.h>
#include <Expression.h>
#include <SquareRoot.h>
#include <Exponentiate.h>
#include <cmath>
#include <tgmath.h>
#include <vector>
#include <sstream>

NthRoot::NthRoot()
{
    //ctor
}

NthRoot::NthRoot(Value* a, Value* b){
	coefficient = 1;
    insideRoot = a;
    rootNum = b;
}

NthRoot::NthRoot(int coeff, Value* a, Value* b){
    coefficient = coeff;
    insideRoot = a;
    rootNum = b;


}
NthRoot::~NthRoot()
{
    //dtor
}

Value* NthRoot::getNum1(){

}

Value* NthRoot::getNum2(){

}

void NthRoot::printInfo(){
	rootNum->printInfo();
	cout << "rt";
	insideRoot->printInfo();
}
string NthRoot::toString(){
	ostringstream c;
	string s = "";
	s.append(rootNum->toString());
	s.append("rt");
	s.append(insideRoot->toString());
	return s;
}

Value* NthRoot::simplify(){
    RationalFraction* f1 = dynamic_cast<RationalFraction*>(insideRoot);
    RationalFraction* f2 = dynamic_cast<RationalFraction*>(rootNum);
    Log* l1 = dynamic_cast<Log*>(insideRoot);
    Log* l2 = dynamic_cast<Log*>(rootNum);
    RationalNumber* rN1 = dynamic_cast<RationalNumber*>(insideRoot);
    RationalNumber* rN2 = dynamic_cast<RationalNumber*>(rootNum);
    Expression* ex1 = dynamic_cast<Expression*>(insideRoot);
    Expression* ex2 = dynamic_cast<Expression*>(rootNum);
    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(insideRoot);
    IrrationalNumber* iRN2 = dynamic_cast<IrrationalNumber*>(rootNum);
    IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(insideRoot);
    IrrationalFraction* iRF2 = dynamic_cast<IrrationalFraction*>(rootNum);
    SquareRoot* sqr1 = dynamic_cast<SquareRoot*>(insideRoot);
    SquareRoot* sqr2 = dynamic_cast<SquareRoot*>(rootNum);

    Exponentiate expo;
    if(f1 && f2){
        double initialNumerator = f1->getNumerator();
        double initialDenominator = f1->getDenominator();
        //cout<<initialDenominator<<endl;
        double initialPowNum = f2->getNumerator();
        double initialPowDen = f2->getDenominator();
        double numPow = (pow((initialNumerator),(double)(1/initialPowDen)));
        double numDem = (pow(initialDenominator,(double)(1/initialPowDen)));
        double comparisonNum = round((pow(initialNumerator,(double)(1/initialPowDen))));
        double comparisonDen = round((pow(initialDenominator,(double)(1/initialPowDen))));
        Value* newPower = new RationalNumber(initialPowNum);

        if(fmod(numPow,comparisonNum) == 0 && fmod(numDem,comparisonDen) == 0){
           //(pow(initialDenominator,(1.0/initialPowDen))) == floor(pow(initialDenominator,(1.0/initialPowDen)))
            int newNumerator = pow(initialNumerator,(1.0/initialPowDen));
            int newDenominator = pow(initialDenominator,(1.0/initialPowDen));
            ////cout<<newNumerator<<endl;
            ////cout<<newDenominator<<endl;
            Value* simpFrac = new RationalFraction(newNumerator, newDenominator);
            simpFrac = expo.exponentiate(simpFrac, newPower);
            simpFrac->printInfo();
            return simpFrac;
        }
        else if(initialPowDen == 3){
            if(floor(cbrt(initialNumerator)) == (cbrt(initialNumerator)) && floor(cbrt(initialDenominator)) == cbrt(initialDenominator)){
                int newNumerator = cbrt(initialNumerator);
                int newDenominator = cbrt(initialDenominator);
                ////cout<<newNumerator<<endl;
                ////cout<<newDenominator<<endl;
                Value* simpFrac = new RationalFraction(newNumerator, newDenominator);
                simpFrac = expo.exponentiate(simpFrac, newPower);
                return simpFrac;
            }
            else if(floor(cbrt(initialNumerator)) == (cbrt(initialNumerator)) && floor(cbrt(initialDenominator)) != cbrt(initialDenominator)){
                int simpNum = cbrt(initialNumerator);
                Value* newNum = new RationalNumber(simpNum);
                ////cout<<"Simp Num: "<<simpNum<<endl;
                int index = 2;
                Value* newDen = new NthRoot();
                vector<int> storeNum;
                newDen = rootDenominator(initialDenominator, index, coefficient, initialPowDen, storeNum);
                Value* simpIRF = new IrrationalFraction(newNum, newDen);
            }
            else if(floor(cbrt(initialNumerator)) != (cbrt(initialNumerator)) && floor(cbrt(initialDenominator)) == cbrt(initialDenominator)){
                int simpDen = cbrt(initialDenominator);
                Value* newDen = new RationalNumber(simpDen);
                ////cout<<"SimpDen: " <<simpDen<<endl;
                int index = 2;
                Value* newNum = new NthRoot();
                vector<int> storeNums;
                newNum = rootNumerator(initialNumerator, index, coefficient, initialPowDen, storeNums);
                Value* simpIRF = new IrrationalFraction(newNum,newDen);
            }
        }

        else if(numPow == comparisonNum && numDem != comparisonDen){
            int simpNum = pow(initialNumerator,(1/initialPowDen));
            Value* newNum = new RationalNumber(simpNum);
            ////cout<<"SimpNum: "<<simpNum<<endl;
            int index = 2;
            Value* newDen = new NthRoot();
            vector<int> storeNum;
            newDen = rootDenominator(initialDenominator, index, coefficient, initialPowDen, storeNum);
            Value* simpIRF = new IrrationalFraction(newNum, newDen);
        }
        else if(numPow != comparisonNum && numDem == comparisonDen){
            int simpDen = pow(initialDenominator,(1/initialPowDen));
            Value* newDen = new RationalNumber(simpDen);
            ////cout<<"SimpDen: " <<simpDen<<endl;
            int index = 2;
            Value* newNum = new NthRoot();
            vector<int> storeNums;
            newNum = rootNumerator(initialNumerator, index, coefficient, initialPowDen, storeNums);
            Value* simpIRF = new IrrationalFraction(newNum,newDen);
        }
        else if(numPow != comparisonNum && numDem != comparisonDen){
            Value* newNum = new NthRoot();
            Value* newDen = new NthRoot();
            int index = 2;
            vector<int> storeNums;
            vector<int> storeDens;
            newNum = rootNumerator(initialNumerator, index, coefficient, initialPowDen, storeNums);
            newDen = rootDenominator(initialDenominator, index, coefficient, initialPowDen, storeDens);
            Value* simpIRF = new IrrationalFraction(newNum, newDen);
        }
    }
   if(rN1 && rN2){
        double initialNumber = rN1->getNumValue();
        double initialPower = rN2->getNumValue();
        //cout<<initialNumber<<endl;
        //cout<<initialPower<<endl;
        double numPow = (pow((initialNumber),(1/initialPower)));
        double powTest = floor(pow(initialNumber,(1/initialPower)));
        //cout<<numPow<<endl;
        //cout<<powTest<<endl;
        if( initialPower == 3){
            if(cbrt(initialNumber) == floor(cbrt(initialNumber))){
                int simpValue = cbrt(initialNumber);
                Value* simpRN = new RationalNumber(simpValue);
                return simpRN;
            }
            else{
                Value* simpValue = new NthRoot();
                int index = 2;
                vector<int> storeNums;
                simpValue = rootNumerator(initialNumber, index, coefficient, initialPower, storeNums);
                return simpValue;
            }
        }

        else if( pow(initialNumber, (1/initialPower)) == round(pow(initialNumber,(1/initialPower)))){
            int simplifiedNum = pow(initialNumber, (1/initialPower));
            //cout<<simplifiedNum;
            Value* simplifiedVal = new RationalNumber(simplifiedNum);
            return simplifiedVal;
        }
        else{
            Value* newVal = new NthRoot();
            int index = 2;
            vector<int> newValues;
            newVal = rootNumerator(initialNumber,index, coefficient, initialPower, newValues);
            return newVal;
        }
   }
   if(f1 && rN2 || rN1 && f2){
        if(f1 && rN2){
            double initialNumerator = f1->getNumerator();
            double initialDenominator = f1->getDenominator();
            double initialPower = rN2->getNumValue();
            double numPow = (pow((initialNumerator),(double)(1/initialPower)));
            double numDem = (pow(initialDenominator,(double)(1/initialPower)));
            double comparisonNum = round((pow(initialNumerator,(double)(1/initialPower))));
            double comparisonDen = round((pow(initialDenominator,(double)(1/initialPower))));

            if(fmod(numPow,comparisonNum) == 0 && fmod(numDem,comparisonDen) == 0){
                //(pow(initialDenominator,(1.0/initialPowDen))) == floor(pow(initialDenominator,(1.0/initialPowDen)))
                int newNumerator = pow(initialNumerator,(1.0/initialPower));
                int newDenominator = pow(initialDenominator,(1.0/initialPower));
                //cout<<newNumerator<<endl;
                //cout<<newDenominator<<endl;
                Value* simpFrac = new RationalFraction(newNumerator, newDenominator);
            }
            else if( initialPower == 3){
                if (floor(cbrt(initialNumerator)) == (cbrt(initialNumerator)) && floor(cbrt(initialDenominator)) == cbrt(initialDenominator)){
                    int newNumerator = cbrt(initialNumerator);
                    int newDenominator = cbrt(initialDenominator);
                    //cout<<newNumerator<<endl;
                    //cout<<newDenominator<<endl;
                    Value* simpFrac = new RationalFraction(newNumerator, newDenominator);
                }
                else if(floor(cbrt(initialNumerator)) == (cbrt(initialNumerator)) && floor(cbrt(initialDenominator)) != cbrt(initialDenominator)){
                    int simpNum = cbrt(initialNumerator);
                    Value* newNum = new RationalNumber(simpNum);
                    //cout<<"Simp Num: "<<simpNum<<endl;
                    int index = 2;
                    Value* newDen = new NthRoot();
                    vector<int> storeNum;
                    newDen = rootDenominator(initialDenominator, index, coefficient, initialPower, storeNum);
                    Value* simpIRF = new IrrationalFraction(newNum, newDen);
                }
                else if(floor(cbrt(initialNumerator)) != (cbrt(initialNumerator)) && floor(cbrt(initialDenominator)) == cbrt(initialDenominator)){
                    int simpDen = cbrt(initialDenominator);
                    Value* newDen = new RationalNumber(simpDen);
                    //cout<<"SimpDen: " <<simpDen<<endl;
                    int index = 2;
                    Value* newNum = new NthRoot();
                    vector<int> storeNums;
                    newNum = rootNumerator(initialNumerator, index, coefficient, initialPower, storeNums);
                    Value* simpIRF = new IrrationalFraction(newNum,newDen);
                }
            }

            else if(numPow == comparisonNum && numDem != comparisonDen){
                int simpNum = pow(initialNumerator,(1/initialPower));
                Value* newNum = new RationalNumber(simpNum);
                //cout<<"SimpNum: "<<simpNum<<endl;
                int index = 2;
                Value* newDen = new NthRoot();
                vector<int> storeNum;
                newDen = rootDenominator(initialDenominator, index, coefficient, initialPower, storeNum);
                Value* simpIRF = new IrrationalFraction(newNum, newDen);
            }
            else if(numPow != comparisonNum && numDem == comparisonDen){
                int simpDen = pow(initialDenominator,(1/initialPower));
                Value* newDen = new RationalNumber(simpDen);
                //cout<<"SimpDen: " <<simpDen<<endl;
                int index = 2;
                Value* newNum = new NthRoot();
                vector<int> storeNums;
                newNum = rootNumerator(initialNumerator, index, coefficient, initialPower, storeNums);
                Value* simpIRF = new IrrationalFraction(newNum,newDen);
            }
            else if(numPow != comparisonNum && numDem != comparisonDen){
                Value* newNum = new NthRoot();
                Value* newDen = new NthRoot();
                int index = 2;
                vector<int> storeNums;
                vector<int> storeDens;
                newNum = rootNumerator(initialNumerator, index, coefficient, initialPower, storeNums);
                newDen = rootDenominator(initialDenominator, index, coefficient, initialPower, storeDens);
                Value* simpIRF = new IrrationalFraction(newNum, newDen);
            }
        }
    if(rN1 && f2){
        double initialNumber = rN1->getNumValue();
        int initialPowNum = f2->getNumerator();
        int initialPowDen = f2->getDenominator();
        double numPow = (pow((initialNumber),(double)(1/initialPowDen)));
        double comparisonNum = round((pow(initialNumber,(double)(1/initialPowDen))));
        Value* newPower = new RationalNumber(initialPowNum);

        if(initialPowDen == 3){
            if(cbrt(initialNumber) == floor(cbrt(initialNumber))){
                int simpValue = cbrt(initialNumber);
                Value* simpRN = new RationalNumber(simpValue);
                Value* newExponent = new RationalNumber(initialPowNum);
                simpRN = expo.exponentiate(simpRN, newExponent);
                simpRN->printInfo();
                return simpRN;
            }
           else{
                Value* simpValue = new NthRoot();
                int index = 2;
                vector<int> storeNums;
                simpValue = rootNumerator(initialNumber, index, coefficient, initialPowDen, storeNums);
                return simpValue;
            }
        }
       else if( pow(initialNumber, (1/initialPowDen)) == round(pow(initialNumber,(1/initialPowDen)))){
            int simplifiedNum = pow(initialNumber, (1/initialPowDen));
            //cout<<simplifiedNum;
            Value* simplifiedVal = new RationalNumber(simplifiedNum);
            Value* newExponent = new RationalNumber(initialPowNum);
            simplifiedVal = expo.exponentiate(simplifiedVal, newExponent);
            simplifiedVal->simplify();
            return simplifiedVal;
        }
        else{
            Value* newVal = new NthRoot();
            int index = 2;
            vector<int> newValues;
            newVal = rootNumerator(initialNumber,index, coefficient, initialPowDen, newValues);
            return newVal;
        }

    }
   }
}

Value* NthRoot::simplifyNumerator(int a, int b, int c){

}

Value* NthRoot::rootDenominator(int insideVal, int index, int co, int power, vector<int> storeNum){
    int inside = insideVal;
    int currentIndex = index;
    int coeff = co;
    //double newPow = (1/(double)power);
    vector<int> storedInts = storeNum;
    if(inside % currentIndex == 0){
        storedInts.push_back(currentIndex);
        return rootDenominator(inside/currentIndex, currentIndex, coeff, power, storedInts);
    }
    else if(currentIndex <= inside){
        return rootDenominator(inside, currentIndex + 1, coeff, power, storedInts);
    }
    else{
        if( storedInts.size() == 0 ){
            Value* simplified = new NthRoot(insideRoot, rootNum);
            return simplified;
        }
        else{
            vector<int> storedNumbers;
            storedNumbers.push_back (storedInts[0]);
            for(int i = 0; i < storedInts.size(); i++){
                int checkNum = storedInts[i];
                //cout<<"Check Num: "<<checkNum<<endl;
                for(int j = 0; j < storedNumbers.size(); j++){
                    int checkRN = storedNumbers[j];
                    //cout<<"Check RN: "<<checkRN<<endl;
                    for(int k = 0; k < storedNumbers.size(); k++){
                        if( checkRN != storedNumbers[k]){
                            storedNumbers.push_back(checkNum);
                            //cout<<storedNumbers[k];
                        }
                    }
                }
            }
            //cout<<"StoredInts Size: "<<storedInts.size()<<endl;
            //cout<<"StoredNumbers Size: "<< storedNumbers.size()<<endl;
            int comparison = storedInts.size() - storedNumbers.size();
            if(comparison == power){
                int newCoeff = storedInts[0];
                int newInside = storedInts[comparison];
                Value* newInsideVal = new RationalNumber(newInside);
                Value* newPower = new RationalNumber(power);
                Value* simpRoot = new NthRoot(newCoeff, newInsideVal, newPower );
                //cout<<newCoeff<<"("<<power<<"rt"<<newInside<<")";
                return simpRoot;
            }
            else if( comparison > power ){
                int newCoeff = storedInts[0];
                int num1 = 1;
                for(int i = comparison; i > storedNumbers.size() + 1; i--){
                    int num2 = storedInts[i];
                    num1 = num1 * num2;

                }
                int newInside = num1;
                Value* newInsideValue = new RationalNumber(newInside);
                Value* newPower = new RationalNumber(power);
                Value* simpRoot = new NthRoot(newCoeff, newInsideValue, newPower);
                //cout<<newCoeff<<"("<<power<<"rt"<<newInside<<")";
                return simpRoot;

            }
            else if( comparison < power){
                int newInside = 1;
                for(int i = 0; i < storedInts.size(); i++){
                    newInside = newInside * storedInts[i];
                }
                //cout<<power<<"rt:"<<newInside;
                Value* simpInside = new RationalNumber(newInside);
                Value* simpPower = new RationalNumber(power);
                Value* simplified = new NthRoot(simpInside, simpPower);
                return simplified;
            }
        }
    }
}


Value* NthRoot::rootNumerator(int insideVal, int index, int co, int power, vector<int> storeNum){
    int inside = insideVal;
    int currentIndex = index;
    int coeff = co;
    //double newPow = (1/(double)power);
    vector<int> storedInts = storeNum;
    if(inside % currentIndex == 0){
        storedInts.push_back(currentIndex);
        return rootNumerator(inside/currentIndex, currentIndex, coeff, power, storedInts);
    }
    else if(currentIndex <= inside){
        return rootNumerator(inside, currentIndex + 1, coeff, power, storedInts);
    }
    else{
        if( storedInts.size() == 0 ){
            Value* simplified = new NthRoot(insideRoot, rootNum);
            return simplified;
        }
        else{
            vector<int> storedNumbers;
            storedNumbers.push_back (storedInts[0]);
            for(int i = 0; i < storedInts.size(); i++){
                int checkNum = storedInts[i];
                ////cout<<checkNum;
                for(int j = 0; j < storedNumbers.size(); j++){
                    int checkRN = storedNumbers[j];
                    for(int k = 0; k < storedNumbers.size(); k++){
                        if( checkRN != storedNumbers[k]){
                            storedNumbers.push_back(checkRN);
                        }
                    }
                }
            }
            int comparison = storedInts.size() - storedNumbers.size();

            if(comparison == power){
                int newCoeff = storedInts[0];
                int newInside = storedInts[comparison];
                Value* newInsideVal = new RationalNumber(newInside);
                Value* newPower = new RationalNumber(power);
                Value* simpRoot = new NthRoot(newCoeff, newInsideVal, newPower );
                //cout<<newCoeff<<"("<<power<<"rt"<<newInside<<")";
                return simpRoot;
            }
            else if( comparison > power ){
                int newCoeff = storedInts[0];
                int num1 = 1;
                for(int i = comparison; i > storedNumbers.size() + 1; i--){
                    int num2 = storedInts[i];
                    num1 = num1 * num2;

                }
                int newInside = num1;
                Value* newInsideValue = new RationalNumber(newInside);
                Value* newPower = new RationalNumber(power);
                Value* simpRoot = new NthRoot(newCoeff, newInsideValue, newPower);
                //cout<<newCoeff<<"("<<power<<"rt"<<newInside<<")";
                return simpRoot;

            }
            else if( comparison < power){
                int newInside = 1;
                for(int i = 0; i < storedInts.size(); i++){
                    newInside = newInside * storedInts[i];
                }
                //cout<<power<<"rt:"<<newInside;
                Value* simpInside = new RationalNumber(newInside);
                Value* simpPower = new RationalNumber(power);
                Value* simplified = new NthRoot(simpInside, simpPower);
                return simplified;
            }
        }
    }
}
