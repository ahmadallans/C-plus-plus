#ifndef _PROFILE
#define _PROFILE
#include<string>
#include"ArrayList.h"
#include<iostream>
//Creating class profile
class Profile
{
private:
	std::string name;
	std::string image;
	std::string status;
	int friendCount = 0;
	ArrayList<std::string> friends;
public:
	//constructor
	Profile();
	//overload constructor
	Profile(std::string name, std::string status, std::string image);
	
	//set functions
	void setName(std::string);
	void setImage(std::string);
	void setStatus(std::string);

	//get functions
	std::string getName() const;
	std::string getImage() const;
	std::string getStatus() const;

	//add, remove, show friends functions
	void addFriend(std::string member);
	void removeFriend(std::string member);
	void showFriends();
};
#endif

