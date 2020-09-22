#include<iostream> //for cin cout
using namespace std; //to make it easier (instead of writing std everytime)
struct Node
{
	//Defines the variable numbers as integer
	int numbers;
	//Pointer to nextNodePtr node
	struct Node *nextNodePtr; 
};
//A function that reverese the list using the iterative method
static void reverseIterative(struct Node** head_ref)
{
	//initializing pointer prevNodePtr to Null
	struct Node* prevNodePtr = NULL;

	struct Node* currentNodePtr = *head_ref;
	//initializing pointer prevNodePtr to Null
	struct Node* nextNodePtr = NULL;
	//while loop keeps iterating until list is completely reversed (currentNodePtr is empty)
	while (currentNodePtr != NULL)
	{
		//to access nextNodePtr in Node struct and assigning currentNodePtr it to the next value
		nextNodePtr = currentNodePtr->nextNodePtr;
		//to access nextNodePtr in Node struct and assignign it to the previous value
		currentNodePtr->nextNodePtr = prevNodePtr;
		//assiging prevNodePtr the value of currentNodePtr
		prevNodePtr = currentNodePtr;
		//assiging currentNodePtr the value of nextNodePtr
		currentNodePtr = nextNodePtr;
	}
	*head_ref = prevNodePtr;
}
// The reversing recursive function 
void RevereseAssist(Node *currentNodePtr2, Node *prevNodePtr, Node **lastNodePtr)
{
	//If this was the the last node, we set as lastNodePtr
	if (!currentNodePtr2->nextNodePtr)
	{
		*lastNodePtr = currentNodePtr2;
		// Assign nextNodePtr to prevNodePtr 
		currentNodePtr2->nextNodePtr = prevNodePtr;
		return;
	}
	// Assign currentNodePtr2 as nextNodePtr node for the recursive function call
	Node *nextNodePtr = currentNodePtr2->nextNodePtr;
	// the we assign nextNodePtr again
	currentNodePtr2->nextNodePtr = prevNodePtr;
	//Call reverUtil function
	RevereseAssist(nextNodePtr, currentNodePtr2, lastNodePtr);
}
//This function calls on reverseAssist function until the las node
void reverse(Node **lastNodePtr)
{
	if (!lastNodePtr)
		return;
	RevereseAssist(*lastNodePtr, NULL, lastNodePtr);
}
// A function to create a new node
//This is where user input starts
Node *nodeInput(int userInput)
{
	//create and initialize pointer tempPtr
	Node *tempPtr = new Node;
	//assigning numbers to userInput
	tempPtr->numbers = userInput;
	//initializing nextNodePtr
	tempPtr->nextNodePtr = NULL;
	return tempPtr;
}
// A  function to print the list
void print(Node *lastNodePtr)
{
	//keeps iterating until lastNodePtr is empty
	while (lastNodePtr != NULL)
	{
		cout << lastNodePtr->numbers << " ";
		lastNodePtr = lastNodePtr->nextNodePtr;
	}
	cout << endl;
}
//A function to remove duplicates
void removeDuplicates(struct Node *beginningOfList)
{
	struct Node *tempPtr1, *tempPtr2, *duplicatePtr;
	tempPtr1 = beginningOfList;
	//keeps looping until end of the list is reached
	while (tempPtr1 != NULL && tempPtr1->nextNodePtr != NULL)
	{
		tempPtr2 = tempPtr1;
		//We go throught the list one by one and we compare the each number to all of them
		while (tempPtr2->nextNodePtr != NULL)
		{
			//if statement to compare numbers in the list
			if (tempPtr1->numbers == tempPtr2->nextNodePtr->numbers)
			{
				//if the if statemnet was true, the number will be deleted (by deleting its pointer)
				duplicatePtr = tempPtr2->nextNodePtr;
				tempPtr2->nextNodePtr = tempPtr2->nextNodePtr->nextNodePtr;
				//delete
				delete(duplicatePtr);
			}
			//if the numbers are not the same, we go to the next number in the list
			else
				tempPtr2 = tempPtr2->nextNodePtr;
		}
		//go to next number 
		tempPtr1 = tempPtr1->nextNodePtr;
	}
}
//Driver program to test our program and call functions
int main()
{
	//Assigining the numbers 1 2 3 1 2 3 9 6 using pointers
	Node *head1 = nodeInput(1);
	head1->nextNodePtr = nodeInput(2);
	head1->nextNodePtr->nextNodePtr = nodeInput(3);
	head1->nextNodePtr->nextNodePtr->nextNodePtr = nodeInput(1);
	head1->nextNodePtr->nextNodePtr->nextNodePtr->nextNodePtr = nodeInput(2);
	head1->nextNodePtr->nextNodePtr->nextNodePtr->nextNodePtr->nextNodePtr = nodeInput(3);
	head1->nextNodePtr->nextNodePtr->nextNodePtr->nextNodePtr->nextNodePtr->nextNodePtr = nodeInput(9);
	head1->nextNodePtr->nextNodePtr->nextNodePtr->nextNodePtr->nextNodePtr->nextNodePtr->nextNodePtr = nodeInput(6);
	//Displaying results
	cout<<"Allan_Alali_Assignment4_Q4\n"<<endl;
	cout << "List" << endl;
	print(head1);
	reverse(&head1);
	cout << "\nReversing (recrusive): "<<endl;
	print(head1);
	reverseIterative(&head1);
	cout << "\nReversing (iterative):"<<endl;
	print(head1);
	cout << "\nRemoving duplicates:"<<endl;
	removeDuplicates(head1);
	print(head1);
	cout << endl;
}
