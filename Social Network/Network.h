#ifndef _NETWORK
#define _NETWORK
#include"Profile.h"
#include<iostream>
//Creating a class and calling it Network
class Network
{
private: 
	static const int DEFAULT_CAPACITY = 100;
	Profile members[DEFAULT_CAPACITY];
	int memberCount;
	int maxMembers;
	int getIndexOf(const std::string name) const;
public:
	//default constructor
	Network();
	//number of members
	int getCurrentSize() const;
	//check if social media website is empty
	bool isEmpty() const;
	//adds members
	bool add(const Profile& p);
	//removes members
	bool remove(const std::string member);
	//checks if a member is there
	bool isThere(const std::string member) const;
	//shows the profile of the member
	void show(const std::string name);
	//edit the name of the member
	void editN(std::string member, std::string name);
	//edit the status of the member
	void editS(std::string member, std::string status);
	//edit the image of the member
	void editI(std::string member, std::string image);
	//add friends
	void addFriends(std::string m, std::string n);
	//remove friends
	void removeFriends(std::string m, std::string n);
};

#endif
