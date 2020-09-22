#include<iostream>
#include<stdexcept>
#include "Time.h"
using namespace std;
//displays time (initial)
void displayTime(const string& message, const Time& time)
{
	cout << message << "\nuniversal time: " << time.toUniversalString() << "\nStandard time: " << time.toStandardString() << "\n\n";
}
int main()
{
	Time t;
	displayTime("initial time: ", t);
	t.setTime(13, 27, 6);
	displayTime("After setTime: ", t);
	try
	{
		t.setTime(99, 99, 99);
	}
	catch (invalid_argument& e)
	{
		cout << "Exception: " << e.what() << "\n\n";
	}
	displayTime("After attempting to set an invalid time: ", t);
}