/** @file LinkedList.cpp */
#include "LinkedList.h"

//A constructor given no arguments will implicitly assign headPtr to nullptr and lineCount to 0
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
} // end default constructor

//A destructor that frees each Node in the list until it is empty
template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	
	while (headPtr != nullptr)						//While headPtr points to a node...
	{
 		Node<ItemType>* nodeToDeletePtr = headPtr;	//Store the node so you do not lose it
 		headPtr = headPtr->getNext();				//Move to the next node
		nodeToDeletePtr->setNext(nullptr);			//Disconnect the node from the list
		delete nodeToDeletePtr;						//Delete the node
 	} // end while
 	
 	//nodeToDeletePtr = nullptr;			//At the end, safeguard from dangling pointer
 	itemCount = 0;							//Set the number of items there are to zero
 	
} // end destructor 

/******************************************************************************/
/* Method: getCurrentSize                                                     */
/* Inputs: None                                                               */
/* Outputs: An integer "itemCount"                                            */
/* Purpose: To identify how many items are held by the list                   */
/******************************************************************************/
template<class ItemType>
int LinkedList<ItemType>::getCurrentSize() const
{
	return itemCount;
} // end getCurrentSize 

/******************************************************************************/
/* Method: toVector                                                           */
/* Inputs: None                                                               */
/* Outputs: A vector of type ItemType that holds the items held by the list   */
/* Purpose: Used to display the items held by the list                        */
/******************************************************************************/
template<class ItemType>
std::vector<ItemType> LinkedList<ItemType>::toVector() const
{
	std::vector<ItemType> items;							//Create a vector that holds items  
	Node<ItemType>* curPtr = headPtr;						//Create a pointer for traversing the list
	int counter = 0;										//A safeguard to ensure you don't go over item count				
	
	while ((curPtr != nullptr) && (counter < itemCount)) 	//While you have not reached end of list...
	{
		items.push_back(curPtr->getItem());					//Store the item at that node in the vector
		curPtr = curPtr->getNext();							//Move to the next node
		counter++;
	} // end while
	
	return items;											//Return the vector
} // end toVector

/******************************************************************************/
/* Method: addItem						                                      */
/* Inputs: A constant reference to ItemType "newItem"                         */
/* Outputs: True if the addition was successful, false otherwise              */
/* Purpose: To insert an item into the LinkedList at the proper location such */
/*          that the items are in ascending order                             */
/******************************************************************************/
template<class ItemType>
bool LinkedList<ItemType>::addItem(const ItemType& newItem) {
	bool additionSuccessful = true;												//Defaults to true so less assignments are made

	if (headPtr == nullptr || headPtr->getItem() < newItem) {					//If list is empty or first entry is less than entry being inserted
		Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, headPtr);		//Insert at the head of the list
		headPtr = newNodePtr;
	} else {																	//Else, find the proper insertion point
		Node<ItemType>* curPtr = headPtr;
		Node<ItemType>* prevPtr = nullptr;
		while (curPtr != nullptr && curPtr->getItem() >= newItem) {				//Traverse the list until you hit the end or find an entry greater than or equal to yours
			prevPtr = curPtr;													//I can simplify the code if I compare prevPtr in the case its a duplicate, 
			curPtr = curPtr->getNext();											//That is why I let it move to the next node when it is equal
		}
		if (prevPtr->getItem() != newItem) {									//If not duplicate, insert between prevPtr and curPtr
			Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, curPtr);	//This includes the case curPtr == nullptr
			prevPtr->setNext(newNodePtr);
		} else {
			additionSuccessful = false;											//If no insertion was made, it is a duplicate
		}
	}
	
	if (additionSuccessful) {													//Increase the count of lines in the list if an insertion was made
		itemCount++;
	}
	
	return additionSuccessful;													//Return whether addition was successful
}
