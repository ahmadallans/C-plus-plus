//Ahmad Allan, Omar Alali
//This program works perfectly 

#include <iostream>
using namespace std;

class Stack
{

private:

	int *myArray;
	int tempArraySize;
	int arraySize;

	//creates new function that increases the array size
	void increaseCapacity()
	{
		//create new array
		int *newArray = new int[arraySize * 2];
		//copy to new one
		for (int i = arraySize * 2 - 1, j = arraySize - 1; j >= 0; i--, j--)
			newArray[i] = myArray[j];

		//tempArraySize is now arraySize
		tempArraySize = arraySize;
		//double arraySize and assign it to myArray
		arraySize = arraySize * 2;
		myArray = newArray;
	}

public:
	Stack(int size)
	{
		myArray = new int[size];
		arraySize = size;
		tempArraySize = arraySize;
	}

	void push(int x)
	{

		//call increase size function when tempArraySize is -1 (full) 
		if (tempArraySize == -1) {
			increaseCapacity();
		}
		tempArraySize--;
		myArray[tempArraySize] = x;
	}
	//to print list
	int pop()
	{
		tempArraySize += 1;
		return myArray[tempArraySize - 1];
	}
	//checks if empty
	bool isEmpty() {
		return tempArraySize == arraySize;
	}

};

int main()

{

	cout << "Initialized with size 5 and 8 elements added to it" << endl << endl;
	Stack stack(5);

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	stack.push(6);
	stack.push(7);
	stack.push(8);


	while (!stack.isEmpty())
		cout << stack.pop() << "  ";
	cout << endl << endl;
}