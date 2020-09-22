#include "Complex.h"
#include<iostream>
using namespace std;
int main()
{
	Complex result, number_A(4.3, 8.2), number_B(3.3, 1.1), user_input;
	cout << "Enter a complex number in the form: (a,b) ";
	//takes input from user
	cin >> user_input;
	//outputs expected result, numbers used, and number inputted.
	cout <<endl<< "result: " << result << " number_A:" << number_A << " number_B:" << number_B << " user input: " << user_input << endl;

	result = number_A + number_B;
	cout <<endl<<endl<< "Addition: " << result << endl;
	result = number_A - number_B;
	cout << "Subtraction: " << result << endl;
	result = number_A * number_B;
	cout << "Multiplication: " << result << endl;

	if (result != user_input)
		cout << result << "!=" << user_input << "Better luck next time"<<endl;
	if (result == user_input)
		cout << result << "==" << user_input << endl;
}
