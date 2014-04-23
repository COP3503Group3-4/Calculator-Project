#include "IrrationalFraction.h"
#include <RationalFraction.h>
#include <IrrationalNumber.h>
#include <Log.h>
#include <NthRoot.h>
#include <Expression.h>
#include <SquareRoot.h>
#include <cmath>

IrrationalFraction::IrrationalFraction()
{
    //ctor
}

IrrationalFraction::IrrationalFraction(Value* a, Value* b){
    numerator = a;
    denominator = b;
}

IrrationalFraction::~IrrationalFraction()
{
    //dtor
}

Value* IrrationalFraction::getNum1(){
    return numerator;
}

Value* IrrationalFraction::getNum2(){
    return denominator;
}

Value* IrrationalFraction::simplify(){
    Value* numTest = new RationalNumber();
    Value* denTest = new RationalNumber();

    numTest = this->getNum1();
    denTest = this->getNum2();

    Log* l1 = dynamic_cast<Log*>(numTest);
    Log* l2 = dynamic_cast<Log*>(denTest);
    RationalNumber* rN1 = dynamic_cast<RationalNumber*>(numTest);
    RationalNumber* rN2 = dynamic_cast<RationalNumber*>(denTest);
    Expression* ex1 = dynamic_cast<Expression*>(numTest);
    Expression* ex2 = dynamic_cast<Expression*>(denTest);
    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(numTest);
    IrrationalNumber* iRN2 = dynamic_cast<IrrationalNumber*>(denTest);
    SquareRoot* sqrtN = dynamic_cast<SquareRoot*>(numTest);
    SquareRoot* sqrtD = dynamic_cast<SquareRoot*>(denTest);

    if((rN1 && l2) || (rN1 && ex2) || (rN1 && iRN2) || (rN1 && sqrtD) ) {
        if ( rN1 && sqrtD ){
            Value* newDenom = new RationalNumber();
            newDenom = sqrtD->getNum2();
            RationalNumber* rTest2 = dynamic_cast<RationalNumber*>(newDenom);
            if(rTest2){
                int newNumCo = rN1->getNumValue();
                int newDenomCo = rTest2->getNumValue();
                /*if( newNumCo/(double)newDenomCo == floor(newNumCo/newDenomCo)){
                        int newNumCo2 = newNumCo / newDenomCo;
                        int newDenomCo2 = newDenomCo / newDenomCo;
                        Value* simpNumer = new SquareRoot(newNumCo2, sqrtD);
                        Value* simpDenom = new RationalNumber(newDenomCo2);
                        Value* simpFrac = new IrrationalFraction(simpRoot, simpDenom);
                        cout<<newNumCo2<<"sqrt("<<newDenom<<'/'<<newDenomCo2<<endl;
                }
                else if( newDenomCo/(double)newNumCo == floor(newDenomCo/newNumCo)){

                }*/
                //else{
                    cout<<newNumCo<<endl;
                    Value* simpNumer = new SquareRoot(newNumCo, newDenom);
                    Value* simpDenom = new RationalNumber(newDenomCo);
                    Value* simpRoot = new SquareRoot();
                    simpRoot = simpNumer->simplify();
                    /*SquareRoot* simplifiedRoot = dynamic_cast<SquareRoot*>(simpRoot);
                    if(simplifiedRoot){
                        int newCoefficient = simplifiedRoot->getCoefficient();
                        Value* inside = simpDenom(getNum2());
                        RationalNumber* newDenominator = dynamic_cast<RationalNumber*>(inside);
                        if(newDenominator){
                            int simplifiedDenominator = newDenominator->getNumValue();

                        }
                    }*/
                    Value* simpFrac = new IrrationalFraction(simpRoot, simpDenom);
                    cout<<'/'<<newDenomCo;
                    return simpFrac->simplify();
                //}
            }
        }
    }
    /*if( (sqrtN && rN2) || (sqrtN && l2) || (sqrtN && iRN2) || (sqrtN && ex2) ){
        if(sqrtN && rN2){
            int coeffiecient = sqrtN->getCoefficient();
            cout<<coeffiecient;
            Value* insideRoot = sqrtN->getNum2();
            int coeffDenTest = rN2->getNumValue();
            cout<<coeffDenTest;
            Value* RTF = new RationalFraction(coeffiecient,coeffDenTest);
            RationalFraction* simpRTF = dynamic_cast<RationalFraction*>(RTF);
            simpRTF->simplify();
            int newNumSimp = simpRTF->getNumerator();
            int newDenSimp = simpRTF->getDenominator();
            Value* simplifiedRoot = new SquareRoot(newNumSimp, insideRoot);
            Value* simplifiedDen = new RationalNumber(newDenSimp);
            Value* simplifiedFraction = new IrrationalFraction(simplifiedRoot,simplifiedDen);
            cout<<newNumSimp<<"sqrt("<<") / "<<newDenSimp;
            return simplifiedFraction;
        }
    }*/

}

void IrrationalFraction::printInfo(){
	cout << "((";
	numerator->printInfo();
	cout << ") / (";
	denominator->printInfo();
	cout << "))";
}
string IrrationalFraction::toString()
{
	string s = "";
	s.append("((");
	s.append(numerator->toString());
	s.append(") / (");
	s.append(denominator->toString());
	s.append("))");
	return s;
}
