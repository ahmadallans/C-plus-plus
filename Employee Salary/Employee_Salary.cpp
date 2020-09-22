/*This program inputs an employee’s first name, last name and salary and outputting these values
along with their salary after raises.*/ 
#include <iostream>
#include <string>
//to be able to us class employee we have to include it in file
#include "employee.h"
using namespace std;

int main()
{
	//setting constructor values for employee 1 and 2
	employee employee1{ "Ahmad", "Allan", -35000 };
	employee employee2{ "Omar", "Alali", 45000 };

	//statement to output the name and salary
	cout << "Employee one name is: " << employee1.getFirst() << " " << 
		employee1.getLast() << " and his salary is: $" << 
		employee1.getSalary() << endl;
	
	cout << "Employee two name is: " << employee2.getFirst() << " " << 
		employee2.getLast() << " and his salary is: $" << 
		employee2.getSalary() << endl<<endl;
	
	//statement to output the salary after %10 raise
	cout << "Employee one salay after %10 raise is: $" << 
		(employee1.getSalary())*.1 + employee1.getSalary() << endl;
	
	cout << "Employee two salay after %10 raise is: $" << 
		(employee2.getSalary())*.1 + employee2.getSalary() << endl;
}
