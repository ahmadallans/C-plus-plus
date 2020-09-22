//Allan_Alali_Q1
//This program is working perfectly

//This code was copied from ECE 4050 GitHub 

#include <cstddef>

#ifndef _BAG
#define _BAG

template <class ItemType>
class Bag
{
private:
	static const int DEFAULT_BAG_SIZE = 6;
	ItemType items[DEFAULT_BAG_SIZE]; // array of bag items
	int itemCount; // current count of bag items
	int maxItems; // max capacity of the bag
				  

	int getIndexOf(const ItemType& target) const;

public:

	Bag();

	int getCurrentSize() const;

	bool isEmpty() const;

	bool add(const ItemType& newEntry);

	bool remove(const ItemType& anEntry);

	void clear();

	bool contains(const ItemType& anEntry) const;

	int getFrequencyOf(const ItemType& anEntry) const;

	void displayBagContents();

	void duplicate(Bag &a, int b);

}; // end Bag

template<class ItemType>

Bag<ItemType>::Bag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)

{

} // end default constructor

template<class ItemType>

int Bag<ItemType>::getCurrentSize() const

{

	return itemCount;

} // end getCurrentSize

template<class ItemType>

bool Bag<ItemType>::isEmpty() const

{

	return itemCount == 0;

} // end isEmpty

template<class ItemType>

bool Bag<ItemType>::add(const ItemType& newEntry)

{

	bool hasRoomToAdd = (itemCount < maxItems);

	if (hasRoomToAdd)

	{

		items[itemCount] = newEntry;

		itemCount++;

	} // end if

	return hasRoomToAdd;

} // end add

template<class ItemType>

bool Bag<ItemType>::remove(const ItemType& anEntry)

{

	int locatedIndex = getIndexOf(anEntry);

	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);

	if (canRemoveItem)

	{

		itemCount--;

		items[locatedIndex] = items[itemCount];

	} // end if

	return canRemoveItem;

} // end remove

template<class ItemType>

void Bag<ItemType>::clear()

{

	itemCount = 0;

} // end clear

template<class ItemType>

int Bag<ItemType>::getFrequencyOf(const ItemType& anEntry) const

{

	int frequency = 0;

	int searchIndex = 0;

	while (searchIndex < itemCount)

	{

		if (items[searchIndex] == anEntry)

		{

			frequency++;

		} // end if

		searchIndex++;

	} // end while

	return frequency;

} // end getFrequencyOf

template<class ItemType>

bool Bag<ItemType>::contains(const ItemType& anEntry) const

{

	return getIndexOf(anEntry) > -1;

} // end contains

  /* ALTERNATE 1

  template<class ItemType>

  bool Bag<ItemType>::contains(const ItemType& anEntry) const

  {

  return getFrequencyOf(anEntry) > 0;

  } // end contains

  */

  /* ALTERNATE 2

  template<class ItemType>

  bool Bag<ItemType>::contains(const ItemType& anEntry) const

  {

  bool found = false;

  for (int i = 0; !found && (i < itemCount); i++)

  {

  if (anEntry == items[i])

  {

  found = true;

  } // end if

  } // end for

  return found;

  } // end contains

  */

template<class ItemType>

void Bag<ItemType>::displayBagContents() {

	for (int r = 0; r < itemCount; r++)

	{

		cout << items[r] << endl;

	}

}

template<class ItemType>

inline void Bag<ItemType>::duplicate(Bag &a, int b)

{

	int s = 0;

	if (a.isEmpty()) {

		cout << "bag is empty" << endl;

	}

	else {

		for (int y = 0; y < b - 1; y++)

		{

			for (int p = y + 1; p < b; p++)

			{

				if (items[y] == items[p])

				{

					for (int i = p; i < b - 1; i++)

					{

						items[p] == items[p + 1];

						s++;

						itemCount--;

					}

				}

			}

		}

		cout << "\nnumbers of items removed: " << s-1 << endl<<endl;

		a.displayBagContents();

	}

}

// private

template<class ItemType>

int Bag<ItemType>::getIndexOf(const ItemType& target) const

{

	bool found = false;

	int result = -1;

	int searchIndex = 0;

	// if the bag is empty, itemCount is zero, so loop is skipped

	while (!found && (searchIndex < itemCount))

	{

		if (items[searchIndex] == target)

		{

			found = true;

			result = searchIndex;

		}

		else

		{

			searchIndex++;

		} // end if

	} // end while

	return result;

} // end getIndexOf

#endif

