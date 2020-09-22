#include <iostream>
#include <iomanip> 
using namespace std;

//This function calculated the charge accumulated on each of the three cars and returns the total charge for each
double Charges(double hours)
{
	//initialize total to 20 (charge if 3 hours or less)
	double total = 20.0;
	// if time is more than 3 hours
	if (hours > 3) 
	{
		/* The garage charges an additional $5.00 per hour
		for each hour or part there of in excess of three hours */
		total += (ceil(hours) - 3) * 5;
	}

	if (total > 50.00)
	{
		//The maximum charge for any given 24-hour period is $50.00
		total = 50.00; 
	}
	return total;
}

void print(double car1, double car2, double car3)
{
	//calls the function charges for each car and stores its return value (total charge) in three different variables
	double car1Charges = Charges(car1);
	double car2Charges = Charges(car2);
	double car3Charges = Charges(car3);
	
	//printing the results in a table format
	cout << fixed << setfill('0');
	cout << "car" << "\t" << "Hours" << '\t' << "Charge" << endl;
	cout << "1" << '\t' << setprecision(1) << car1 << '\t' << setprecision(2) << car1Charges << endl;
	cout << "2" << '\t' << setprecision(1) << car2 << '\t' << setprecision(2) << car2Charges << endl;
	cout << "3" << '\t' << setprecision(1) << car3 << '\t' << setprecision(2) << car3Charges << endl;
	cout << "Total" << '\t' << setprecision(1) << car1 + car2 + car3 << '\t' << setprecision(2) << car1Charges + car2Charges + car3Charges << endl;
	
}

int main()
{
	double car1, car2, car3;
	//takes input from user for each of the three cars
	cout << "Car 1 time:";
	cin >> car1;
	//error trapping for values less than 0 or more than 24
	while (car1 < 0 || car1>24)
	{
		cout << "Can't be this value" << endl;
		cout << "Car 1 time:";
		cin >> car1;
	}
	cout << "Car 2 time:";
	cin >> car2;
	//error trapping for values less than 0 or more than 24
	while (car2 < 0 || car2>24)
	{
		cout << "Can't be this value" << endl;
		cout << "Car 2 time:";
		cin >> car2;
	}
	cout << "Car 3 time:";
	cin >> car3;
	//error trapping for values less than 0 or more than 24
	while (car3 < 0 || car3>24)
	{
		cout << "Can't be this value" << endl;
		cout << "Car 3 time:";
		cin >> car3;
	}
	cout << endl;
	
	//calls the print funtion, and gives it the inputted values for the three cars from the user
	print(car1, car2, car3);
	cout << endl;

	return 0;
	// end program
}