#include <iostream>
using namespace std;
//This function produces the first pattern
void stars_a()
{
	//first for loop counts 10 lines
	for (int counter_1 = 1; counter_1 <= 10; counter_1++)
	{
		//second loop will print the number of stars in each line
		for (int counter_2 = 0; counter_2 < counter_1; counter_2++)
			cout << '*';
		cout << endl;
	}
	cout << endl<<endl;
}
void stars_b()
{
	//first for loop counts 10 lines
	for (int counter_1 = 1; counter_1 <= 10; counter_1++)
	{
		//second loop will print the number of stars in each line
		for (int counter_2 = 10; counter_2 > counter_1-1; counter_2--)
			cout << '*';
		cout << endl;
	}
	cout << endl<<endl;
}
void stars_c()
{
	//first for loop counts 10 lines
	for (int counter_main = 1; counter_main <= 10; counter_main++)
	{
		//second loop will print the empty spaces in each line starting from the beginning
		for (int counter_1 = 1; counter_1 < counter_main; counter_1++)
			cout << ' ';
		//third loop will print the number of stars in each line after the empty spaces have been printed starting from the end
		for (int counter_2 = 10; counter_2 > counter_main-1 ; counter_2--)
			cout << '*';
		cout << endl;
	}
	cout << endl << endl;
}
void stars_d()
{
	//first for loop counts 10 lines
	for (int counter_main = 1; counter_main <= 10; counter_main++)
	{
		//second loop will print the empty spaces in each line starting from the end
		for (int counter_1 = 10; counter_1 > counter_main; counter_1--)
			cout << ' ';
		//third loop will print the number of stars in each line after the empty spaces have been printed starting from the beginning
		for (int counter_2 = 0; counter_2 < counter_main; counter_2++)
			cout << '*';
		cout << endl;
	}
}
//This function prints the combined patterns of all four patterns
void combined_stars()
{
	//This main loop will count 10 lines
	for (int counter_main = 1; counter_main <= 10; counter_main++)
	{
		//first pattern
		for (int counter_1 = 0; counter_1 < counter_main; counter_1++)
			cout << '*';
		for (int counter_2 = 10; counter_2 > counter_main - 1; counter_2--)
			cout << ' ';
		cout << ' ';
		//second pattern
		for (int counter_1 = 10; counter_1 > counter_main - 1; counter_1--)
			cout << '*';
		for (int counter_2 = 0; counter_2 < counter_main-1; counter_2++)
			cout << ' ';
		cout << ' ';
		//third pattern
		for (int counter_1 = 1; counter_1 < counter_main; counter_1++)
			cout << ' ';
		for (int counter_2 = 10; counter_2 > counter_main - 1; counter_2--)
			cout << '*';
		cout << ' ';
		//fourth pattern
		for (int counter_1 = 10; counter_1 > counter_main; counter_1--)
			cout << ' ';
		for (int counter_2 = 0; counter_2 < counter_main; counter_2++)
			cout << '*';
		cout << ' ';
		cout << endl;
	}
}


int main()
{
	//calls first function
	stars_a();
	//calls second function 
	stars_b();
	//calls third function
	stars_c();
	//calls fourth function
	stars_d();
	cout << endl << endl << "This is all four patterns combined" << endl << endl;
	//calls fifth function
	combined_stars();
}
