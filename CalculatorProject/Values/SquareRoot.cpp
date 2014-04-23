#include <SquareRoot.h>
#include <RationalFraction.h>
#include <IrrationalNumber.h>
#include <RationalNumber.h>
#include <IrrationalFraction.h>
#include <Log.h>
#include <NthRoot.h>
#include <Expression.h>
#include <cmath>
#include <sstream>

SquareRoot::SquareRoot()
{

}

SquareRoot::SquareRoot(Value* a){
	coefficient = 1;
    insideRoot = a;
}

SquareRoot::SquareRoot(int c, Value* a){
    coefficient = c;
    insideRoot = a;
}

SquareRoot::~SquareRoot()
{
    //dtor
}

Value* SquareRoot::simplify(){
    RationalFraction* f1 = dynamic_cast<RationalFraction*>(insideRoot);
    Log* l1 = dynamic_cast<Log*>(insideRoot);
    RationalNumber* rN1 = dynamic_cast<RationalNumber*>(insideRoot);
    Expression* ex1 = dynamic_cast<Expression*>(insideRoot);
    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(insideRoot);
    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(insideRoot);

    if(f1){
        int numer = f1->getNumerator();
        int denom = f1->getDenominator();
        if(sqrt(numer) == float(sqrt(numer)) && sqrt(denom) == float(sqrt(denom))){
            int simpNum = sqrt(numer);
            int simpDem = sqrt(denom);
            //cout<<simpNum<<'/'<<simpDem;
            Value* rootSim = new RationalFraction(simpNum,simpDem);
            return rootSim;
        }
        else if(sqrt(numer) == float(sqrt(numer)) && sqrt(denom) != float(sqrt(denom))){
            int simpNum = sqrt(numer);
            Value* newNum = new RationalNumber(simpNum);
            int index = 2;
            //cout<<simpNum<<'/';
            Value* newDem = new SquareRoot();
            newDem = simplifyDenominator(denom, index, coefficient);
            Value* simpRoot = new IrrationalFraction(newNum, newDem);
            return simpRoot;
        }
        else if(sqrt(denom) == float(sqrt(denom)) && sqrt(numer) != float(sqrt(numer))){
            int simpDem = sqrt(denom);
            Value* newDem = new RationalNumber(simpDem);
            int index = 2;
            //cout<<simpDem<<'/';
            Value* newNum = new SquareRoot();
            newNum = simplifyNumerator(numer, index, coefficient);
            Value* simpRoot = new IrrationalFraction(newNum,newDem);
            return simpRoot;
        }
        else{
            Value* newNum = new SquareRoot();
            Value* newDem = new SquareRoot();
            int index = 2;
            newNum = simplifyNumerator(numer, index, coefficient);
            newDem = simplifyDenominator(denom, index, coefficient);
            Value* simpRoot = new IrrationalFraction(newNum,newDem);
            return simpRoot;
        }
    }
    if(l1){

    }
    if(rN1){
        int inside = rN1->getNumValue();
        //cout<<inside<<endl;
        if (sqrt(inside) == floor(sqrt(inside))){
            int simpRoot = sqrt(inside);
            //cout<<simpRoot;
            Value* rootSim = new RationalNumber(simpRoot);
            return rootSim;
        }
        else{
            int index = 2;
            Value* newRoot = new SquareRoot();
            newRoot = simplifyNumerator(inside, index, coefficient);
            return newRoot;
        }
    }
    if(ex1){

    }
    if(iRN1){

    }
//    if(iRF1){

  //  }


}

Value* SquareRoot::simplifyNumerator(Value* a, Value* b){

}

Value* SquareRoot::getNum1(){
    int coeff = getCoefficient();
    Value* coeff2 = new RationalNumber(coeff);
    return coeff2;
}

Value* SquareRoot::getNum2(){
    return insideRoot;
}

void SquareRoot::printInfo(){
	if(coefficient != 1) cout << coefficient << "*";
	cout << "sqrt(";
	insideRoot->printInfo();
	cout << ")";
}

string SquareRoot::toString()
{
	string s = "";
	ostringstream c;
	if (coefficient != 1) {
		c << coefficient;
		s.append(c.str());
		s.append("*");
	}
	s.append("sqrt(");
	s.append(insideRoot->toString());
	s.append(")");
}

Value* SquareRoot::simplifyNumerator(int a, int b, int c){
    int inside = a;
    int i = b;
    int coeff = c;
    double compare = inside/(double)i;
    cout<<"C: "<<coeff<<endl;
    cout<<"I: "<<inside<<endl;
    cout<<"Compare: "<<compare<<endl;
    if(i >= inside){
        Value* insideSimp = new RationalNumber(inside);
        Value* power = new RationalNumber(2);
        Value* simplifiedRoot = new NthRoot(coeff, insideSimp, power);
       // cout<<coeff<<"sqrt("<<inside<<")";
        return simplifiedRoot;
    }
    else if((sqrt(i) == floor(sqrt(i))) && ((compare) == floor(compare))){
        int newCo = coeff*sqrt(i);
        int newInside = inside/i;
        cout<<"C: "<<newCo<<endl;
        cout<<"I: "<<newInside<<endl;
        return simplifyNumerator(newInside, i, newCo);
    }
    else{
        i++;
        return simplifyNumerator(inside, i, coeff);
    }
}

Value* SquareRoot::simplifyDenominator(int a, int b, int c){
    int inside = a;
    int i = b;
    int coeff = c;
    double compare = inside/(double)i;
    cout<<"C: "<<coeff<<endl;
    cout<<"I: "<<inside<<endl;
    cout<<"Compare: "<<compare<<endl;
    if(i >= inside){
        Value* insideSimp = new RationalNumber(inside);
        Value* power = new RationalNumber(2);
        Value* simplifiedRoot = new NthRoot(coeff, insideSimp, power);
        //cout<<coeff<<"sqrt("<<inside<<")";
        return simplifiedRoot;
    }
    else if((sqrt(i) == floor(sqrt(i))) && ((compare) == floor(compare))){
        int newCo = coeff*sqrt(i);
        int newInside = inside/i;
        cout<<"C: "<<newCo<<endl;
        cout<<"I: "<<newInside<<endl;
        return simplifyDenominator(newInside, i, newCo);
    }
    else{
        i++;
        return simplifyDenominator(inside, i, coeff);
    }
}
int SquareRoot::getCoefficient(){
    return coefficient;
}
