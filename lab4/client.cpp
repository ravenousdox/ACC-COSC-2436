/** client file
@file client.cpp */

/******************************************************************************/
/* Program Description: 
/* Opens a file containing employee data and stores it inside a binary 
/* search tree. The user can select options from a menu to perform operations 
/* on the data.
/******************************************************************************/

#include "BinarySearchTree.h"	//Maybe change to employeeTree and var to like employee list idk roster
#include "menu.cpp"
#include <iostream>
#include <fstream>

void grabFile(ifstream& file);
void readLines(ifstream& file, BinarySearchTree& employeeTree);
void display(Employee* employeePtr);

int main() {
	BinarySearchTree employeeTree;		// Creates a binary search tree that holds employees
	ifstream file;						// A file object for reading employee data into the tree
	int selection;						// The user's selection from the menu
	
	cout << "DISCLAIMERS:\n";
	cout << "1) Removing an employee does not work for employees with two children\n";
	cout << "2) Enter valid arguments for the options\n";
	cout << "3) You navigate the menu using the up and down arrow keys and press enter to make a selection\n";
	cout << "4) Attempting to full screen the terminal during selection will cause a visual bug\n\n";
	
	grabFile(file);						// Attempts to grab the employee data file from the user
	readLines(file, employeeTree);		// Reads the employee data into the tree from the file
	
	cout << '\n';
	
	string choices[] = {"Display Employees", "Search for an Employee", "Add an Employee", "Remove an Employee", "Exit"};		// An array of menu choices that can be selected
	int size = sizeof(choices)/sizeof(choices[0]);																				// The number of choices
	
	do {

		// Prompt the menu and store the user's choice in selection
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		selection = menu(choices, size);																
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		
		// Directs the choice made by the user
		switch(selection) 
		{	
			// Displays each employee in sorted order
			case 0:
			{	
				cout << '\n';
				employeeTree.inorderTraverse(display);
				cout << '\n';
				break;
			}
			
			// Searches for an employee by ID
			case 1:
			{
				int searchID;
				cout << "\nEnter an employee ID to search for: ";
				cin >> searchID;
				cin.ignore();
				
				if (employeeTree.contains(searchID))
					cout << "Employee matching ID found!\n\n";
				else
					cout << "Employee matching ID not found\n\n";
					
				break;
			}
			
			// Adds an employee to the tree
			case 2:
			{
				int employeeID;
				string employeeName;
				cout << "\nEnter the ID of the employee you are adding: ";
				cin >> employeeID;
				cin.ignore();
				cout << "Enter the name of the employee you are adding: ";
				getline(cin, employeeName);
				employeeTree.addEmployee(employeeID, employeeName);
				cout << '\n';
				break;
			}
			
			// Removes an employee from the tree
			case 3:
			{
				int removeID;
				cout << "\nEnter the ID of the employee you are removing: ";
				cin >> removeID;
				employeeTree.removeEmployee(removeID);
				cout << '\n';
				break;
			}
		}
	} while (selection != 4);	// While the user has not chosen to quit

	return 0;
}

/******************************************************************************/
/* Function: grabFile		                                                  */
/* Inputs: A constant reference to a file object                              */
/* Outputs: None                                                              */
/* Purpose: To properly retrieve the file name from the user and open the     */
/*          file                                                              */
/******************************************************************************/
void grabFile(ifstream& file) {
	string fileName;	// The name of the file
	
	// Prompts the user for the filename
	cout << "Input the file to be read without the extension: ";
	cin >> fileName;
	
	//Creates a file object linked to fileName
	file.open(fileName + ".txt"); 

	//If the file could not be properly opened, prompt the user until a valid file is chosen
	while (!file) {
		cerr << "\nFile \"" << fileName << ".txt\" does not exist or cannot be found.\n";
		cout << "\nRe-enter the employee data file to be read without the extension: ";
		cin >> fileName;
		file.open(fileName + ".txt");
	}
	
}

/******************************************************************************/
/* Function: readEmployeeData                                                 */
/* Inputs: A constant reference to the file object, A constant reference to   */
/*         the employee tree                                                  */
/* Outputs: None                                                              */
/* Purpose: To read the employee data from the file, attempting to add an     */
/*          employee with that data to the tree                               */
/******************************************************************************/
void readLines(ifstream& file, BinarySearchTree& employeeTree) {
	string employeeID;
	string employeeName;

	// While it has not reached EOF
	while (file) {
		getline(file, employeeID, ' ');								// Read the employee ID
		getline(file, employeeName);								// Read the employee name
		employeeTree.addEmployee(stoi(employeeID), employeeName);   // Add the employee to the tree
	}

}

/******************************************************************************/
/* Function: display                                                          */
/* Inputs: A pointer to an employee                                           */
/* Outputs: None                                                              */
/* Purpose: To display an employee's ID and name                              */
/******************************************************************************/
void display(Employee* employeePtr) {
	cout << employeePtr->getID() << " | " << employeePtr->getName() << '\n';
}

//[](Employee* employeePtr){ cout << employeePtr->getID() << " | " << employeePtr->getName() << endl; }
