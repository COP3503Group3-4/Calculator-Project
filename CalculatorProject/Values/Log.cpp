#include <Log.h>

Log::Log(Value* b, Value* insideVal)
{
    base = b;
    insideValue = insideVal;
}
Log::Log(int b, int insideVal){
    baseNum = b;
    insideNum = insideVal;
}
Log::Log(){

}
Log::~Log()
{
}

Value* Log::simplify(){
    //simplifyLog(base, insideValue);
    printInfo();
}

Value* Log::simplifyLog(Value* a, Value* b){
    RationalFraction* f1 = dynamic_cast<RationalFraction*>(a);
    RationalFraction* f2 = dynamic_cast<RationalFraction*>(b);
    RationalNumber* rN1 = dynamic_cast<RationalNumber*>(a);
    RationalNumber* rN2 = dynamic_cast<RationalNumber*>(b);
    IrrationalNumber* iRN1 = dynamic_cast<IrrationalNumber*>(a);
    IrrationalNumber* iRN2 = dynamic_cast<IrrationalNumber*>(b);
    vector<Value*> x;

    if( f1 && f2 ){

    }
    if( (f1 && rN1) || (f1 && rN2) || (f2 && rN1) || (f2 && rN2) ){
        if (f1 && rN1){

        }
    }
    if(rN1 && rN2){
        if(rN1->getNumValue() == rN2->getNumValue()){
            Value* rNSimp = new RationalNumber(1);
            return rNSimp;
        }
        else{
            int num1 = rN2->getNumValue();
            int i = 2;
            //simplifyLogRN(num1,0,i);
        }
    }
}

Value* Log::getNum1(){
    return base;
}

Value* Log::getNum2(){
    return insideValue;
}

void Log::printInfo(){
    cout<<"log_";
    base->printInfo();
    cout<<":";
    insideValue->printInfo();
}

Value* Log::logFactor(vector<Value*>, int index1, int index2){

}
