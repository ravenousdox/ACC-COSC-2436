/** @file LinkedStack.cpp */

#include <cassert> 
#include "LinkedStack.h" 

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{
} // end default constructor

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{ 
 	Node<ItemType>* origChainPtr = aStack->topPtr;							//Stores the pointer to the original chain in a separate variable
	if (origChainPtr == nullptr)											//If the pointer to the original chain is nullptr, the original chain is empty
 		topPtr = nullptr; 													//Thus this chain should be empty
	else																
 	{
 		topPtr = new Node<ItemType>();										//Initialize a new node and have topPtr point to it. This is the first node
 		topPtr->setItem(origChainPtr->getItem());							//Copy the contents of the first item in the original chain
 		Node<ItemType>* newChainPtr = topPtr;								//Create a separate variable to traverse the new chain
 		while (origChainPtr != nullptr)										//While you have not reached the end of the chain being copied...
 		{
			origChainPtr = origChainPtr->getNext();							//Traverse the original chain
			ItemType nextItem = origChainPtr->getItem();					//Copy the contents of the node
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);      //Initialize a new node with the copied contents
			newChainPtr->setNext(newNodePtr);								//Add the node onto the new chain
			newChainPtr = newChainPtr->getNext();							//Traverse to the new node just added
 		} // end while
 		newChainPtr->setNext(nullptr); 										//Once you have reached the end of the chain being copied,
 																			//Mark the end of the chain with nullptr
 	} // end if																
} // end copy constructor

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	while (!isEmpty())					//While the stack is not empty
 		pop();							//Remove the item at the top of the stack
} // end destructor

/******************************************************************************/
/* Method: isEmpty							      							  */
/* Inputs: None                                                               */
/* Outputs: A boolean true/false      	 	                                  */
/* Purpose: To signify whether the stack is empty                             */
/******************************************************************************/
template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return topPtr == nullptr;
} // end isEmpty

/******************************************************************************/
/* Method: push					                    			              */
/* Inputs: A constant reference to a new entry of type ItemType				  */
/* Outputs: A boolean true/false depending on whether the node was			  */
/*			 successfully added                  							  */
/* Purpose: Adds an item to the top of the stack                        	  */
/******************************************************************************/
template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem)
{
 	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);	//Initialize a new node with the item passed
 	topPtr = newNodePtr;												//Set the top of the stack to the new node
 	newNodePtr = nullptr; 												//Set the newNodePtr to nullptr so can't dangle
 	return true;
} // end push

/******************************************************************************/
/* Method: pop						                                  		  */
/* Inputs: None                                                               */
/* Outputs: A boolean true/false depending on whether the node was			  */
/*			successfully removed											  */
/* Purpose: Removes an item from the top of the stack                         */
/******************************************************************************/
template<class ItemType>
bool LinkedStack<ItemType>::pop()
{
	bool result = false;							//Default to false				
	if (!isEmpty())									//If the stack is not empty
 	{
 		Node<ItemType>* nodeToDeletePtr = topPtr;	//Create a variable to point to the node to be deleted (which is at top of the stack)
 		topPtr = topPtr->getNext();					//Have the top of the stack point to the node "below" it
		nodeToDeletePtr->setNext(nullptr);			//Redundancy?
		delete nodeToDeletePtr;						//Free the memory being pointed to
 		nodeToDeletePtr = nullptr;					//Make sure it doesnt dangle
 		result = true;								//The node was successfully deleted if the code executed thus far
 	} // end if
	return result;
} // end pop

/******************************************************************************/
/* Method: peek					                                  			  */
/* Inputs: None                                                               */
/* Outputs: The item at the top of the stack of type ItemType 				  */
/* Purpose: Retrieves the item at the top of the stack                        */
/******************************************************************************/
template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const
{
	assert(!isEmpty()); 		//Ensure that the stack is not empty prior to peeking
	return topPtr->getItem();	//Get the item from the node at the top of the stack
} // end getTop

// end of implementation file 
