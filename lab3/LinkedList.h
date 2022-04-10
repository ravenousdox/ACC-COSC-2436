/** ADT bag: Link-based implementation.
	@file LinkedList.h */

#ifndef _LINKED_LIST
#define _LINKED_LIST

#include <vector>
#include "Node.h"

class LinkedList {
private:
	Node* headPtr;		// A pointer to a Node that represents the head of the list
	int lineCount;		// A counter that holds the number of lines in the list
	
public:
	LinkedList();
	virtual ~LinkedList();
	
	// Returns the number of lines in the LinkedList
	int getNumLines() const;
	
	// Returns a vector filled with the lines held by the LinkedList
	std::vector<std::string> toVector() const;
	
	// Returns true if the line was successfully added and false if not
	bool addLine(const std::string& newLine);
	
}; // end LinkedList

#include "LinkedList.cpp"
#endif 
