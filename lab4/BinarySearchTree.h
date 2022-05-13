/** Link-based implementation of the ADT binary search tree.
@file BinarySearchTree.h */

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "Employee.h"
#include <iostream>
//#include "NotFoundException.h"
//#include "PrecondViolatedExcep.h"

class BinarySearchTree {
	private:
		Employee* rootPtr;    // The root node of the binary search tree
		
	protected:

	    // Returns the updated subtree with the new employee added
		Employee* addHelper(Employee* subTreePtr, Employee* newEmployeePtr);	
		
		// Returns the employee matching the ID OR nullptr if not found
		Employee* findEmployee(Employee* subTreePtr, int targetID) const;			
		
		// Returns none
		void destroyTree(Employee* subTreePtr);										
		
		// Returns none
		void inorderHelper(void visit(Employee*), Employee* subTreePtr) const;	
		
		// Returns a pointer to the updated subtree with the employee removed OR nullptr if not found
		Employee* removeFinder(Employee* subTreePtr, int targetID, bool& success);	
		
		// Returns a pointer to the updated subtree with the employee removed
		Employee* removeHelper(Employee* employeePtr);						
		
		// Returns the inorder successor of an employee (the employee with the smallest ID greater than the one being removed)
		Employee* findLeftmostEmployee(Employee* employeePtr);
		
	public:
		BinarySearchTree();							// Default constructor
		BinarySearchTree(int id, string name);      // Customized constructor given employee data
		virtual ~BinarySearchTree();                // Customized destructor
		
		// Returns none
		void clear();

		// Returns true if addition was successful, false otherwise
		bool addEmployee(int id, string name);
		
		// Returns true if removal was successful, false otherwise
		bool removeEmployee(int targetID);
		
		// Returns true if employee matching ID was found in tree, false otherwise
		bool contains(int targetID) const;
	
	    // Returns none
		void inorderTraverse(void visit(Employee*)) const;				
		
}; // end BinarySearchTree

#include "BinarySearchTree.cpp"
#endif 
