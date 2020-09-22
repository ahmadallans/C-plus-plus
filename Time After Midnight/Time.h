#pragma once
using namespace std;
#include <string>
class Time
{
public:
	void setTime(int, int, int);
	string toUniversalString() const;
	string toStandardString() const;
private:
	unsigned int hour{ 0 };
	unsigned int minute{ 0 };
	unsigned int second{ 0 };


};

