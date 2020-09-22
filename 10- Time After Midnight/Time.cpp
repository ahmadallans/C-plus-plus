#include<iomanip>
#include<stdexcept>
#include<sstream>
#include<string>
#include "Time.h"

using namespace std;

void Time::setTime(int h, int m, int s)
{
	//using time in seconds
int seconds=h * 3600 + m * 60 + s;
	if (seconds<90600)
	{
		hour = h*12;
		minute = m*60;
		second = s*60;
	}
	else
	{
		throw invalid_argument("hour, minute and/or second was out of range");
	}
}
//convert time to universal
string Time::toUniversalString() const
{
	ostringstream output;
	output << setfill('0') << setw(2) << hour/12<< ":" << setw(2)<<minute/60<<":"<< setw(2)<<second/60;
	
	return output.str();
}
//convert time to standard 
string Time::toStandardString() const
{
	ostringstream output;
	output << ((hour/12 == 0 || hour/12 == 12) ? 12 : hour/12 % 12) << ":" << setfill('0') << setw(2) << minute/60 << ":" << setw(2) << second/60 << (hour < 12 ? "AM" : "PM");
	return output.str();
}

