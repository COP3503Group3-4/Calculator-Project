/*
 * Add.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: Kevin
 */
//test

add::add(){

}

Value add(Fraction a, Fraction b) {
	int n1 = a.getNumerator() * b.getNumerator;
	int n2 = b.getNumerator() * a.getDenominator;
	int d = a.getDenominator() * b.getDenominator;
	return Fraction(n1+n2, d);
}

Value add(Fraction a, Expression b) {
	return Expression(a + b);
}

Value add(Fraction a, Number b)  {
	int n1 = a.getNumerator() * b;
	int n2 = a.getDenominator() * b;
	int d = a.getDenominator() * b;
	return Fraction(n1+n2, d);
}

Value add(Fraction a, Log b)  {
	return Expression(a,b);
}

Value add(Fraction a, NthRoot b) {
	return Expression(a,b);
}





