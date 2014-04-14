/*
 * divide.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: guorui
 */

#include <divide.h>
#include <typeinfo>

Divide::Divide() {}
Divide::~Divide() {}

Value* Divide::divide(Value* a, Value* b){
    ostringstream combined;
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

    if(f1 && f2){
        int n1 = f1->getNumerator();
		int n2 = f2->getNumerator();
        int d1 = f1->getDenominator();
		int d2 = f2->getDenominator();
		int n = n1 * d2;
		int d = d1 * n2;
        Value* f3 = new RationalFraction(n,d);
		f3 = f3->simplify();
        return f3;
    }
    /*
    if(l1 && l2){
        Value* lB1 = l1->getNum1();
        Value* lB2 = l2->getNum1();
        Value* lIV1 = l1->getNum2();
        Value* lIV2 = l2->getNum2();

        if(isEqual(lB1,lB2)){
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

                if( rNIV1 && rNIV2 ){
                    int value1 = rNIV1->getNumValue();
                    int value2 = rNIV2->getNumValue();
                    //cout<<value1<<endl;
                    //cout<<value2<<endl;
                    int finalVal = value1*value2;
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
            Value* exp1 = new Expression(l1, l2, '-');
            return exp1;
        }*/


   // }

    if(rN1 && rN2){
        int nn = rN1->getNumValue();
        int dd = rN2->getNumValue();
        Value* quotient = new RationalFraction(nn,dd);
        quotient = quotient->simplify();
        //quotient->printInfo();
        return quotient;
    }

    if((f1 && rN1) || (f1 && rN2) || (f2 && rN1) || (f2 && rN2) ){
        if( f1 && rN1 ){
		    int n1 = f1->getNumerator();
			int d1 = f1->getDenominator();
            int d2 = rN1->getNumValue();
            int d = d1 *d2;
            Value* f3 = new RationalFraction(n1,d);
			f3 = f3->simplify();
            return f3;
        }
        if( f1 && rN2 ){
            int n1 = f1->getNumerator();
			int d1 = f1->getDenominator();
            int d2 = rN2->getNumValue();
            int d = d1 *d2;
            Value* f3 = new RationalFraction(n1,d);
			f3 = f3->simplify();
            return f3;
        }
        if( f2 && rN1 ){
            int n1 = f2->getNumerator();
			int d1 = f2->getDenominator();
            int d2 = rN1->getNumValue();
            int d = d1 *d2;
            Value* f3 = new RationalFraction(n1,d);
			f3 = f3->simplify();
            return f3;
        }
        if( f2 && rN2 ){
            int n1 = f2->getNumerator();
			int d1 = f2->getDenominator();
            int d2 = rN2->getNumValue();
            int d = d1 *d2;
            Value* f3 = new RationalFraction(n1,d);
			f3 = f3->simplify();
            return f3;
        }
	}

	if((rN1 && f1) ||  (rN2 && f1) || (rN1 && f2) || (rN2 && f2) ){
        if( rN1 && f1 ){
            int n1 = rN1->getNumValue();
            int n2 = f1->getDenominator();
            int n = n1 * n2;
            int d = f1->getNumerator();
            Value* f3 = new RationalFraction(n,d);
			f3 = f3->simplify();
            return f3;
        }
        if( rN2 && f1 ){
            int n1 = rN2->getNumValue();
            int n2 = f1->getDenominator();
            int n = n1 * n2;
            int d = f1->getNumerator();
            Value* f3 = new RationalFraction(n,d);
			f3 = f3->simplify();
            return f3;
        }
        if( rN1 && f2 ){
            int n1 = rN1->getNumValue();
            int n2 = f2->getDenominator();
            int n = n1 * n2;
            int d = f2->getNumerator();
            Value* f3 = new RationalFraction(n,d);
			f3 = f3->simplify();
            return f3;
        }
        if( rN2 && f2 ){
            int n1 = rN2->getNumValue();
            int n2 = f2->getDenominator();
            int n = n1 * n2;
            int d = f2->getNumerator();
            Value* f3 = new RationalFraction(n,d);
			f3 = f3->simplify();
            return f3;
        }
    }


    /*if((f1 && l2) || (f1 && l1) || (f2 && l1) || (f2 && l2)){
        if(f1 && l1){
            Value* exp1 = new Expression(f1, l1, '/');
            return exp1;
        }
        if(f1 && l2){
            Value* exp1 = new Expression(f1, l2, '/');
            return exp1;
        }
        if(f2 && l1){
            Value* exp1 = new Expression(f2, l1, '/');
            return exp1;
        }
        if(f2 && l2){
            Value* exp1 = new Expression(f2, l2, '/');
            return exp1;
        }
    }*/

    /*if((rN1 && l1) || (rN2 && l1) || (rN1 && l2) || (rN2 && l2)){
        if(rN1 && l1){
            Value* exp1 = new Expression(rN1, l1, '/');
            return exp1;
        }
        if(rN1 && l2){
            Value* exp1 = new Expression(rN1, l2, '/');
            return exp1;
        }
        if(rN2 && l1){
            Value* exp1 = new Expression(rN2, l1, '/');
            return exp1;
        }
        if(rN2 && l2){
            Value* exp1 = new Expression(rN2, l2, '/');
        }
    }
    */
   /* if(ex1 && ex2){
        Value* exp1 = new Expression(ex1, ex2, '/');
        return exp1;
    }*/

   if(iRN1 && iRN2){
        Value* exp1 = new Expression(iRN1, iRN2, '/');
        return exp1;
   }

   /*if( ex1 || ex2 ){
        if(ex1 && ex2){
            Value* exp1 = new Expression(ex1, ex2, '/');
            return exp1;
        }
        if((ex1 && f1) || (ex1 && f2) || (ex2 && f1) || (ex2 && f2)){
            if(ex1 && f1){
                Value* exp1 = new Expression(ex1, f1, '/');
                return exp1;
            }
            if(ex1 && f2){
                Value* exp1 = new Expression(ex1, f2, '/');
                return exp1;
            }
            if(ex2 && f1){
                Value* exp1 = new Expression(ex2, f1, '/');
                return exp1;
            }
            if(ex2 && f2){
                Value* exp1 = new Expression(ex2, f2, '/');
                return exp1;
            }
        }
   }*/
}