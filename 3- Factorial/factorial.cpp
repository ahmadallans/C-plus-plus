//This program calculate the factorial of non-negative numbers
#include <iostream>
using namespace std;
//This function takes input the number the user wishes to calculate the factorial for
void input(unsigned long long int &number)
{
	cout << "This program calculate the factorial of non-negative numbers (20 is max number)." << endl;
	cout << "Enter a number to calculate its factorial: ";
	//number is the number we are calculating the factorial for
	cin >> number;
}
void check(unsigned long long int number)
{
	//checks if number is larger than 20 (c++ limit for factorial calculations
	if (number > 20)
	{
		cout << "c++ can't handle the factorial of numbers larger than 20" << endl;
		exit(0);
	}
	//checks if the number is negative and terminate the program if it is
	else if (number < 0)
	{
		cout << "Negative numbers are not accepted" << endl;
		exit(0);
	}
	//check if the number is equal to 0 (special factorial case)
	else if (number == 0)
	{
		cout << "The factorial of 0 is: 1" << endl;
		exit(0);
	}
}
//factorial functions finds the factorial of positive numbers only
void factorial(unsigned long long int number)
{
	//factorial is the variable that we add to each individual number to calculate the factorial
	//original is the original number the user inputs (used to display the original number later
	unsigned long long int factorial, original;
	factorial = number; original = number;
	//substracts 1 from the original number
	number--;
	//while loop that stops when the original number is 0
	while (number != 0)
	{
		//keeps adding value to factorial to eventually get the factorial
		factorial = factorial*number;
		//keeps subtracting 1 from the original number with each iteration of the while loop
		number--;
	}
	//outputs the original number and its factorial
	cout << "The factorial of " << original << " is: " << factorial<<endl;
}
//initializes the original number an calls on other functions
int main(){
	unsigned long long int number = 0;
	input(number);
	check(number);
	factorial(number);
}