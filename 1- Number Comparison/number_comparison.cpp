//This program takes on two integers, compare their values, and outputs a message depending on their values
#include <iostream>
using namespace std;

//This function takes two numbers as input from the user
void input(int first, int second)
{
	//asks the user to input the first number
	cout << "Enter the value of the first number: ";
	cin >> first;
	//asks the user to input the second number
	cout << "Enter the value of the second number: ";
	cin >> second;
}

//This function compares the two numbers and prints out a message depending on the value of the numbers
void compare(int &first, int &second)
{
	if (first > second)
		//outputs a message when the first number is larger
		cout << first << " is larger" << endl;
	else if (first < second)
		//outputs a message when the second number is larger
		cout << second << " is larger" << endl;
	else
		//outputs a message when the numbers are equal
		cout << "The numbers are equal" << endl;
}
//main function initializes the values of the numbers (first and second) and calls on other functions
int main(){
	//initialize the two numbers
	int first = 0, second = 0;
	//calls function input for inputting the two numbers
	input(first, second);
	//compares the the two numbers
	compare(first, second);
	return 0;
}