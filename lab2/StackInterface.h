/** @file StackInterface.h */

#ifndef _STACK_INTERFACE
#define _STACK_INTERFACE

template<class ItemType>
class StackInterface
{
	public:
		//Checks if the top of the stack is nullptr, in which case the stack is empty
		//Input: None
		//Returns: Boolean true if the stack is empty, false otherwise
		virtual bool isEmpty() const = 0;
		
		//Pushes an item on top of the stack
		//Input: newEntry     The item to be added as a new entry
		//Returns: True if addition was successful, or false if not
		virtual bool push(const ItemType& newEntry) = 0;
		
		//Removes an item from the top of the stack
		//Input: None
		//Returns: True if the removal was successful, or false if not
		virtual bool pop() = 0;
		
		//Returns the item at the top of the stack
		//Input: None
		//Returns: The item at the top of the stack.
		virtual ItemType peek() const = 0;
}; // end StackInterface

#endif 
