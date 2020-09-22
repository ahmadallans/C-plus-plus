#include <iostream> // For cout and cin
#include <string> // For string objects
#include "Bag.h" // For ADT bag
using namespace std;
int main()
{
	//groceeries in original bag inputted by user
	string storeBag[] = { "bread", "eggs", "brownie", "orange", "bread", "eggs" };
	//Define object groceryBag	
	Bag<string> groceryBag;
	//Define object fragileBag
	Bag<string> fragileBag;

	//adding inputs
	groceryBag.add(storeBag[0]);
	groceryBag.add(storeBag[1]);
	groceryBag.add(storeBag[2]);
	groceryBag.add(storeBag[3]);
	groceryBag.add(storeBag[4]);
	groceryBag.add(storeBag[5]);

	for (int counter = 0; counter < 6; counter++)
	{
		//looks for fragile items and adds them to the fragile bag and removes them from the bag
		if (storeBag[counter] == "eggs" || storeBag[counter] == "bread") 
		{
			fragileBag.add(storeBag[counter]);
			groceryBag.remove(storeBag[counter]);
		}
		
	}
	
	//displaying fragile bag
	cout << "fragile bag:" << endl;
	fragileBag.displayBagContents();
	
	//Displaying grocery bag
	cout << "\ngrocery bag:" << endl;
	groceryBag.displayBagContents();
	cout << endl;
}

