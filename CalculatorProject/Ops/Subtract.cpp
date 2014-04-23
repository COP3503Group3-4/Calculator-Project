/* subtract.cpp
 *  Created on: Apr 3, 2014
 *      Author: guorui
 */

#include <Subtract.h>
#include <Expression.h>
#include <Fraction.h>
#include <IrrationalFraction.h>
#include <Log.h>
#include <NthRoot.h>
#include <Number.h>
#include <RationalFraction.h>
#include <RationalNumber.h>
#include <SquareRoot.h>
#include <Value.h>
#include <Add.h>
#include <IrrationalNumber.h>

#include <sstream>
#include <typeinfo>

Subtract::Subtract() {}

Subtract::~Subtract() {}

 //Version 3:

 Value* Subtract::subtract(Value* a, Value* b) {

	int ind;
	RationalNumber* zero = new RationalNumber(0);
    //dynamic cast variables for later use
    RationalFraction* f1 = dynamic_cast<RationalFraction*>(a);
    RationalFraction* f2 = dynamic_cast<RationalFraction*>(b);
    Log* l1 = dynamic_cast<Log*>(a);
    Log* l2 = dynamic_cast<Log*>(b);
    RationalNumber* rN1 = dynamic_cast<RationalNumber*>(a);
    RationalNumber* rN2 = dynamic_cast<RationalNumber*>(b);
    Expression* ex1 = dynamic_cast<Expression*>(a);
    Expression* ex2 = dynamic_cast<Expression*>(b);
    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(a);
    IrrationalNumber* iRN2 = dynamic_cast<IrrationalNumber*>(b);
    //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(a);
    //IrrationalFraction* iRF2 = dynamic_cast<IrrationalFraction*>(b);
    NthRoot* nrtA = dynamic_cast<NthRoot*>(a);
    NthRoot* nrtB = dynamic_cast<NthRoot*>(b);
    SquareRoot* sqrA = dynamic_cast<SquareRoot*>(a);
    SquareRoot* sqrB = dynamic_cast<SquareRoot*>(b);


    if(f1 && f2){
        int n1 = f1->getNumerator() * f2->getDenominator();
        //cout<<"N1: "<<n1<<endl;
        int n2 = f2->getNumerator() * f1->getDenominator();
        //cout<<"N2: "<<n2<<endl;
        int d = f1->getDenominator() * f2->getDenominator();
        //cout<<"D: "<<d<<endl;
        Value* f3 = new RationalFraction(n1-n2,d);
		f3 = f3->simplify();
        return f3;
    }
    if(l1 && l2){
        Value* lB1 = l1->getNum1();
        Value* lB2 = l2->getNum1();
        Value* lIV1 = l1->getNum2();
        Value* lIV2 = l2->getNum2();
        if(Add::isEqual(lB1,lB2)){
            RationalNumber* rNB1 = dynamic_cast<RationalNumber*>(lB1);
            RationalNumber* rNB2 = dynamic_cast<RationalNumber*>(lB2);
            RationalFraction* rFB1 = dynamic_cast<RationalFraction*>(lB1);
            RationalFraction* rFB2 = dynamic_cast<RationalFraction*>(lB2);
            Log* l2B1 = dynamic_cast<Log*>(lB1);
            Log* l2B2 = dynamic_cast<Log*>(lB2);
            Expression* exB1 = dynamic_cast<Expression*>(lB1);
            Expression* exB2 = dynamic_cast<Expression*>(lB2);
            IrrationalNumber* iRNB1 = dynamic_cast<IrrationalNumber*>(lB1);
            IrrationalNumber* iRNB2 = dynamic_cast<IrrationalNumber*>(lB2);
            //IrrationalFraction* iRFB1 = dynamic_cast<IrrationalFraction*>(lB1);
            //IrrationalFraction* iRFB2 = dynamic_cast<IrrationalFraction*>(lB2);
            if( rNB1 && rNB2 ){
                RationalNumber* rNIV1 = dynamic_cast<RationalNumber*>(lIV1);
                RationalNumber* rNIV2 = dynamic_cast<RationalNumber*>(lIV2);
                RationalFraction* rFIV1 = dynamic_cast<RationalFraction*>(lIV1);
                RationalFraction* rFIV2 = dynamic_cast<RationalFraction*>(lIV2);
                Log* l2IV1 = dynamic_cast<Log*>(lIV1);
                Log* l2IV2 = dynamic_cast<Log*>(lIV2);
                Expression* exIV1 = dynamic_cast<Expression*>(lIV1);
                Expression* exIV2 = dynamic_cast<Expression*>(lIV2);
                IrrationalNumber* iRNIV1 = dynamic_cast<IrrationalNumber*>(lIV1);
                IrrationalNumber* iRNIV2 = dynamic_cast<IrrationalNumber*>(lIV2);
                //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(a);
                //IrrationalFraction* iRF2 = dynamic_cast<IrrationalFraction*>(b);
                if( rNIV1 && rNIV2 ){
                    int value1 = rNIV1->getNumValue();
                    int value2 = rNIV2->getNumValue();
                    //cout<<value1<<endl;
                    //cout<<value2<<endl;
                    int finalVal = value1/value2;
                    //cout<<finalVal<<endl;
                    Value* finalRNIV = new RationalNumber(finalVal);
                    Value* logSimp = new Log(lB1, finalRNIV);
                    logSimp->printInfo();
                    //cout<<endl;
                    return logSimp;
                }
            }
        }
        /*else if(lB1 != lB2){
            Value* exp1 = new Expression(l1, l2, '+');
            return exp1;
        }*/
    }
    if(rN1 && rN2){
        int num1 = rN1->getNumValue();
        int num2 = rN2->getNumValue();
        int numSub = num1 - num2;
        Value* Num = new RationalNumber(numSub);
        //cout<<numAdded<<endl;
        return Num;
    }
    if((f1 && rN1) ||  (f1 && rN2) || (f2 && rN1) || (f2 && rN2) ){
        if( f1 && rN1 ){
            int numerFN = rN1->getNumValue();
            RationalFraction* fN2 = new RationalFraction(numerFN,1);
            int n1 = f1->getNumerator() * fN2->getDenominator();
            int n2 = fN2->getNumerator() * f1->getDenominator();
            int d = f1->getDenominator() * fN2->getDenominator();
            Value* f3 = new RationalFraction(n1-n2,d);
			f3 = f3->simplify();
            return f3;
        }
        if( f1 && rN2 ){
            int numerFN = rN2->getNumValue();
            RationalFraction* fN2 = new RationalFraction(numerFN,1);
            int n1 = f1->getNumerator() * fN2->getDenominator();
            //cout<<"N1: "<<n1<<endl;
            int n2 = fN2->getNumerator() * f1->getDenominator();
            //cout<<"N2: "<<n2<<endl;
            int d = f1->getDenominator() * fN2->getDenominator();
            //cout<<"d: "<<d<<endl;
            Value* f3 = new RationalFraction(n1-n2,d);
			f3 = f3->simplify();
            return f3;
        }
        if( f2 && rN1 ){
            int numerFN = rN1->getNumValue();
            RationalFraction* fN2 = new RationalFraction(numerFN,1);
            int n1 = f2->getNumerator() * fN2->getDenominator();
            //cout<<"N1: "<<n1<<endl;
            int n2 = fN2->getNumerator() * f2->getDenominator();
            //cout<<"N2: "<<n2<<endl;
            int d = f2->getDenominator() * fN2->getDenominator();
            //cout<<"d: "<<d<<endl;
            Value* f3 = new RationalFraction(n1-n2,d);
			f3 = f3->simplify();
            return f3;
        }
        if( f2 && rN2 ){
            int numerFN = rN2->getNumValue();
            RationalFraction* fN2 = new RationalFraction(numerFN,1);
            int n1 = f2->getNumerator() * fN2->getDenominator();
            //cout<<"N1: "<<n1<<endl;
            int n2 = fN2->getNumerator() * f2->getDenominator();
            //cout<<"N2: "<<n2<<endl;
            int d = f2->getDenominator() * fN2->getDenominator();
            //cout<<"d: "<<d<<endl;
            Value* f3 = new RationalFraction(n1-n2,d);
			f3 = f3->simplify();
            return f3;
        }
    }

	if((rN1 && f1) ||  (rN2 && f1) || (rN1 && f2) || (rN2 && f2) ){
        if( rN1 && f1 ){
            int numerFN = rN1->getNumValue();
            RationalFraction* fN2 = new RationalFraction(numerFN,1);
            int n1 = f1->getNumerator() * fN2->getDenominator();
            int n2 = fN2->getNumerator() * f1->getDenominator();
            int d = f1->getDenominator() * fN2->getDenominator();
            Value* f3 = new RationalFraction(n1-n2,d);
			f3 = f3->simplify();
            return f3;
        }
        if( rN2 && f1 ){
            int numerFN = rN2->getNumValue();
            RationalFraction* fN2 = new RationalFraction(numerFN,1);
            int n1 = f1->getNumerator() * fN2->getDenominator();
            //cout<<"N1: "<<n1<<endl;
            int n2 = fN2->getNumerator() * f1->getDenominator();
            //cout<<"N2: "<<n2<<endl;
            int d = f1->getDenominator() * fN2->getDenominator();
            //cout<<"d: "<<d<<endl;
            Value* f3 = new RationalFraction(n1-n2,d);
			f3 = f3->simplify();
            return f3;
        }
        if( rN1 && f2 ){
            int numerFN = rN1->getNumValue();
            RationalFraction* fN2 = new RationalFraction(numerFN,1);
            int n1 = f2->getNumerator() * fN2->getDenominator();
            //cout<<"N1: "<<n1<<endl;
            int n2 = fN2->getNumerator() * f2->getDenominator();
            //cout<<"N2: "<<n2<<endl;
            int d = f2->getDenominator() * fN2->getDenominator();
            //cout<<"d: "<<d<<endl;
            Value* f3 = new RationalFraction(n1-n2,d);
			f3 = f3->simplify();
            return f3;
        }
        if( rN2 && f2 ){
            int numerFN = rN2->getNumValue();
            RationalFraction* fN2 = new RationalFraction(numerFN,1);
            int n1 = f2->getNumerator() * fN2->getDenominator();
            //cout<<"N1: "<<n1<<endl;
            int n2 = fN2->getNumerator() * f2->getDenominator();
            //cout<<"N2: "<<n2<<endl;
            int d = f2->getDenominator() * fN2->getDenominator();
            //cout<<"d: "<<d<<endl;
            Value* f3 = new RationalFraction(n1-n2,d);
			f3 = f3->simplify();
            return f3;
        }
    }
	
    if((f1 && l2) || (f1 && l1) || (f2 && l1) || (f2 && l2)){
        if(f1 && l1){
            Value* exp1 = new Expression(f1, l1, '-');
            return exp1;
        }
        if(f1 && l2){
            Value* exp1 = new Expression(f1, l2, '-');
            return exp1;
        }
        if(f2 && l1){
            Value* exp1 = new Expression(f2, l1, '-');
            return exp1;
        }
        if(f2 && l2){
            Value* exp1 = new Expression(f2, l2, '-');
            return exp1;
        }
    }


    if((rN1 && l1) || (rN2 && l1) || (rN1 && l2) || (rN2 && l2)){
        if(rN1 && l1){
            Value* exp1 = new Expression(rN1, l1, '-');
            return exp1;
        }
        if(rN1 && l2){
            Value* exp1 = new Expression(rN1, l2, '-');
            return exp1;
        }
        if(rN2 && l1){
            Value* exp1 = new Expression(rN2, l1, '-');
            return exp1;
        }
        if(rN2 && l2){
            Value* exp1 = new Expression(rN2, l2, '-');
        }
    }


   if(iRN1 && iRN2){
        if(iRN1->getIRNumValue() == iRN2->getIRNumValue()){
        	int coef = iRN1->coefficient - iRN2->coefficient;
        	IrrationalNumber* iRN3 = new IrrationalNumber(coef, iRN1->getIRNumValue());
        	return iRN3->simplify();
        }
        else{
	    Expression* exp1 = new Expression(iRN1, iRN2, '-');
        return exp1;
        }
   }
   if((iRN1 && rN2) || (iRN2 && rN1)){
               if(iRN1 && rN2){
            	   if(!rN2->getNumValue() == 0) {
            		   Expression* exp1 = new Expression(iRN1, rN2, '-');
                   	   return exp1;
            	   }
            	   else return iRN1->simplify();
               }
               if(iRN2 && rN1){
            	   if(!rN1->getNumValue() == 0) {
            		   Expression* exp1 = new Expression(rN1, iRN2, '-');
                   	   return exp1->simplify();
            	   }
            	   else {
            		   IrrationalNumber* iRN = new IrrationalNumber(iRN2->coefficient * -1, iRN2->getIRNumValue());
            		   return iRN->simplify();
            	   }
               }
           }
   if((iRN1 && f2) || (iRN2 && f1)){
                  if(iRN1 && f2){
                      Expression* exp1 = new Expression(iRN1, f2, '-');
                      return exp1;
                  }
                  if(f1 && iRN2){
                      Expression* exp1 = new Expression(f1, iRN2, '-');
                      return exp1;
                  }
              }

   if(ex1 && iRN2) {
	   if(ex1->getIrrational(ind,iRN2->getIRNumValue())) {
		   Value* v = subtract(ex1->get(ind), iRN2);
		   ex1->popOffAt(ind);
		   ex1->addVal(v);
	   }
	   else {
		   Value* v = subtract(zero, iRN2);
		   ex1->addVal(v);
	   }
	   return ex1->simplify();
   }
   
   if(iRN1 && ex2){
	   ex2->makeNegative();
	   if(ex2->getIrrational(ind, iRN1->getIRNumValue())) {
		   Value* v = Add::add(iRN1, ex2->get(ind));
		   ex2->popOffAt(ind);
		   ex2->addVal(v);
		}
	   else ex2->addVal(iRN1);
	   return ex2->simplify();
   }
   

	if(ex1 && ex2){
		Value* newEx = ex1;
		ex2->minusToPlus();
		ex2->makeNegative();

		cout << endl << "ex&&ex subtraction not working properly until Hayden fixes RPN ~" << endl;

		for(int i = 0; i < ex2->size(); i++) {
		   newEx = Add::add(newEx, ex2->get(i));
		}
		return newEx->simplify();
	}

	if(ex1 && f2){
		if(ex1->getRational(ind)) {
			Value* v = subtract(ex1->get(ind), f2);
			ex1->popOffAt(ind);
			ex1->addVal(v);
		}
		else {
			RationalFraction* rF = new RationalFraction(f2->getNumerator() * -1, f2->getDenominator());
			ex1->addVal(rF);
		}
		return ex1->simplify();
	}
	if(f1 && ex2){
		ex2->makeNegative();

		if(ex1->getRational(ind)) {
			Value* v = Add::add(f1, ex2->get(ind));
			ex2->popOffAt(ind);
			ex2->addVal(v);
		}
		else {
			ex2->addVal(f1);
		}
		return ex2->simplify();
	}

	if(ex1 && rN2){
		if(ex1->getRational(ind)) {
			Value* v = subtract(ex1->get(ind),rN2);
			ex1->popOffAt(ind);
			ex1->addVal(v);
		}
		else {
			RationalNumber* rN = new RationalNumber(rN2->getNumValue() * -1);
			ex1->addVal(rN2);
		}
		return ex1->simplify();
	}

	if(ex2 && rN1){
		ex2->makeNegative();

		if(ex2->getRational(ind)) {
			Value* v = Add::add(rN1, ex2->get(ind));
			ex2->popOffAt(ind);
			ex2->addVal(v);
		}
		else {
			ex2->addVal(rN2);
		}
		return ex2->simplify();
	}

   if(sqrA && sqrB){
        Value* sqrAInside = sqrA->getNum2();
        Value* sqrBInside = sqrB->getNum2();
        RationalFraction* insideRTrF1 = dynamic_cast<RationalFraction*>(sqrAInside);
        RationalFraction* insideRTrF2 = dynamic_cast<RationalFraction*>(sqrBInside);
        Log* insideLog1 = dynamic_cast<Log*>(sqrAInside);
        Log* insideLog2 = dynamic_cast<Log*>(sqrBInside);
        RationalNumber* insideRN1 = dynamic_cast<RationalNumber*>(sqrAInside);
        RationalNumber* insideRN2 = dynamic_cast<RationalNumber*>(sqrBInside);
        Expression* insideEX1 = dynamic_cast<Expression*>(sqrAInside);
        Expression* insideEX2 = dynamic_cast<Expression*>(sqrBInside);
        IrrationalNumber* insideIRN1 = dynamic_cast<IrrationalNumber*>(sqrAInside);
        IrrationalNumber* insideIRN2 = dynamic_cast<IrrationalNumber*>(sqrBInside);
        //IrrationalFraction* insideIrF1 = dynamic_cast<IrrationalFraction*>(sqrAInside);
        //IrrationalFraction* insideIrF2 = dynamic_cast<IrrationalFraction*>(sqrBInside);
        SquareRoot* insideSqr1 = dynamic_cast<SquareRoot*>(sqrAInside);
        SquareRoot* insideSqr2 = dynamic_cast<SquareRoot*>(sqrBInside);
        NthRoot* insideNrt1 = dynamic_cast<NthRoot*>(sqrAInside);
        NthRoot* insideNrt2 = dynamic_cast<NthRoot*>(sqrBInside);
        if((insideRN1 && insideRN2) || (insideRTrF1 == insideRTrF2) || (insideEX1 == insideEX2) || (insideSqr1 == insideSqr2) ||
           (insideIRN1 == insideIRN2) || (insideLog1 == insideLog2)){
            int insideNum1 = insideRN1->getNumValue();
            int insideNum2 = insideRN2->getNumValue();
            if(insideNum1 == insideNum2){
                int coefrF1 = sqrA->getCoefficient();
                int coefrF2 = sqrB->getCoefficient();
                int simpCoeff = coefrF1 - coefrF2;
                Value* addedRoot = new SquareRoot(simpCoeff, sqrAInside);
            }
        }
        else if(insideRTrF1 && insideRTrF2){
            int insideNumerator1 = insideRTrF1->getNumerator();
            int insideDenominator1 = insideRTrF1->getDenominator();
            int insideNumerator2 = insideRTrF2->getNumerator();
            int insideDenominator2 = insideRTrF2->getDenominator();
            if((insideNumerator1 == insideNumerator2) && (insideDenominator1 == insideDenominator2)){
                int coefrF1 = sqrA->getCoefficient();
                int coefrF2 = sqrB->getCoefficient();
                int simpCoeff = coefrF1 - coefrF2;
                Value* addedRoot = new SquareRoot(simpCoeff, sqrAInside);
            }
        }
   }

   if(nrtA && nrtB) {
	   cout << "Subtracting NthRoots is currently unsupported." << endl;
	   return nrtA;
   }
   if(nrtA && rN2) {
	   Expression* exp = new Expression(nrtA, rN2, '-');
	   return exp->simplify();
   }
   if(rN1 && nrtB) {
	   Expression* exp = new Expression(rN1, nrtB, '-');
	   return exp->simplify();
   }
   if(f1 && nrtB) {
	   Expression* exp = new Expression(f1, nrtB, '-');
	   return exp->simplify();
   }
   if(nrtA && f2) {
	   Expression* exp = new Expression(nrtA, f2, '-');
	   return exp->simplify();
   }
}

