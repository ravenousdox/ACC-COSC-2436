/** @file Node.cpp */
#include "Node.h"

//A constructor given no arguments
//Implicitly assigns item to an empty string and next to nullptr
template<class ItemType>
Node<ItemType>::Node() : item(""), next(nullptr)
{
} // end default constructor

//A constructor given just a data member
//Implicitly assigns next to nullptr
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
} // end constructor

//A constructor given a data member and pointer to the next node
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{
} // end constructor

/******************************************************************************/
/* Method: setItem  								      					  */
/* Inputs: A constant reference to a ItemType "anItem"                        */
/* Outputs: None                                                              */
/* Purpose: Sets the data member "item" to the item that you pass             */
/******************************************************************************/
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
} // end setItem

/******************************************************************************/
/* Method: setNext		     												  */
/* Inputs: A pointer to a Node "nextNodePtr"                                  */
/* Outputs: None                                                              */
/* Purpose: To assign the Node after this one                                 */
/******************************************************************************/
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
} // end setNext

/******************************************************************************/
/* Method: getLine		                                                      */
/* Inputs: None                                                               */
/* Outputs: A ItemType "item"                                                 */
/* Purpose: To retrieve the data member that this Node stores                 */
/******************************************************************************/
template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
} // end getItem

/******************************************************************************/
/* Method: getNext		                                                      */
/* Inputs: None                                                               */
/* Outputs: A pointer to a node "next"                                        */
/* Purpose: To retrieve the Node after this one                               */
/******************************************************************************/
template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
} // end getNext 
