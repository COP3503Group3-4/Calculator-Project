#include <Add.h>

Add::Add()
{

}

Add::~Add()
{
    //dtor
}

Value* Add::add(Value* a, Value* b) {
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
    SquareRoot* sqr1 = dynamic_cast<SquareRoot*>(a);
    SquareRoot* sqr2 = dynamic_cast<SquareRoot*>(b);

    if(f1 && f2){
        int n1 = f1->getNumerator() * f2->getDenominator();
        //cout<<"N1: "<<n1<<endl;
        int n2 = f2->getNumerator() * f1->getDenominator();
        //cout<<"N2: "<<n2<<endl;
        int d = f1->getDenominator() * f2->getDenominator();
        //cout<<"D: "<<d<<endl;
        Value* f3 = new RationalFraction(n1+n2,d);
        return f3;
    }
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
                //IrrationalFraction* iRF1 = dynamic_cast<IrrationalFraction*>(a);
                //IrrationalFraction* iRF2 = dynamic_cast<IrrationalFraction*>(b);
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
            Value* exp1 = new Expression(l1, l2, '+');
            return exp1;
        }*/
    }
    if(rN1 && rN2){
        int num1 = rN1->getNumValue();
        int num2 = rN2->getNumValue();
        int numAdded = num1 + num2;
        Value* summedNum = new RationalNumber(numAdded);
        //cout<<numAdded<<endl;
        return summedNum;
    }
    if((f1 && rN1) || (f1 && rN2) || (f2 && rN1) || (f2 && rN2) ){
        if( f1 && rN1 ){
            int numerFN = rN1->getNumValue();
            RationalFraction* fN2 = new RationalFraction(numerFN,1);
            int n1 = f1->getNumerator() * fN2->getDenominator();
            int n2 = fN2->getNumerator() * f1->getDenominator();
            int d = f1->getDenominator() * fN2->getDenominator();
            Value* f3 = new RationalFraction(n1+n2,d);
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
            Value* f3 = new RationalFraction(n1+n2,d);
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
            Value* f3 = new RationalFraction(n1+n2,d);
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
            Value* f3 = new RationalFraction(n1+n2,d);
            return f3;
        }
    }
    /*if((f1 && l2) || (f1 && l1) || (f2 && l1) || (f2 && l2)){
        if(f1 && l1){
            Value* exp1 = new Expression(f1, l1, '+');
            return exp1;
        }
        if(f1 && l2){
            Value* exp1 = new Expression(f1, l2, '+');
            return exp1;
        }
        if(f2 && l1){
            Value* exp1 = new Expression(f2, l1, '+');
            return exp1;
        }
        if(f2 && l2){
            Value* exp1 = new Expression(f2, l2, '+');
            return exp1;
        }
    }*/

    /*if((rN1 && l1) || (rN2 && l1) || (rN1 && l2) || (rN2 && l2)){
        if(rN1 && l1){
            Value* exp1 = new Expression(rN1, l1, '+');
            return exp1;
        }
        if(rN1 && l2){
            Value* exp1 = new Expression(rN1, l2, '+');
            return exp1;
        }
        if(rN2 && l1){
            Value* exp1 = new Expression(rN2, l1, '+');
            return exp1;
        }
        if(rN2 && l2){
            Value* exp1 = new Expression(rN2, l2, '+');
        }
    }
    */
   /* if(ex1 && ex2){
        Value* exp1 = new Expression(ex1, ex2, '+');
        return exp1;
    }*/
   if(iRN1 && iRN2){
        if(iRN1->getIRNumValue() == iRN2->getIRNumValue()){
        	vector<Value*> vals;
        	vector<string> ops;
        	vals.push_back(iRN1);
        	vals.push_back(iRN2);
        	ops.push_back("+");
            Value* exp1 = new Expression(vals, ops);
            return exp1;
        }
   }
   /*if( ex1 || ex2 ){
        if(ex1 && ex2){
            Value* exp1 = new Expression(ex1, ex2, '+');
            return exp1;
        }
        if((ex1 && f1) || (ex1 && f2) || (ex2 && f1) || (ex2 && f2)){
            if(ex1 && f1){
                Value* exp1 = new Expression(ex1, f1, '+');
                return exp1;
            }
            if(ex1 && f2){
                Value* exp1 = new Expression(ex1, f2, '+');
                return exp1;
            }
            if(ex2 && f1){
                Value* exp1 = new Expression(ex2, f1, '+');
                return exp1;
            }
            if(ex2 && f2){
                Value* exp1 = new Expression(ex2, f2, '+');
                return exp1;
            }
        }
   }*/

}

bool Add::isEqual(Value* a, Value* b){
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
    else{ return false; }

}
