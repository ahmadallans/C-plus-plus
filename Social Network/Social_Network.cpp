#include <iostream>
using namespace std;
#include "Profile.h"
#include"Network.h"

int main() {
	//variable to display if a profile exists
	int exists;
	//Create a new profile for Ahmad, Omar, Hanady
	Profile* newProfile1;
	newProfile1 = new Profile("Ahmad", "Hungry", "image");
	Profile* newProfile2;
	newProfile2 = new Profile("Omar", "Working", " ");
	Profile* newProfile3;
	newProfile3 = new Profile("Hanady", "Playing", " ");

	//Create an object for Network
	Network NetworkObj;

	//adding Ahmad, Omar, Hanady to network
	NetworkObj.add(*newProfile1);
	NetworkObj.add(*newProfile2);
	NetworkObj.add(*newProfile3);
	
	//displaying the three profiles
	cout << "Three people joining network";
	NetworkObj.show("Ahmad");
	NetworkObj.show("Omar");
	NetworkObj.show("Hanady");

	//adding friends 
	cout << "\n\n\nadding Omar as Ahmad friend\n";
	NetworkObj.addFriends("Ahmad", "Omar");
	NetworkObj.show("Ahmad");
	cout << "\n\n\nadding Hanady as Ahmad friend\n";
	NetworkObj.addFriends("Ahmad", "Hanady");
	NetworkObj.show("Ahmad");

	//removing friends
	cout << "\n\nRemove Omar as Ahmad friend" << endl;
	NetworkObj.removeFriends("Ahmad", "Hanady");
	NetworkObj.show("Ahmad");

	//Searching for profiles
	cout << "\n\nCheck if Omar profile exists: " << endl;
	if (NetworkObj.isThere("Omar"))
		cout << "It exists" << endl;
	else
		cout << "It doesn't exist" << endl;
	
	cout << "\nCheck if Jo profile exists: " << endl;
	if (NetworkObj.isThere("Jo"))
		cout << "It exists" << endl;
	else
		cout << "It doesn't exist" << endl;

	//Modify Ahmad Profile
	cout << "\nModify Ahmad Status to available" << endl;
	NetworkObj.editS("Ahmad", "Available");
	NetworkObj.show("Ahmad");

	//remove a person from network
	cout << "\n\nRemove Hanady from network" << endl;
	NetworkObj.remove("Hanady");
	cout << "\nCheck if Hanady profile exists: " << endl;
	if (NetworkObj.isThere("Hanady"))
		cout << "It exists" << endl;
	else
		cout << "It doesn't exist" << endl;
}