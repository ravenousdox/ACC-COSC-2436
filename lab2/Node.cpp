/** @file Node.cpp */
#include "Node.h"

//A constructor given no arguments
Node::Node() : line(""), next(nullptr)
{
} // end default constructor

//A constructor given just a data member
Node::Node(const std::string& aLine) : line(aLine), next(nullptr)
{
} // end constructor

//A constructor given a data member and pointer to the next node
Node::Node(const std::string& aLine, Node* nextNodePtr) : line(aLine), next(nextNodePtr)
{
} // end constructor

/******************************************************************************/
/* Method: setLine  								      					  */
/* Inputs: A constant reference to a string "aLine"                           */
/* Outputs: None                                                              */
/* Purpose: Sets the data member "line" to the string that you pass           */
/******************************************************************************/
void Node::setLine(const std::string& aLine)
{
	line = aLine;
} // end setLine

/******************************************************************************/
/* Method: setNext		     												  */
/* Inputs: A pointer to a Node "nextNodePtr"                                  */
/* Outputs: None                                                              */
/* Purpose: To assign the Node after this one                                 */
/******************************************************************************/
void Node::setNext(Node* nextNodePtr)
{
	next = nextNodePtr;
} // end setNext

/******************************************************************************/
/* Method: getLine		                                                      */
/* Inputs: None                                                               */
/* Outputs: A string "line"                                                   */
/* Purpose: To retrieve the data member that this Node stores                 */
/******************************************************************************/
std::string Node::getLine() const
{
	return line;
} // end getLine

/******************************************************************************/
/* Method: getNext		                                                      */
/* Inputs: None                                                               */
/* Outputs: A pointer to a node "next"                                        */
/* Purpose: To retrieve the Node after this one                               */
/******************************************************************************/
Node* Node::getNext() const
{
	return next;
} // end getNext 
