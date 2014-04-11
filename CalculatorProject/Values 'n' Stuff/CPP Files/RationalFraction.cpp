#include "RationalFraction.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

RationalFraction::RationalFraction(int n, int d)
{
    numer = n;
    denom = d;
}
RationalFraction::RationalFraction(){

}

RationalFraction::~RationalFraction()
{
}
int RationalFraction::getDenominator(){
    cout<<"Initial Denominator: "<<denom<<endl;
    return denom;
}

int RationalFraction::getNumerator(){
    cout<<"Initial Numerator: "<<numer<<endl;
    return numer;
}

int RationalFraction::simplifyNum(int n, int d, int index){
    int numerator = n;
    int denominator = d;
    int newnum, newden;
    int i = index;
    /*for(int i = 1; i < numer; i++){
        if(numerator % i == 0 && denominator % i == 0){
            tempNum = numerator/i;
        }
    }*/
    if(i >= numerator){
        cout<<numerator<<endl;;
        return numerator;
    }
    else if(numerator % i == 0 && denominator % i == 0){
        newnum = numerator/i;
        newden = denominator/i;
        cout<<newnum<<endl;
        return simplifyNum(newnum, newden, i);
    }
    else{
        i++;
        return simplifyNum(numerator,denominator,i);
    }

//    return -1;
}

int RationalFraction::simplifyDen(int n, int d, int index){
    int numerator = n;
    int denominator = d;
    int tempDen = 0;
    int tempNum;
    int i = index;
    /*for(int i = 1; i < numer; i++){
        if(numerator % i == 0 && denominator % i == 0){
            tempNum = numerator/i;
        }
    }*/
    if(i > denominator){
        cout<<denominator<<endl;
        return denominator;
    }
    else if(numerator % i == 0 && denominator % i == 0){
        tempDen = denominator/i;
        tempNum = numerator/i;
        cout<<tempDen<<endl;
        return simplifyDen(tempNum, tempDen, i);
    }
    else{
        i++;
        return simplifyDen(numerator, denominator, i);
    }

//    return -1;
}

Value* RationalFraction::getNum1(){
    getNumerator();
}
Value* RationalFraction::getNum2(){
    getDenominator();
}
Value* RationalFraction::simplify(){
    numer = getNumerator();
    denom = getDenominator();
    int index = 2;
    int newNum = simplifyNum(numer, denom, index);
    int newDen = simplifyDen(numer, denom, index);
    cout<<newNum<<'/'<<newDen<<endl;
    Value* simpRTF = new RationalFraction(newNum,newDen);
    return simpRTF;
}

void RationalFraction::printInfo(){

}

