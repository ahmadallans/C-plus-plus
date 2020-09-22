//This program calculates the value of e to an accuracy determined by the user 
#include <iostream>
using namespace std;

//This function takes input the number the user wishes to use for accuracy and the value of accuracy
void input(int &accuracy, int &numerator)
{
	cout << "This program calculate the value of e^accuracy." << endl;
	cout << "Enter the desired accuracy: ";
	//accuracy is the number that determines the accuracy desired
	cin >> accuracy;
	cout<< "Enter the value of numerator: ";
	//numerator is the value of x
	cin >> numerator;
}
void check(int accuracy)
{
	//checks if the number is non-positive and terminate the program if it is
	if (accuracy <= 0)
	{
		cout << "Non positive numbers are not accepted" << endl;
		exit(0);
	}
}
//calc functions finds the value of e^x
void calc(int accuracy, int numerator)
{
	//answer is the final value and factorial is the number we divide by
	double answer = 1, factorial;
	int counter;
	for (int t = 0; t < (accuracy - 1); t++)
	{
		factorial = t + 1;
		counter = t;
		while (counter != 0)
		{

			factorial = factorial*counter;
			counter--;
		}
		//keeps adding to answer untill t reaches accuracy-1
		answer = answer +  (pow(numerator,(t+1)))/ factorial;
	}
	cout << "The value of e is: " << answer << endl;
}
//function main calls other functions
int main(){
	int accuracy = 0, numerator=0;
	input(accuracy, numerator);
	check(accuracy);
	calc(accuracy, numerator);
}
