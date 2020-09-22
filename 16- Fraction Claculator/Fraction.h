#pragma once

#include<iostream>
#include<cstring>
#include <sstream>
using namespace std;
class Fraction
{
	int numerator;
	int denominator;
public:
	// Initializing constructor
	Fraction();
	// Overloading constructor
	Fraction(int, int);
	// to display the numerator
	int getNumerator();
	// return denominator
	int getDenominator();
	// addition function
	Fraction add(Fraction);
	// subtraction function
	Fraction subtract(Fraction);
	// multiplication function
	Fraction multiply(Fraction);
	// division function
	Fraction divide(Fraction);
	// fraction to string function
	string toString();
	// fraction to decimal function
	double Decimal();
	// Simplifies fractions
	void reduceToLowestTerms();
};