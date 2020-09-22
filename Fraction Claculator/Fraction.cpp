#include "Fraction.h"
// Initializing constructor
Fraction::Fraction()
{
	// Initializes numerator and denominator
	this->numerator = 0;
	this->denominator = 1;
}

// Ovelaoding constructor
Fraction::Fraction(int num, int den)
{
	//prevents division by zero by throwing an error when denomerator is zero
	if (den == 0)
		throw "division by zero not allowed";
	this->numerator = num;
	this->denominator = den;
}

// displays numerator
int Fraction::getNumerator()
{
	return this->numerator;
}

// displays denominator
int Fraction::getDenominator()
{
	return this->denominator;
}

// addition function
Fraction Fraction::add(Fraction ob)
{
	// calculate the numerator
	int num = this->numerator * ob.getDenominator() + ob.getNumerator() * this->denominator;
	// calculates the denominator
	int den = this->denominator * ob.getDenominator();
	Fraction ans(num, den);
	// reduceToLowestTerms simplifies the fraaction to simplest terms
	ans.reduceToLowestTerms();
	return ans;
}

//subtraction function
Fraction Fraction::subtract(Fraction ob)
{
	// calculate the numerator
	int num = this->numerator * ob.getDenominator() - ob.getNumerator() * this->denominator;
	// calculate the denominator
	int den = this->denominator * ob.getDenominator();
	Fraction ans(num, den);
	// reduceToLowestTerms simplifies the fraction to simplest terms
	ans.reduceToLowestTerms();
	return ans;
}

// Multiplication function
Fraction Fraction::multiply(Fraction ob)
{
	// compute the numerator
	int num = this->numerator * ob.getNumerator();
	// compute the denominator
	int den = this->denominator * ob.getDenominator();
	Fraction ans(num, den);
	// reduceToLowestTerms the fraaction to simplest terms
	ans.reduceToLowestTerms();
	return ans;
}

// division function
Fraction Fraction::divide(Fraction ob)
{
	if (this->denominator == 0 || ob.getNumerator() == 0)
		throw "Error: Cannot divide by zero.";
	// compute the numerator
	int num = this->numerator * ob.getDenominator();
	// compute the denominator
	int den = this->denominator * ob.getNumerator();
	Fraction ans(num, den);
	// reduceToLowestTerms the fraaction to simplest terms
	ans.reduceToLowestTerms();
	return ans;
}

// converts answer to string
string Fraction::toString()
{
	ostringstream out;
	out << this->numerator << "/" << this->denominator;
	return out.str();
}

// converts fraction to decimal
double Fraction::Decimal()
{
	return (double)this->numerator / (double)this->denominator;
}

// reduceToLowestTerms simplifies the Fraction number to simplest form
void Fraction::reduceToLowestTerms()
{
	int x = this->numerator < this->denominator ? this->numerator : this->denominator;
	for (int counter = 2; counter < x; counter++)
	{
		while (this->numerator % counter == 0 && this->denominator % counter == 0)
		{
			this->numerator /= counter;
			this->denominator /= counter;
		}
	}
}
