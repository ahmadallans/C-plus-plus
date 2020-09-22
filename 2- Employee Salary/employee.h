/*This program inputs an employee’s first name, last name and salary and outputting these values
along with their salary after raises.*/
//This is the header file
#pragma once
#include <iostream>
#include <string>
using namespace std;

//class declaration
class employee {
//private members of class
private:
	//initializing variables (hidden in private)
	string first;
	string last;
	int salary=0;
public:
	//class employee constructor
	employee(string firstName, string lastName, int money){
		first = firstName;
		last = lastName;
		//fail safe if user inputted a negative value
		if (money < 0)
			money = 0;
		salary = money;
	}
	//a function to set the variable for first name
	void setFirst(string firstName){
		first = firstName;
	}
	//a function used to print the variable for first name
	string getFirst() const {
		return first;
	}
	//a function to set the variable for last name
	void setLast(string lastName){
		last=lastName;
	}
	//a function used to print the variable for last name
	string getLast() const {
		return last;
	}
	//a function to set the variable for salary
	void setSalary(int money){
		if (money < 0)
			money = 0;
		salary=money;
	}
	//a function used to print the variable for salary
	int getSalary() const {
		return salary;
	}

};
