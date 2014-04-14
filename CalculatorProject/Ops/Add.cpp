#include <Add.h>
#include <Fraction.h>
#include <RationalFraction.h>
#include <Log.h>
#include <Expression.h>
#include <Number.h>
#include <RationalNumber.h>
#include <IrrationalNumber.h>
#include <SquareRoot.h>
#include <NthRoot.h>
#include <IrrationalFraction.h>
#include <sstream>

Add::Add()
{

}

Add::~Add()
{

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
    SquareRoot* sqrA = dynamic_cast<SquareRoot*>(a);
    SquareRoot* sqrB = dynamic_cast<SquareRoot*>(b);
    NthRoot* nrtA = dynamic_cast<NthRoot*>(a);
    NthRoot* nrtB = dynamic_cast<NthRoot*>(b);

    //Type Checks the Initial Values passed into the function
    if(f1 && f2){
        int n1 = f1->getNumerator() * f2->getDenominator();
        //cout<<"N1: "<<n1<<endl;
        int n2 = f2->getNumerator() * f1->getDenominator();
        //cout<<"N2: "<<n2<<endl;
        int d = f1->getDenominator() * f2->getDenominator();
        //cout<<"D: "<<d<<endl;
        Value* f3 = new RationalFraction(n1+n2,d);
        f3->simplify();
        return f3;

        //If the Values are Rational Fractions, the program will add them together.
    }
    if(l1 && l2){
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
            SquareRoot* sqrA = dynamic_cast<SquareRoot*>(a);
            SquareRoot* sqrB = dynamic_cast<SquareRoot*>(b);
            NthRoot* nrtA = dynamic_cast<NthRoot*>(a);
            NthRoot* nrtB = dynamic_cast<NthRoot*>(b);

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
                SquareRoot* sqrA = dynamic_cast<SquareRoot*>(a);
                SquareRoot* sqrB = dynamic_cast<SquareRoot*>(b);
                NthRoot* nrtA = dynamic_cast<NthRoot*>(a);
                NthRoot* nrtB = dynamic_cast<NthRoot*>(b);

                //Since we determined that the two bases are both Rational Numbers, we actually
                //will need to combine the Inside Values. However, that process will be different
                //depending on what Values are stored inside the logs. So, for example, if both
                //are Rational Numbers, the numbers will simply be multiplied together and the combined
                //log will be created. However, if one is a Rational Number and one is an Irrational Number,
                //we need to perform a different set of steps to multiply them together.
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
    }
    if(rN1 && rN2){
        int num1 = rN1->getNumValue();
        int num2 = rN2->getNumValue();
        int numAdded = num1 + num2;
        Value* summedNum = new RationalNumber(numAdded);
        //cout<<numAdded<<endl;
        return summedNum;
    }
    //If both of the values to be added are Rational Numbers, all we need to do is get their values,
    //add them, and return a RationalNumber object equivalent to the sum.

    if((f1 && rN1) || (f1 && rN2) || (f2 && rN1) || (f2 && rN2) ){

        //This is what is performed if we have any combination of a Rational Fraction and a Rational Number.
        //The following if statements are called depending on which combination is entered (so if Value 1 is
        //a rational number and B is a rational Fraction, rN1 && f2 will be performed).
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

        //All of the above steps are the same with slightly different Value names.
        //Essentially, what happens is the Rational Number is converted into a Rational Fraction
        //with the numerator being the value of the Number and the denominator being 1. So,
        //if we input 1/2 + 6, it will become 1/2 + 6/1, and then the same process as Rational Fraction
        //addition will occur.
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

    //All of the above is the combination of a rational fraction and an expression. Expression types will not INITALLY
    //be passed into the method, and they will be solved later on anyways, so all we need to do now is return an expression
    //with both values. No need to worry about the actual simplification right now.

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

    //The above handles Rational Numbers and Logs. Nothing else needs to be done. We could call exp->simplify here if we wanted,
    //but it wouldn't make a difference if we did it at the end of calculate or in here. It's not programmed in because it isn't
    //written yet, and I really didn't want to get too far ahead of myself.

   /* if(ex1 && ex2){
        Value* exp1 = new Expression(ex1, ex2, '+');
        return exp1;
    }*/

    //If both types are Expressions, congrats, just concatenate them into a new expression. Done deal.

   if(iRN1 && iRN2){
        //Value* exp1 = new Expression(iRN1, iRN2, '+');
        //return exp1;
   }

   //If both are IrrationalNumbers, we really can't just tack on a coefficient and call it a done deal, so
   //we create an Expression that stores the two. So if we have e + e, we will get an expression that calls that.
   //In simplifying the expression, we will have to find a way to know that e+e = 2e, which we may have to do by
   //removing common factors or something. Or I'll have to add to this. I don't know. There is a getIRNumValue method
   //and if they're equivalent, add the coefficients.

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

   if(sqrA && sqrB){
        Value* sqrAInside = sqrA->getNum2();
        Value* sqrBInside = sqrB->getNum2();
        RationalFraction* insideRTF1 = dynamic_cast<RationalFraction*>(sqrAInside);
        RationalFraction* insideRTF2 = dynamic_cast<RationalFraction*>(sqrBInside);
        Log* insideLog1 = dynamic_cast<Log*>(sqrAInside);
        Log* insideLog2 = dynamic_cast<Log*>(sqrBInside);
        RationalNumber* insideRN1 = dynamic_cast<RationalNumber*>(sqrAInside);
        RationalNumber* insideRN2 = dynamic_cast<RationalNumber*>(sqrBInside);
        Expression* insideEX1 = dynamic_cast<Expression*>(sqrAInside);
        Expression* insideEX2 = dynamic_cast<Expression*>(sqrBInside);
        IrrationalNumber* insideIRN1 = dynamic_cast<IrrationalNumber*>(sqrAInside);
        IrrationalNumber* insideIRN2 = dynamic_cast<IrrationalNumber*>(sqrBInside);
        //IrrationalFraction* insideIRF1 = dynamic_cast<IrrationalFraction*>(sqrAInside);
        //IrrationalFraction* insideIRF2 = dynamic_cast<IrrationalFraction*>(sqrBInside);
        SquareRoot* insideSqr1 = dynamic_cast<SquareRoot*>(sqrAInside);
        SquareRoot* insideSqr2 = dynamic_cast<SquareRoot*>(sqrBInside);
        NthRoot* insideNrt1 = dynamic_cast<NthRoot*>(sqrAInside);
        NthRoot* insideNrt2 = dynamic_cast<NthRoot*>(sqrBInside);
        if((insideRN1 && insideRN2) || (insideRTF1 == insideRTF2) || (insideEX1 == insideEX2) || (insideSqr1 == insideSqr2) ||
           (insideIRN1 == insideIRN2) || (insideLog1 == insideLog2)){
            int insideNum1 = insideRN1->getNumValue();
            int insideNum2 = insideRN2->getNumValue();
            if(insideNum1 == insideNum2){
                int coeff1 = sqrA->getCoefficient();
                int coeff2 = sqrB->getCoefficient();
                int simpCoeff = coeff1 + coeff2;
                Value* addedRoot = new SquareRoot(simpCoeff, sqrAInside);
            }
        }
        else if(insideRTF1 && insideRTF2){
            int insideNumerator1 = insideRTF1->getNumerator();
            int insideDenominator1 = insideRTF1->getDenominator();
            int insideNumerator2 = insideRTF2->getNumerator();
            int insideDenominator2 = insideRTF2->getDenominator();
            if((insideNumerator1 == insideNumerator2) && (insideDenominator1 == insideDenominator2)){
                int coeff1 = sqrA->getCoefficient();
                int coeff2 = sqrB->getCoefficient();
                int simpCoeff = coeff1 + coeff2;
                Value* addedRoot = new SquareRoot(simpCoeff, sqrAInside);
            }
        }
   }

    //If an Expression is used at all, the Value created is always going to be an expression. Why? Because that's the only one
    //that simplify isn't very simple to do.

    //ROOTS WILL BE ADDED SOON, don't get your panties in a bunch guys. That's also going to involve a ton of Type-Checking, but
    //whatever, I'll make it work somehow.
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

    //This typechecks whatever to see if they're equivalent.
    if(rnTestA && rnTestB){
        Value* num1 = new RationalNumber();
        Value* num2 = new RationalNumber();
        num1 = a;
        num2 = b;
        if(num1->getNum1() == num2->getNum1()){
            return true;
        }
        //If both of the numbers we're testing are Rational Numbers, we execute this.
        //If both values stored by num1 and num2 are equivalent, return true.
    }
    else{ return false; }
}
