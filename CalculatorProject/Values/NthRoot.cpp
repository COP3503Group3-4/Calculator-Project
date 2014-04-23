#include <NthRoot.h>
#include <RationalFraction.h>
#include <RationalNumber.h>
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
#include <set>
#include <map>
#include <algorithm>
NthRoot::NthRoot()
{
    //ctor
}

NthRoot::NthRoot(Value* a, Value* b){
    insideRoot = a;
    rootNum = b;

    //Constructor without a coefficient, just creates an object of type NthRoot.
}

NthRoot::NthRoot(int coeff, Value* a, Value* b){
    coefficient = coeff;
    insideRoot = a;
    rootNum = b;
    //Constructs an object of type NthRoot with a coefficient, which will be helpful for the ops methods.

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
    cout<<coefficient<<"*";
    rootNum->printInfo();
    cout<<"rt:(";
    insideRoot->printInfo();
    cout<<")";
}

string NthRoot::toString(){
	ostringstream c;
	string s = "";
	if(coefficient > 1 || coefficient < -1) {
		c << coefficient;
		s.append(c.str());
		s.append("*");
	}
	if (coefficient == -1) s.append("-");
	s.append(rootNum->toString());
	s.append("rt:(");
	s.append(insideRoot->toString());
	s.append(")");
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

    /*
        Typechecks the base and the exponent
    */
    Exponentiate expo;

    /*
        Creates an Exponentiate object in order to handle fractional exponents.
    */
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
        /*
            Sets initial values for the powers, values to be rooted, and the comparisons.
        */
        if(fmod(numPow,comparisonNum) == 0 && fmod(numDem,comparisonDen) == 0){
           //(pow(initialDenominator,(1.0/initialPowDen))) == floor(pow(initialDenominator,(1.0/initialPowDen)))
            int newNumerator = pow(initialNumerator,(1.0/initialPowDen));
            int newDenominator = pow(initialDenominator,(1.0/initialPowDen));
            //cout<<newNumerator<<endl;
            //cout<<newDenominator<<endl;
            Value* simpFrac = new RationalFraction(newNumerator, newDenominator);
            simpFrac = expo.exponentiate(simpFrac, newPower);
            simpFrac->printInfo();
            return simpFrac;
            /*
                If both the numerator and denominator have perfect roots, return the perfect roots.
            */
        }
        else if(initialPowDen == 3){
            if(floor(cbrt(initialNumerator)) == (cbrt(initialNumerator)) && floor(cbrt(initialDenominator)) == cbrt(initialDenominator)){
                int newNumerator = cbrt(initialNumerator);
                int newDenominator = cbrt(initialDenominator);
                //cout<<newNumerator<<endl;
                //cout<<newDenominator<<endl;
                Value* simpFrac = new RationalFraction(newNumerator, newDenominator);
                simpFrac = expo.exponentiate(simpFrac, newPower);
                simpFrac->printInfo();
                return simpFrac;
            }
            else if(floor(cbrt(initialNumerator)) == (cbrt(initialNumerator)) && floor(cbrt(initialDenominator)) != cbrt(initialDenominator)){
                int simpNum = cbrt(initialNumerator);
                Value* newNum = new RationalNumber(simpNum);
                //cout<<"Simp Num: "<<simpNum<<endl;
                int index = 2;
                Value* newDen = new NthRoot();
                vector<int> storeNum;
                newDen = rootDenominator(initialDenominator, index, coefficient, initialPowDen, storeNum);
                Value* simpIRF = new IrrationalFraction(newNum, newDen);
                return simpIRF;
            }
            else if(floor(cbrt(initialNumerator)) != (cbrt(initialNumerator)) && floor(cbrt(initialDenominator)) == cbrt(initialDenominator)){
                int simpDen = cbrt(initialDenominator);
                Value* newDen = new RationalNumber(simpDen);
                //cout<<"SimpDen: " <<simpDen<<endl;
                int index = 2;
                Value* newNum = new NthRoot();
                vector<int> storeNums;
                newNum = rootNumerator(initialNumerator, index, coefficient, initialPowDen, storeNums);
                Value* simpIRF = new IrrationalFraction(newNum,newDen);
                return simpIRF;
            }
            /*
                Since 1/3 does not have an accurate floating point, this section handles
                any sort of combination of the cube root. Provided that at least one of the numbers are
                not perfect cube roots, the numerator or denominator will simplify by pulling out prime factors.
            */
        }

        else if(numPow == comparisonNum && numDem != comparisonDen){
            int simpNum = pow(initialNumerator,(1/initialPowDen));
            Value* newNum = new RationalNumber(simpNum);
            //cout<<"SimpNum: "<<simpNum<<endl;
            int index = 2;
            Value* newDen = new NthRoot();
            vector<int> storeNum;
            newDen = rootDenominator(initialDenominator, index, coefficient, initialPowDen, storeNum);
            Value* simpIRF = new IrrationalFraction(newNum, newDen);
            return simpIRF;
        }
        else if(numPow != comparisonNum && numDem == comparisonDen){
            int simpDen = pow(initialDenominator,(1/initialPowDen));
            Value* newDen = new RationalNumber(simpDen);
            //cout<<"SimpDen: " <<simpDen<<endl;
            int index = 2;
            Value* newNum = new NthRoot();
            vector<int> storeNums;
            newNum = rootNumerator(initialNumerator, index, coefficient, initialPowDen, storeNums);
            Value* simpIRF = new IrrationalFraction(newNum,newDen);
            return simpIRF;
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
            return simpIRF;
        }
        /*
            These handle the simplification of other roots. One method calls with the numerator being a perfect root,
            one calls with the denominator, and one calls with neither.
        */
    }
   if(rN1 && rN2){
        /*
            This is the function if both the number to be rooted and the root are rational numbers.
            Much like every other section, the methods are essentially the same combination of "perfect roots" vs.
            "not at all a perfect root."
        */
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
                simpRN->printInfo();
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
                return simpFrac;
            }
            else if( initialPower == 3){
                if (floor(cbrt(initialNumerator)) == (cbrt(initialNumerator)) && floor(cbrt(initialDenominator)) == cbrt(initialDenominator)){
                    int newNumerator = cbrt(initialNumerator);
                    int newDenominator = cbrt(initialDenominator);
                    //cout<<newNumerator<<endl;
                    //cout<<newDenominator<<endl;
                    Value* simpFrac = new RationalFraction(newNumerator, newDenominator);
                    return simpFrac;
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
                    return simpIRF;
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
                    return simpIRF;
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
                return simpIRF;
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
                return simpIRF;
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
                return simpIRF;
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
            map<int, int> keepCount;

            for(int i = 0; i < storedInts.size(); i++){
                int numToInsert = storedInts[i];
                if(keepCount.count (numToInsert) > 0){
                    keepCount[numToInsert]++;
                }
                else{
                    keepCount[numToInsert] = 1;
                }
            }
            vector<int> finalValues;
            for (map<int,int>::iterator it=keepCount.begin(); it!=keepCount.end(); ++it){
                ////cout << "the number: "<< it->first << " apears " << it->second << "times" <<'\n';
                if(it->second == power){
                    coeff = coeff*it->first;
                }
                else if( it->second > power ){
                    int newPower = it->second - power;
                    coeff = coeff*it->first;
                    int newInside = pow(it->first,newPower);
                    finalValues.push_back(newInside);
                }
                else if( it->second < power){
                    //cout<<it->first<<" "<<it->second<<endl;
                    int newInside = pow(it->first, it->second);
                    finalValues.push_back(newInside);
                }
            }

            int finalInsideValue = 1;
            for(int i = 0; i < finalValues.size(); i++){
                finalInsideValue = finalInsideValue * finalValues[i];
            }

            Value* simplifiedInside = new RationalNumber(finalInsideValue);
            Value* simplifiedRoot = new NthRoot(coeff, simplifiedInside, rootNum );
            simplifiedRoot->printInfo();
            return simplifiedRoot;
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
            map<int, int> keepCount;

            for(int i = 0; i < storedInts.size(); i++){
                int numToInsert = storedInts[i];
                if(keepCount.count (numToInsert) > 0){
                    keepCount[numToInsert]++;
                }
                else{
                    keepCount[numToInsert] = 1;
                }
            }
            vector<int> finalValues;
            for (map<int,int>::iterator it=keepCount.begin(); it!=keepCount.end(); ++it){
                ////cout << "the number: "<< it->first << " apears " << it->second << "times" <<'\n';
                if(it->second == power){
                    coeff = coeff*it->first;
                }
                else if( it->second > power ){
                    int newPower = it->second - power;
                    coeff = coeff*it->first;
                    int newInside = pow(it->first,newPower);
                    finalValues.push_back(newInside);
                }
                else if( it->second < power){
                    //cout<<it->first<<" "<<it->second<<endl;
                    int newInside = pow(it->first, it->second);
                    finalValues.push_back(newInside);
                }
            }

            int finalInsideValue = 1;
            for(int i = 0; i < finalValues.size(); i++){
                finalInsideValue = finalInsideValue * finalValues[i];
            }

            Value* simplifiedInside = new RationalNumber(finalInsideValue);
            Value* simplifiedRoot = new NthRoot(coeff, simplifiedInside, rootNum );
            simplifiedRoot->printInfo();
            return simplifiedRoot;
        }
    }
}
