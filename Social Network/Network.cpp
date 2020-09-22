#include "Network.h"

//Default Constructor to initialize
Network::Network() : memberCount(0), maxMembers(DEFAULT_CAPACITY)
{
}
//number of people in network (used in other functions)
int Network::getCurrentSize() const
{
	return memberCount;
} 

////check if network is empty (used in other functions)
//bool Network::isEmpty() const
//{
//	return memberCount == 0;
//}

//add a profile to network 
bool Network::add(const Profile& p)
{
	bool hasRoomToAdd = (memberCount < maxMembers);
	//check if network is below capacity, if not add user
	if (hasRoomToAdd)
	{
		members[memberCount] = p;
		memberCount++;
	} 
	return hasRoomToAdd;
} 

//remove a profile to network 
bool Network::remove(const std::string name)
{
	int locatedIndex = getIndexOf(name);
	memberCount--;
	members[locatedIndex] = members[memberCount];
	return 1;
}



//Check if the profile is on network
bool Network::isThere(const std::string name) const
{
	return getIndexOf(name) > -1;
}

//Finds index of profile
int Network::getIndexOf(const std::string name) const
{
	bool found = false;
	int result = -1;
	int searchIndex = 0;

	// a check for if the network is empty
	while (!found && (searchIndex < memberCount))
	{
		if (members[searchIndex].getName() == name)
		{
			found = true;
			result = searchIndex;
		}
		else
		{
			searchIndex++;
		}  
	} 

	return result;
}

//Show the profile
void Network::show(std::string name)
{
	int index = getIndexOf(name);
	std::cout << "\n\nName: " << members[index].getName();
	std::cout << "\nStatus: " << members[index].getStatus();
	std::cout << "\nImage: " << ((members[index].getImage() == " ") ? "No Image!" : members[index].getImage()) << std::endl;
	std::cout << "friends: \n";
	members[index].showFriends();
}
//edit name
void Network::editN(std::string member, std::string n)
{
	int index = getIndexOf(member);
	members[index].setName(n);
}
//edit status
void Network::editS(std::string member, std::string s)
{
	int index = getIndexOf(member);
	members[index].setStatus(s);
}
//edit image
void Network::editI(std::string member, std::string i)
{
	int index = getIndexOf(member);
	members[index].setImage(i);
}
//Allows user to add friends to their friends list
void Network::addFriends(std::string m, std::string n)
{
	int index = getIndexOf(m);
	members[index].addFriend(n);
}
//remove friends
void Network::removeFriends(std::string m, std::string n)
{
	int index = getIndexOf(m);
	members[index].removeFriend(n);
}
