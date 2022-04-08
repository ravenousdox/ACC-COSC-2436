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
	int counter = 0;							
	
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
	
	bool additionSuccessful = false;

	// If the list is empty, have it be the first Node in the list
	if (headPtr == nullptr) {			
	    headPtr = new Node(newLine);
	    lineCount++;
	    additionSuccessful = true;
			
	} else {
		
		// If the list is not empty, check the first node	
		// If the line you are inserting is less than the first line in the list...
		// Insert at the head of the list
		
		// This is required because prevPtr->setNext() is not valid when prevPtr does not point to a node...
		// ... which occurs if curPtr does not advance... which occurs if the first line in the list is 
		// greater than the one you are inserting
		
		if (newLine < headPtr->getLine()) {	
			Node* newNodePtr = new Node(newLine, headPtr);
			headPtr = newNodePtr;
			lineCount++;
			additionSuccessful = true;
			
		} else {
			// Else... you must traverse the list to find the proper insertion point
			
			Node* curPtr = headPtr;		//A pointer to traverse the list starting at the head
			Node* prevPtr = nullptr;	//A pointer to hold the node previous to the one you are on
			
			// While you have not reached the end of the list
			// AND have not encountered a line that is greater than the one you are inserting...
			// Move to the next node
		    while ((curPtr != nullptr) && (newLine > curPtr->getLine())) {	
		        prevPtr = curPtr;
		        curPtr = curPtr->getNext();
		    }
	
			//As long as the line is not a duplicate...
			//Insert the node between prevPtr and curPtr
		    if (curPtr->getLine() != newLine) { 
		    	Node* newNodePtr = new Node(newLine, curPtr);
		        prevPtr->setNext(newNodePtr);
		        lineCount++;
		        additionSuccessful = true;
		    }
		}
	}
	return additionSuccessful;
}
