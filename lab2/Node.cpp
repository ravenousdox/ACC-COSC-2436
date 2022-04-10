/** @file Node.cpp */

#include "Node.h"
#include <cstddef>

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
} // end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
} // end constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{
} // end constructor

/******************************************************************************/
/* Method: setItem							      							  */
/* Inputs: A constant reference to an item of type ItemType 		          */
/* Outputs: None                                                              */
/* Purpose: Sets the contents of the node                                     */
/******************************************************************************/
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
} // end setItem

/******************************************************************************/
/* Method: setNext							      							  */
/* Inputs: A pointer to a a node of type ItemType 	             	          */
/* Outputs: None                                                              */
/* Purpose: Sets the next address of the node to the same as the pointer      */
/*          passed                                                            */
/******************************************************************************/
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
} // end setNext

/******************************************************************************/
/* Method: getItem                       								      */
/* Inputs: None                                                               */
/* Outputs: Contents of type ItemType                                         */
/* Purpose: To retrieve the contents at the node in the chain                 */
/******************************************************************************/
template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
} // end getItem

/******************************************************************************/
/* Method: getNext                         								      */
/* Inputs: None                                                               */
/* Outputs: An address to the next node in the chain                          */
/* Purpose: To retrive the address of the next node in the chain              */
/******************************************************************************/
template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
} // end getNext 
