/** client file
@file client.cpp */

/******************************************************************************/
/* Program Description: 
/* Opens a file containing employee data and stores it inside a binary 
/* search tree. The user can select options from a menu to perform operations 
/* on the data.
/******************************************************************************/

#include "EmployeeTree.h"
#include "menu.cpp"
#include <iostream>
#include <fstream>

void grabFile(ifstream& file);
void readLines(ifstream& file, EmployeeTree& employeeRoster);
void display(EmployeeInfo* employeePtr);

int main() {
	EmployeeTree employeeRoster;		// Creates a binary search tree that holds employees
	ifstream file;						// A file object for reading employee data into the tree
	int selection;						// The user's selection from the menu
	
	cout << "DISCLAIMERS:\n";
	cout << "1) Enter valid arguments for the options\n";
	cout << "2) You navigate the menu using the up and down arrow keys and press enter to make a selection\n";
	cout << "3) Attempting to full screen the terminal during selection will cause a visual bug\n\n";
	
	grabFile(file);						// Attempts to grab the employee data file from the user
	readLines(file, employeeRoster);		// Reads the employee data into the tree from the file
	
	cout << '\n';
	
	string choices[] = {"Display Employee", "Search for an Employee", "Add an Employee", "Remove an Employee", "Exit"};		// An array of menu choices that can be selected
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
				employeeRoster.inorderTraverse(display);
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
				
				if (employeeRoster.contains(searchID))
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
				employeeRoster.addEmployee(employeeID, employeeName);
				cout << '\n';
				break;
			}
			
			// Removes an employee from the tree
			case 3:
			{
				int removeID;
				cout << "\nEnter the ID of the employee you are removing: ";
				cin >> removeID;
				if (employeeRoster.removeEmployee(removeID))
					cout << "\nRemoval successful!\n\n";
				else 
					cout << "\nEmployee not found\n\n";
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
/* Function: readEmployeeInfoData                                                 */
/* Inputs: A constant reference to the file object, A constant reference to   */
/*         the employee tree                                                  */
/* Outputs: None                                                              */
/* Purpose: To read the employee data from the file, attempting to add an     */
/*          employee with that data to the tree                               */
/******************************************************************************/
void readLines(ifstream& file, EmployeeTree& employeeRoster) {
	string employeeID;
	string employeeName;

	// While it has not reached EOF
	while (file) {
		getline(file, employeeID, ' ');								// Read the employee ID
		getline(file, employeeName);								// Read the employee name
		employeeRoster.addEmployee(stoi(employeeID), employeeName);   // Add the employee to the tree
	}

}

/******************************************************************************/
/* Function: display                                                          */
/* Inputs: A pointer to an employee                                           */
/* Outputs: None                                                              */
/* Purpose: To display an employee's ID and name                              */
/******************************************************************************/
void display(EmployeeInfo* employeePtr) {
	cout << employeePtr->getID() << " | " << employeePtr->getName() << '\n';
}

//[](EmployeeInfo* employeePtr){ cout << employeePtr->getID() << " | " << employeePtr->getName() << endl; }
