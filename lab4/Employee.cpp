/** A class of nodes for a link-based binary tree.
@file Employee.cpp */

#include "Employee.h"

// Default constructor
Employee::Employee() : id(0), name(""), leftChildPtr(nullptr), rightChildPtr(nullptr)
{
} // end default constructor

// Customized constructor given employee data
Employee::Employee(int anID, string aName) : id(anID), name(aName), leftChildPtr(nullptr), rightChildPtr(nullptr)
{
} // end constructor

/******************************************************************************/
/* Method: setID				                                              */
/* Inputs: An integer representing the ID of the employee                     */
/* Outputs: None                                                              */
/* Purpose: To set the ID of an employee                                      */
/******************************************************************************/
void Employee::setID(int anID)
{
	id = anID;
} // end setItem

/******************************************************************************/
/* Method: setName		                                                      */
/* Inputs: A string representing the name of the employee                     */
/* Outputs: None                                                              */
/* Purpose: To set the name of an emplyoee                                    */
/******************************************************************************/
void Employee::setName(string aName)
{
	name = aName;
} // end setItem

/******************************************************************************/
/* Method: setLeftChildPtr                                                    */
/* Inputs: A pointer to an employee                                           */
/* Outputs: None                                                              */
/* Purpose: To set the left child of the employee                             */
/******************************************************************************/
void Employee::setLeftChildPtr(Employee* leftPtr)
{
	leftChildPtr = leftPtr;
} // end setNext

/******************************************************************************/
/* Method: setRightChildPtr                                                   */
/* Inputs: A pointer to an employee                                           */
/* Outputs: None                                                              */
/* Purpose: To set the right child of the employee                            */
/******************************************************************************/
void Employee::setRightChildPtr(Employee* rightPtr)
{
	rightChildPtr = rightPtr;
} // end setNext

/******************************************************************************/
/* Method: getID 								                              */
/* Inputs: None                                                               */
/* Outputs: An integer, the ID of the employee                                */
/* Purpose: To get the ID of an employee                                      */
/******************************************************************************/
int Employee::getID() const
{
	return id;
} // end getItem

/******************************************************************************/
/* Method: getName		                                                      */
/* Inputs: None                                                               */
/* Outputs: A string, the name of the employee                                */
/* Purpose: To get the name of the employee                                   */
/******************************************************************************/
string Employee::getName() const
{
	return name;
} // end getName

/******************************************************************************/
/* Method: getLeftChildPtr                                                    */
/* Inputs: None                                                               */
/* Outputs: A pointer to an employee, the left child of this employee         */
/* Purpose: To get the left child of this employee                            */
/******************************************************************************/
Employee* Employee::getLeftChildPtr() const
{
	return leftChildPtr;
} // end getLeftChildPtr

/******************************************************************************/
/* Method: getRightChildPtr                                                   */
/* Inputs: None                                                               */
/* Outputs: A pointer to an employee, the right child of this employee        */
/* Purpose: To get the right child of this employee                           */
/******************************************************************************/
Employee* Employee::getRightChildPtr() const
{
	return rightChildPtr;
} // end getRightChildPtr

/******************************************************************************/
/* Method: isLeaf                                                             */
/* Inputs: None                                                               */
/* Outputs: A boolean on whether the employee has no children                 */
/* Purpose: To determine whether the employee is a leaf node                  */
/******************************************************************************/
bool Employee::isLeaf() const 
{
	return (leftChildPtr == nullptr && rightChildPtr == nullptr);
}
