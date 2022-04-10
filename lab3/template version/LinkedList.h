/** ADT bag: Link-based implementation.
	@file LinkedList.h */

#ifndef _LINKED_LIST
#define _LINKED_LIST

#include <vector>
#include "Node.h"

template<class ItemType>
class LinkedList {
private:
	Node<ItemType>* headPtr;	// A pointer to a Node that represents the head of the list
	int itemCount;				// A counter that holds the number of items in the list
	
public:
	LinkedList();
	virtual ~LinkedList();
	
	// Returns the number of items in the LinkedList
	int getCurrentSize() const;
	
	// Returns a vector filled with the items held by the LinkedList
	std::vector<ItemType> toVector() const;
	
	// Returns true if the item was successfully added and false if not
	bool addItem(const ItemType& anItem);
	
}; // end LinkedList

#include "LinkedList.cpp"
#endif 
