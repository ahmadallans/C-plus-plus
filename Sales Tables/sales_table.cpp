#include <iostream>
using namespace std;

void print(double &temp1, double temp2[4], double array[4][5])
{
	//prints the table header
	cout << "\n\n\n\n\n\n";
	cout << "    person   " << "\t     person 1" << "\t     person 2" << "\t     person 3" << "\t     person 4" << "\t      total" << endl;
	cout << "Product" << endl << endl;
	//a for loop to go through the rows of table
	for (int row = 0; row < 5; row++)
	{
		//temp1 is used to keep track of the totals
		temp1 = 0;
		cout << "Product " << row + 1 << "\t\t";
		//a for loop to go through the coloumns
		for (int col = 0; col < 4; col++)
		{
			///prints the values of sales row by row and then col by col
			cout << array[col][row] << "\t\t";
			temp1 += array[col][row];
		}
		//prints the total
		cout << temp1 << endl << endl;
	}
	//calculates the total
	for (int col = 0; col < 4; col++)
		for (int row = 0; row < 5; row++)
			temp2[col] += array[col][row];

	cout << "total   \t\t";
	for (int row = 0; row < 4; row++)
	{
		cout << temp2[row] << "    \t\t";
	}
	cout << "\n\n";
}
int main()
{
	//intializes all variables to zero except day number which is initialized to 1
	int day_number = 1, person_number = 0, product_number = 0, selling_price = 0;
	char more_input_current_day;
	double array[4][5], temp1 = 0, temp2[4];
	
	//initializes the array to 0
	for (int col_sales_person = 0; col_sales_person < 4; col_sales_person++)
	{
		temp2[col_sales_person] = 0;
		for (int row_sales_person = 0; row_sales_person < 5; row_sales_person++)
			array[col_sales_person][row_sales_person] = 0;
	}
	//first loop controls the day number
	while (true)
	{
		//seconds loop controls the same day inputs 
		while (true)
		{
			//asks for sales person number
			cout << "\nEnter sales person number for day " << day_number << " (1-4): ";
			cin >> person_number;
			//wrong sales person number error trapping
			while (person_number < 1 || person_number>4)
			{
				cout << "Wrong sales person number" << endl;
				cout << "\nEnter sales person number for day " << day_number << " (1-4): ";
				cin >> person_number;
			}
			//asks for product number
			cout << "Enter product number (1-5): ";
			cin >> product_number;
			//wrong product number error trapping
			while (product_number < 1 || product_number>5)
			{
				cout << "Wrong product number" << endl;
				cout << "Enter product number (1-5): ";
				cin >> product_number;
			}
			//asks for selling price
			cout << "enter selling price: ";
			cin >> selling_price;
			//error trapping for negative amounts
			while (selling_price < 0)
			{
				cout << "selling price can't be negative!" << endl;
				cout << "enter selling price: ";
				cin >> selling_price;
			}
			//stores selling price in the desired location of the array
			array[person_number - 1][product_number - 1] += selling_price;
			//asks user if they want more inputs for that day
			cout << "Do you have more inputs for this day? (Y/N)";
			cin >> more_input_current_day;
			if (more_input_current_day == 'n' || more_input_current_day == 'N')
				//breaks the first loop if user has no more inputs for that day
				break;
		}
		//increments the variable by one to go to next day
		day_number++;
		//stops the seconds while loop when all days have been entered
		if (day_number > 30)
			break;
	}
	//calls the function print
	print(temp1, temp2, array);
}
