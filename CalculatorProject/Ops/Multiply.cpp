#include <Multiply.h>
#include <Fraction.h>
#include <RationalFraction.h>
#include <Log.h>
#include <Expression.h>
#include <Number.h>
#include <RationalNumber.h>
#include <IrrationalNumber.h>
#include <NthRoot.h>
#include <sstream>
#include <Add.h>

/*
 *  Created on: Apr 5, 2014
 *      Author: Kevin
 */
Multiply::Multiply()
{

}
Multiply::~Multiply()
{

}

Value* Multiply::multiply(Value* a, Value* b) {
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
    NthRoot* nrt1 = dynamic_cast<NthRoot*>(a);
    NthRoot* nrt2 = dynamic_cast<NthRoot*>(b);

    //Type Checks the Initial Values passed into the function
    if(rN1 && !rN2 || !rN1 && rN2){
    	if(rN1){
    		if(rN1->getNumValue() == 0){
    			Value* zero = new RationalNumber(0);
    			return zero;
    		}
    	}
    	if(rN2){
    		if(rN2->getNumValue() == 0){
    			Value* zero = new RationalNumber(0);
    			return zero;
    		}
    	}
    }
    if(f1 && f2){
        int n = f1->getNumerator() * f2->getNumerator();
        //cout<<"N: "<<n<<endl;
        int d = f1->getDenominator() * f2->getDenominator();
        //cout<<"D: "<<d<<endl;
        Value* f2 = new RationalFraction(n,d);
        return f2;

        //If the Values are Rational Fractions, the program will Multiply them together.
    }

    //I did not see log multiplication anywhere in the specs.
    
    if(l1 && l2){
    	cout << "Multiplication between logs is currently unsupported." << endl;
    return l2;}

    	/*
        Value* lB1 = l1->getNum1();
        Value* lB2 = l2->getNum1();
        Value* lIV1 = l1->getNum2();
        Value* lIV2 = l2->getNum2();

        //If both initial values are logs, the program will run getNum1 and getNum2, which will get the
        //bases and inside values of the logs. The functions return Value pointers to objects, and the base
        //and the base and inside values are stored as Value pointer objects that we can utilize in this method.
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

            //The program runs the method to check to see if the bases are the same, because
            //if the bases are the same, then the program will need to actually combine the
            //two logs together. If they are, the method will typecheck the bases. So for example,
            //if the bases are both Rational Numbers, the program will perform the operation for rational numbers.
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

                //Since we determined that the two bases are both Rational Numbers, we actually
                //will need to combine the Inside Values. However, that process will be different
                //depending on what Values are stored inside the logs. So, for example, if both
                //are Rational Numbers, the numbers will simply be multiplied together and the combined
                //log will be created. However, if one is a Rational Number and one is an Irrational Number,
                //we need to perform a different set of steps to Multiply them together.
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
                    //Since we determined that the inside values are both rational numbers, they will be
                    //returned and multiplied together. A new log object will be created which has the same
                    //base and the inside value equivalent to the result of the multiplication.
                }
            }
        }
        /*else if(lB1 != lB2){
            Value* exp1 = new Expression(l1, l2, '+');
            return exp1;
        }*/

        //If the bases are different, we just return an expression with the two logs, since there's nothing
        //we can do with addition. With Division, however, we will need to use the change of base formula and
        //there will be actual simplification.
   // }

    if(rN1 && rN2){
        int num1 = rN1->getNumValue();
        int num2 = rN2->getNumValue();
        int numMultiplied = num1 * num2;
        Value* productNum = new RationalNumber(numMultiplied);
        //cout<<numMultiplied<<endl;
        return productNum;
    }
    //If both of the values to be multiplied are Rational Numbers, all we need to do is get their values,
    //Multiply them, and return a RationalNumber object equivalent to the product.

    if((f1 && rN2) || (f2 && rN1)){

        //This is what is performed if we have any combination of a Rational Fraction and a Rational Number.
        //The following if statements are called depending on which combination is entered (so if Value 1 is
        //a rational number and B is a rational Fraction, rN1 && f2 will be performed).
        if( f1 && rN2 ){
            int numerFN = rN2->getNumValue();
            RationalFraction* fN2 = new RationalFraction(numerFN,1);
            int n = f1->getNumerator() * fN2->getNumerator();
            //cout<<"N: "<<n<<endl;
            int d = f1->getDenominator() * fN2->getDenominator();
            //cout<<"d: "<<d<<endl;
            Value* f3 = new RationalFraction(n,d);
            return f3->simplify();
        }
        if( f2 && rN1 ){
            int numerFN = rN1->getNumValue();
            RationalFraction* fN2 = new RationalFraction(numerFN,1);
            int n = f2->getNumerator() * fN2->getNumerator();
            //cout<<"N: "<<n<<endl;
            int d = f2->getDenominator() * fN2->getDenominator();
            //cout<<"d: "<<d<<endl;
            Value* f3 = new RationalFraction(n,d);
            return f3->simplify();
        }

        //All of the above steps are the same with slightly different Value names.
        //Essentially, what happens is the Rational Number is converted into a Rational Fraction
        //with the numerator being the value of the Number and the denominator being 1. So,
        //if we input 1/2 * 6, it will become 1/2 * 6/1, and then the same process as Rational Fraction
        //multiplication will occur.
    }
    
    if((f1 && l2) || (l1 && f2)){
    	cout << "Multiplication between fraction and log is currently unsupported." << endl;
    	if(f1 && l2)
	   {return l2;}
	if(l1 && f2)
	   {return f2;}
    }

    //All of the above is the combination of a rational fraction and an expression. Expression types will not INITALLY
    //be passed into the method, and they will be solved later on anyways, so all we need to do now is return an expression
    //with both values. No need to worry about the actual simplification right now.

    if (l1 && rN2) {
    	return new Log(l1->getCoefficient() * rN2->getNumValue(), l1->getNum1(), l1->getNum2());
    }
    if (rN1 && l2) {
    	return multiply(b,a);
    }

    	/*
        if(rN1 && l1){
            Value* exp1 = new Expression(rN1, l1, '*');
            return exp1;
        }
        if(rN1 && l2){
            Value* exp1 = new Expression(rN1, l2, '*');
            return exp1;
        }
        if(rN2 && l1){
            Value* exp1 = new Expression(rN2, l1, '*');
            return exp1;
        }
        if(rN2 && l2){
            Value* exp1 = new Expression(rN2, l2, '*');
        }
    }
    */

    //The above handles Rational Numbers and Logs. Nothing else needs to be done. We could call exp->simplify here if we wanted,
    //but it wouldn't make a difference if we did it at the end of calculate or in here. It's not programmed in because it isn't
    //written yet, and I really didn't want to get too far ahead of myself.

    //do we need to be able to foil out expressions in this class? Or will that be handled somewhere else?

	if(iRN1 && iRN2){
		if(iRN1->getIRNumValue()==iRN2->getIRNumValue()){

			Value* newExpo = Add::add(iRN1->getNum2(),iRN2->getNum2());

			// Multiply coefficients
			int coef = iRN1->coefficient * iRN2->coefficient;
			IrrationalNumber* iRN3 = new IrrationalNumber(coef, iRN1->getIRNumValue(), newExpo->simplify());
			return iRN3;
           }
           else{
        	   cout << "Multiplying Irrationals of different types is currently unsupported." << endl;
        	   return iRN1;
           }
      }
      if((iRN1 && rN1) || (iRN1 && rN2) || (iRN2 && rN1) || (iRN2 && rN2)){
                  if(iRN1 && rN2){
                	  int coeff = rN2->getNumValue() * iRN1->coefficient;
                      IrrationalNumber* iRN3 = new IrrationalNumber(coeff,iRN1->getIRNumValue(),iRN1->getNum2());
                      return iRN3;
                  }
                  if(iRN2 && rN1){
                	  int coeff = rN1->getNumValue() * iRN2->coefficient;
                      IrrationalNumber* iRN3 = new IrrationalNumber(coeff,iRN2->getIRNumValue(), iRN2->getNum2());
                      return iRN3;
                  }
              }
      if((iRN1 && f2) || (iRN2 && f1)){
    	  cout << "IrrationalNumbers currently only support integer coefficients." << endl;
			 if(iRN1 && f2){
				 return new IrrationalNumber(f2->getNumerator() * iRN1->coefficient / f2->getDenominator(), iRN1->getIRNumValue(), iRN1->getNum2());
			 }
			 if(iRN2 && f1){
				 return multiply(b,a);
			 }
		 }

   //If both are IrrationalNumbers, we really can't just tack on a coefficient and call it a done deal, so
   //we create an Expression that stores the two. So if we have e * e, we will get an expression that calls that.
   //In simplifying the expression, we will have to find a way to know that e*e = e^2, which we may have to do by
   //removing common factors or something. Or I'll have to add to this. I don't know. There is a getIRNumValue method
   //and if they're equivalent, add the coefficients.

   //THE ABOVE STATEMENT IS NOW INCORRECT
   //Expression no longer supports * or /
   //We will now be taking care of this using Value* coefficients for irrational numbers
   //If you want to multiply an expression then set the expression's coefficient to the value
   //In simplifying, I will distribute that coefficient onto the values inside the expression

   if( ex1 || ex2 ){

        if(ex1 && ex2){
        	Value* v2;
            Value* v = multiply(ex2->get(ex2->size() - 1), ex1);
            for(int i = ex2->size() - 2; i >= 0; i--) {
            	v = Add::add(multiply(ex2->get(i), ex1), v);
            }
            return v->simplify();
        }

        if(ex1 && rN2) {
        	Expression* ex = new Expression(*ex1);
        	for(int i = ex->size()-1; i >= 0; i--) {
        		Value* v = multiply(ex->get(i),rN2);
        		ex->popOffAt(i);
        		ex->addVal(v);
        	}
        	return ex->simplify();
        }

        if(rN1 && ex2) {
        	return multiply(b,a);
        }

		if(ex1 && f2){
			Expression* ex = new Expression(*ex1);
        	for(int i = ex->size()-1; i >= 0; i--) {
        		Value* v = multiply(ex->get(i),f2);
        		ex->popOffAt(i);
        		ex->addVal(v);
        	}
        	return ex->simplify();
		}

		if(ex2 && f1){
			return multiply(b,a);
		}

        if(ex1 && iRN2) {
        	Expression* ex = new Expression(*ex1);
        	for(int i = ex->size()-1; i >= 0; i--) {
        		Value* v = multiply(ex->get(i),iRN2);
        		ex->popOffAt(i);
        		ex->addVal(v);
        	}
        	return ex->simplify();
        }

        if(iRN1 && ex2) {
        	return multiply(b,a);
        }

   }
   
   if( nrt1 && nrt2 ){
   	if(isEqual(nrt1->getNum2(), nrt2->getNum2())) {
   		int newCoefficient = nrt1->getCoefficient() * nrt2->getCoefficient();
   		Value* inside1 = new RationalNumber();
   		Value* inside2 = new RationalNumber();
   		inside1 = nrt1->getNum1();
   		inside2 = nrt2->getNum1();
   		RationalNumber* newInsideVal1 = dynamic_cast<RationalNumber*>(inside1);
   		RationalNumber* newInsideVal2 = dynamic_cast<RationalNumber*>(inside2);
   		int insideNumber1 = newInsideVal1->getNumValue();
   		int insideNumber2 = newInsideVal2->getNumValue();
   		int multInsideNumber = insideNumber1 * insideNumber2;
   		Value* preSimpInside = new RationalNumber(multInsideNumber);
   		Value* preSimpRoot = new NthRoot(newCoefficient, preSimpInside, nrt1->getNum2() );
   		Value* finalSimpRoot = new NthRoot();
   		finalSimpRoot = preSimpRoot->simplify();
   		RationalNumber* finalRN = dynamic_cast<RationalNumber*>(finalSimpRoot);
   		if(finalRN){
   			int finalNum = newCoefficient * finalRN->getNumValue();
   			Value* finalSimplifiedNum = new RationalNumber(finalNum);
   			return finalSimplifiedNum;
   		}
   		else{
   			return finalSimpRoot;
   		}
   		//finalSimpRoot->printInfo();
   		
   	}
   }

   if(nrt1 && rN2){
	   NthRoot* nrt = new NthRoot(rN2->getNumValue() * nrt1->getCoefficient() , nrt1->getNum1(), nrt1->getNum2());
	   return nrt->simplify();
   }

   else if(nrt2 && rN1){
	   return multiply(b,a);
   }

   if(nrt1 && f2){
	   cout << "NthRoot does not support fractional coefficients." << endl;
	   return nrt1;
   }

   else if(nrt2 && f1){
	   cout << "NthRoot does not support fractional coefficients." << endl;
	  	   return f1;
   }

    //If an Expression is used at all, the Value created is always going to be an expression. Why? Because that's the only one
    //that simplify isn't very simple to do.

    //Multiplying roots is going to be a huge bitch. I will have to figure ut how to do this sometime tonight or tomorrow i guess.
   // I am completely open to suggestions though.
}


bool Multiply::isEqual(Value* a, Value* b){
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
        if(rnTestA->getNumValue() == rnTestB->getNumValue()){
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
