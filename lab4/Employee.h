/** A class of nodes for a link-based binary tree.
@file Employee.h */

#ifndef _EMPLOYEE
#define _EMPLOYEE

#include <string>

using namespace std;

class Employee
{
	private:
		int id; 					// The ID of the employee
		string name;                // The name of the employee
		Employee* leftChildPtr;     // An employee with an ID less than this employee
		Employee* rightChildPtr;    // An employee with an ID greater than this employee
		
	public:

		Employee();                           // Default constructor
		Employee(int anID, string aName);     // Customized constructor given employee data 
		
		// Returns none
		void setName(string aName);
		void setID(int anID);
		void setLeftChildPtr(Employee* leftPtr);
		void setRightChildPtr(Employee* rightPtr);
		
		// Returns the ID of the employee
		int getID() const;
		
		// Returns the name of the employee
		string getName() const;
		
		// Returns the left child of the employee or nullptr
		Employee* getLeftChildPtr() const;
		
		// Returns the right child of the employee or nullptr
		Employee* getRightChildPtr() const;
		
		// Returns true if the employee has no children
		bool isLeaf() const;
		
}; // end Employee

#include "Employee.cpp"
#endif 
