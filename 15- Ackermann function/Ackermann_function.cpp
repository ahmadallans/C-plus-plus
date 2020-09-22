#include <iostream>//cin, cout
using namespace std;//to make it easier instead of writing std

//Acker function to do Ackermann’s function listed int eh question
int Acker(int m, int n)
{
	//Homework function was used to create the following if statements
	if (m == 0)
		return n + 1;//n+1 is returned if m=0
	else if (n == 0)
		return Acker(m - 1, 1);//m-1 to m and 1 to n are returned to function Acker if n=0
	else
		return	Acker(m - 1, Acker(m, n - 1));//default return if m and n are not equal to zero
}

int main()
{
	//input of 1 to m and 2 to n to the function Acker
	cout<< "Acker(1,2) = "<< Acker(1, 2) << endl;
	return 0;
}