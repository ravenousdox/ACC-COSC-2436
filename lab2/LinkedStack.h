/** ADT stack: Link-based implementation.
 @file LinkedStack.h */
 
#ifndef _LINKED_STACK
#define _LINKED_STACK

#include "StackInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
	private:
		Node<ItemType>* topPtr;

	public:
		LinkedStack(); 
 		LinkedStack(const LinkedStack<ItemType>& aStack); 
		virtual ~LinkedStack(); 
		
		//Returns true/false based on whether the stack is empty
		bool isEmpty() const;
		
		//Returns true/false based on whether the item was properly added to the stack
		bool push(const ItemType& newItem);
		
		//Returns true/falsed based on whether the item was properly removed from the stack
 		bool pop();
 		
 		//Returns the item at the top of the stack
 		ItemType peek() const;
 		
}; // end LinkedStack

#include "LinkedStack.cpp"
#endif 
