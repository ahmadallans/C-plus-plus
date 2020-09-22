#include "Profile.h"
//Default constructor
Profile::Profile()
{
}
//Overload Constructor 
Profile::Profile(std::string n, std::string s, std::string i)
{
	name = n;
	status = s;
	image = i;
}
//Set functions
void Profile::setName(std::string n)
{
	name = n;
}

void Profile::setStatus(std::string s)
{
	status = s;
}

void Profile::setImage(std::string i)
{
	image = i;
}

//get functions 

std::string Profile::getName()const
{
	return name;
}
std::string Profile::getStatus()const
{
	return status;
}
std::string Profile::getImage()const
{
	return image;
}


//add friends
void Profile::addFriend(std::string member)
{
	friendCount++;
	friends.insert(friendCount, member);
}


//delete friends
void Profile::removeFriend(std::string member)
{
	int pos = friends.getIndexOf(member);
	friends.remove(pos);
	friendCount--;
}
//Display friends
void Profile::showFriends()
{
	for (int i = 1; i <= friendCount; i++)
	{
		std::cout << friends.getEntry(i) << endl;
	}
}