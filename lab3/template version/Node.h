/** @file Node.h */
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node 
{
	private:
		ItemType item;				// A string that came from a line in the file
		Node<ItemType>* next;		// A pointer to the next Node
		
	public:
		Node();
		Node(const ItemType& anItem);
		Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	
		void setItem(const ItemType& anItem);
		void setNext(Node* nextNodePtr);
		
		// Returns the string data member held by the Node
		ItemType getItem() const;
		
		// Returns the pointer to the next Node after this one
		Node<ItemType>* getNext() const;
}; // end Node

#include "Node.cpp"
#endif
