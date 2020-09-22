#include "Fraction.cpp"
class Mixed
{
	int VariableA;
	Fraction *VariableB;
public:
	// Default constructor
	Mixed()
	{
		VariableA = 0;
		VariableB = new Fraction(0, 1);
	}
	// Overload constructor
	Mixed(int VariableA, int num, int den)
	{
		this->VariableA = VariableA;
		this->VariableB = new Fraction(num, den);
	}

	Fraction _add()
	{
		// fraction creation
		Fraction temp(VariableA, 1);
		//addition operation
		return this->VariableB->add(temp);
	}
	Fraction _subtract()
	{
		// fraction creation
		Fraction temp(VariableA, 1);
		// subtraction operation
		return this->VariableB->subtract(temp);
	}
	Fraction _multiply()
	{
		// fraction creation
		Fraction temp(VariableA, 1);
		// multiplication operation
		return this->VariableB->multiply(temp);
	}
	Fraction _divide()
	{
		// fraction creation
		Fraction temp(VariableA, 1);
		// division operation
		return this->VariableB->divide(temp);
	}
	string toString()
	{
		//converts answer to string
		char temp[100];
		cout<<temp<< this->VariableA;
		return "VariableA = " + (string)temp + "\ny = " + this->VariableB->toString();
	}
};