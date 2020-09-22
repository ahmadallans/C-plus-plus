#include<iostream>
#include<stack>
using namespace std;
#include<math.h>

//function solve is used to solve the Towers of Hanoi problem
void solve(int num_of_disks, stack<int> col1, stack<int> col2, stack<int> col3)
{
	int iter = 0;
	//iter is the number of loops required to finish the Towers of Hanaoi problem
	iter = pow(2, num_of_disks);
	int initializer = num_of_disks;
	//This while loop initializes the first tower
	while (initializer > 0)
	{
		col1.push(initializer);
		initializer--;
	}
	//loop that stops when number of disks squared is reached
	for (int counter = 1; counter < iter; counter++) {
		//if statement to identitify which step we are on
		if (counter % 3 == 1) {
			//if the first tower is empty...
			if (col1.empty()) {
				//we copy a disk from tower three to it and...
				col1.push(col3.top());
				//delete it from tower three
				col3.pop();
				cout << "Move disk from coloumn 3 to 1" << endl;
			}
			//if the third tower is empty...
			else if (col3.empty()) {
				//we copy a disk from tower one to it and...
				col3.push(col1.top());
				//delete it from tower one
				col1.pop();
				cout << "Move disk from coloumn 1 to 3" << endl;
			}
			//if the top disk on col1 was larger the top disk on col3...
			else if (col1.top() > col3.top()) {
				//we copy the top disk from tower three to it and...
				col1.push(col3.top());
				//delete it from tower three
				col3.pop();
				cout << "Move disk from coloumn 3 to 1" << endl;
			}
			//if the top disk on tower 3 was larger the top disk on tower 1...
			else if (col3.top() > col1.top()) {
				//we copy the top disk from tower one to it and...
				col3.push(col1.top());
				//delete it from tower one
				col1.pop();
				cout << "Move disk from coloumn 1 to 3" << endl;
			}
		}
		//if statement to identitify which step we are on
		if (counter % 3 == 2) {
			//if the first tower is empty...
			if (col1.empty()){
				//we copy a disk from tower two to it and...
				col1.push(col2.top());
				//and delete it from tower two
				col2.pop();
				cout << "Move disk from coloumn 2 to 1" << endl;
			}
			//if the second tower is empty...
			else if (col2.empty()) {
				//we copy a disk from tower one to it and...
				col2.push(col1.top());
				//and delete it from tower 1
				col1.pop();
				cout << "Move disk from coloumn 1 to 2" << endl;
			}
			//if the top disk on col1 was larger the top disk on col2...
			else if (col1.top() > col2.top()) {
				//we copy the top disk from tower two to it and...
				col1.push(col2.top());
				//delete it from tower two
				col2.pop();
				cout << "Move disk from coloumn 2 to 1" << endl;
			}
			//if the top disk on col2 was larger the top disk on col1...
			else if (col2.top() > col1.top()) {
				//we copy the top disk from tower one to it and...
				col2.push(col1.top());
				//delete it from tower one
				col1.pop();
				cout << "Move disk from coloumn 1 to 2" << endl;
			}
		}
		//if statement to identitify which step we are on
		if (counter%3==0)
		{
			//if the third tower is empty...
			if (col3.empty()) {
				//we copy a disk from tower two to it and...
				col3.push(col2.top());
				//delete it from twoer two 
				col2.pop();
				cout << "Move disk from coloumn 2 to 3" << endl;
			}
			//if the second tower is empty...
			else if (col2.empty()) {
				//we copy a disk from tower three to it and...
				col2.push(col3.top());
				//and delete it from tower three
				col3.pop();
				cout << "Move disk from coloumn 3 to 2" << endl;
			}
			//if the top disk on col3 was larger the top disk on col2...
			else if (col3.top() > col2.top()) {
				//we copy a disk from tower two to it and...
				col3.push(col2.top());
				//and delete it from tower two
				col2.pop();
				cout << "Move disk from coloumn 2 to 3" << endl;
			}
			//if the top disk on col2 was larger the top disk on col3...
			else if (col2.top() > col3.top()) {
				//we copy a disk from tower three to it and...
				col2.push(col3.top());
				//and delete it from tower three
				col3.pop();
				cout << "Move disk from coloumn 3 to 2" << endl;
			}
		}
	}
}
//driver program
	int main() {
		//initializes the number of disks and ask the user to enter the number of disks
		int disk_num;
		cout << "Enter the number of disks you would like to solve for: ";
		cin >> disk_num;
		cout << endl;
		//initializes the three stacks
		stack<int> colOne;
		stack<int> colTwo;
		stack<int> colThree;
		//calls the function solve
		solve(disk_num, colOne, colTwo, colThree);
		cout<<"\n\nDONE!!"<<endl<<endl;
	}
