//This program calculates the value of e to an accuracy determined by the user 
#include <iostream>
using namespace std;

//This function takes input the desired accuracy the user wishes to calculate the value of e for
void input(int &accuracy)
{
	cout << "This program calculate the value of e." << endl;
	cout << "Enter the desired accuracy: ";
	//accuracy is the number that determines the accuracy desired
	cin >> accuracy;
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
//calc functions find e
void calc(int accuracy)
{
	//answer is the final value
	//factorial is the number that we divide e by in each step
	double answer = 1, factorial;
	int counter;
	for (int t = 0; t < (accuracy-1); t++)
	{
		factorial = t+1;
		counter = t;
		while (counter != 0)
		{
			
			factorial = factorial*counter;
			counter--;
		}
		//keeps adding up depending on the level of accuracy required
		answer = answer + 1.0 / factorial;
	}
	cout << "The value of e is: " << answer << endl;
}
//function main calls other functions
int main(){
	int accuracy = 0;
	input(accuracy);
	check(accuracy);
	calc(accuracy);
}