bool Subtract::isEqual(Value* a, Value* b){
     RationalNumber* rnTestA = dynamic_cast<RationalNumber*>(a);
     RationalNumber* rnTestB = dynamic_cast<RationalNumber*>(b);
     RationalFraction* rfTestA = dynamic_cast<RationalFraction*>(a);
     RationalFraction* rfTestB = dynamic_cast<RationalFraction*>(b);
     Log* logTestA = dynamic_cast<Log*>(a);
     Log* logTestB = dynamic_cast<Log*>(b);
     Expression* exTestA = dynamic_cast<Expression*>(a);
     Expression* exTestB = dynamic_cast<Expression*>(b);
     IrrationalNumber* inTestA = dynamic_cast<IrrationalNumber*>(a);
     IrrationalNumber* inTestB = dynamic_cast<IrrationalNumber*>(b);
     //IrrationalFraction* irfTestA = dynamic_cast<IrrationalFraction*>(a);
     //IrrationalFraction* irfTestB = dynamic_cast<IrrationalFraction*>(b);
     if(rnTestA && rnTestB){
         Value* num1 = new RationalNumber();
         Value* num2 = new RationalNumber();
         num1 = a;
         num2 = b;
         if(num1->getNum1() == num2->getNum1()){
             return true;
         }
     }
     else if(rfTestA && rfTestB){
     	Value* num1 = new RationalFraction();
     	Value* num2 = new RationalFraction();
     	num1 = a;
     	num2 = b;
     	if(num1->getNum1() == num2->getNum1() && num2->getNum2() == num1->getNum2()){
     		return true;
     		}
     	}
     else if(logTestA && logTestB){
     	Value* num1 = new Log();
     	Value* num2 = new Log();
     	num1 = a;
     	num2 = b;
     	if(num1->getNum1() == num2->getNum1() && num2->getNum2() == num1->getNum2()){
     	    return true;
     	    }
     	}
     else if(exTestA && exTestB) {
     	Value* num1 = new Expression();
     	Value* num2 = new Expression();
     	num1 = a;
     	num2 = b;
     	if(num1->getNum1() == num2->getNum1() && num2->getNum2() == num1->getNum2()){
     	    return true;
     	    }
     	}
     else if(inTestA && inTestB) {
     	Value* num1 = new IrrationalNumber();
     	Value* num2 = new IrrationalNumber();
     	num1 = a;
     	num2 = b;
     	if(num1->getNum1() == num2->getNum1()){
     		return true;
     	    }
     	}
    /* else if(irfTestA && irfTestB) {
     	Value* num1 = new RationalFraction();
     	Value* num2 = new RationalFraction();
     	num1 = a;
     	num2 = b;
     	if(num1->getNum1() == num2->getNum1() && num2->getNum2() == num1->getNum2()){
     		return true;
     	    }
     	}*/
     else return false;

}







