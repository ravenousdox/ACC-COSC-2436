/** @file LinkedList.cpp */
#include "LinkedList.h"

//A constructor given no arguments will implicitly assign headPtr to nullptr and lineCount to 0
LinkedList::LinkedList() : headPtr(nullptr), lineCount(0)
{
} // end default constructor

//A destructor that frees each Node in the list until it is empty
LinkedList::~LinkedList()
{
	
	while (headPtr != nullptr)				//While headPtr points to a node...
	{
 		Node* nodeToDeletePtr = headPtr;	//Store the node so you do not lose it
 		headPtr = headPtr->getNext();		//Move to the next node
		nodeToDeletePtr->setNext(nullptr);	//Disconnect the node from the list
		delete nodeToDeletePtr;				//Delete the node
 	} // end while
 	
 	//nodeToDeletePtr = nullptr;			//At the end, safeguard from dangling pointer
 	lineCount = 0;							//Set the number of lines there are to zero
 	
} // end destructor 

/******************************************************************************/
/* Method: getNumLines                                                        */
/* Inputs: None                                                               */
/* Outputs: An integer "lineCount"                                            */
/* Purpose: To identify how many lines are held by the list                   */
/******************************************************************************/
int LinkedList::getNumLines() const
{
	return lineCount;
} // end getCurrentSize 

/******************************************************************************/
/* Method: toVector                                                           */
/* Inputs: None                                                               */
/* Outputs: A vector of type string that holds the lines held by the list     */
/* Purpose: Used to display the lines held by the list                        */
/******************************************************************************/
std::vector<std::string> LinkedList::toVector() const
{
	std::vector<std::string> lines;							//Create a vector that holds strings
	Node* curPtr = headPtr;									//Create a pointer for traversing the list
	int counter = 0;										//A safeguard to ensure you don't go over line count				
	
	while ((curPtr != nullptr) && (counter < lineCount)) 	//While you have not reached end of list...
	{
		lines.push_back(curPtr->getLine());					//Store the line at that node in the vector
		curPtr = curPtr->getNext();							//Move to the next node
		counter++;
	} // end while
	
	return lines;											//Return the vector
} // end toVector

/******************************************************************************/
/* Method: addLine						                                      */
/* Inputs: A constant reference to a string "newLine"                         */
/* Outputs: True if the addition was successful, false otherwise              */
/* Purpose: To insert a line into the LinkedList at the proper location such  */
/*          that the lines are in ascending order                             */
/******************************************************************************/
bool LinkedList::addLine(const std::string& newLine) {
	bool additionSuccessful = true;										//Defaults to true so less assignments are made

	if (headPtr == nullptr || headPtr->getLine() < newLine) {			//If list is empty or first entry is less than entry being inserted
		Node* newNodePtr = new Node(newLine, headPtr);					//Insert at the head of the list
		headPtr = newNodePtr;
	} else {															//Else, find the proper insertion point
		Node* curPtr = headPtr;
		Node* prevPtr = nullptr;
		while (curPtr != nullptr && curPtr->getLine() >= newLine) {		//Traverse the list until you hit the end or find an entry greater than or equal to yours
			prevPtr = curPtr;											//I can simplify the code if I compare prevPtr in the case its a duplicate, 
			curPtr = curPtr->getNext();									//That is why I let it move to the next node when it is equal
		}
		if (prevPtr->getLine() != newLine) {							//If not duplicate, insert between prevPtr and curPtr
			Node* newNodePtr = new Node(newLine, curPtr);				//This includes the case curPtr == nullptr
			prevPtr->setNext(newNodePtr);
		} else {
			additionSuccessful = false;									//If no insertion was made, it is a duplicate
		}
	}
	
	if (additionSuccessful) {											//Increase the count of lines in the list if an insertion was made
		lineCount++;
	}
	
	return additionSuccessful;											//Return whether addition was successful
}
