/** @file Node.h */
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node 
{
	private:
		ItemType item;
		Node<ItemType>* next;
		
	public:
		Node();
		Node(const ItemType& anItem);
		Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
		
		void setItem(const ItemType& anItem);
		void setNext(Node<ItemType>* nextNodePtr);
		
		//Returns an item of type ItemType at the current node in the chain
		ItemType getItem() const;
		
		//Returns a pointer to the next node in the chain
		Node<ItemType>* getNext() const;
		
}; // end Node

#include "Node.cpp"
#endif
