//Still not funtioning, mixed isn't working properly

#include "Fraction.h"
//#include "Mixed.h" (not working properly)
int main()
{
	// Fraction display object and output
	Fraction displayObject(3, 4);
	cout << "fraction: " << displayObject.Decimal() << endl;

	// Addition object and output
	Fraction AdditionObject(3, 4);
	Fraction add;
	add = displayObject.add(AdditionObject);
	cout << "\nSum result is: " << add.getNumerator() << " / " << add.getDenominator() << endl;

	//Subtraction objects and output
	Fraction subtractObject1(3, 4);
	Fraction subtractObject2(3, 4);
	Fraction subt;
	subtractObject1.subtract(subtractObject2);
	cout << "\nSubtraction result is: " << subt.toString() << endl;

	//multiplication objects and output
	Fraction multiplyObject1(3, 4);
	Fraction multiplyObject2(3, 4);
	Fraction mult = multiplyObject1.multiply(multiplyObject2);
	cout << "\nMultplication result is: " << mult.toString() << endl;

	// Division object
	Fraction divisionObject1(3, 4);
	Fraction divisionObject2(3, 4);
	Fraction div;
	div = divisionObject1.divide(divisionObject2);
	cout << "\nDivision result is: " << div.toString() << endl<<endl;
}
