/** @file Node.h */
#ifndef _NODE
#define _NODE

#include <string>

class Node 
{
	private:
		std::string line;
		Node* next;
		
	public:
		Node();
		Node(const std::string& aLine);
		Node(const std::string& aLine, Node* nextNodePtr);
	
		void setLine(const std::string& aLine);
		void setNext(Node* nextNodePtr);
		
		// Returns the string data member held by the Node
		std::string getLine() const;
		
		// Returns the pointer to the next Node after this one
		Node* getNext() const;
}; // end Node

#include "Node.cpp"
#endif
