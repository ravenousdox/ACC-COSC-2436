/******************************************************************************/
/* Program Description: 
/* Displays a menu to the user and prompts for a choice
/* The user can choose a choice from 1-7
/* These choices allow the user to display, store, remove, sort, and search
/* (using one of two algorithms) a containers contents.
/* Additionally, the user can exit the program.
/******************************************************************************/

#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;

void displayMenu();
void displayContents(const ArrayBag<int> &bag);
void addElement(ArrayBag<int> &bag, bool &bagSorted);
void removeElement(ArrayBag<int> &bag, bool &bagSorted);
void searchRecursive(const ArrayBag<int>& bag, bool &bagSorted);
void searchIterative(const ArrayBag<int>& bag, bool &bagSorted);
void sortContents(ArrayBag<int>& bag, bool &bagSorted);
void loadValues(ArrayBag<int>& bag);
void menuChoice(ArrayBag<int>& bag);

//Declares an ArrayBag
//Loads values into the ArrayBag
//Displays the Menu
//Takes in the choice by the user
int main()
{
	ArrayBag<int> bag;
	
	loadValues(bag);
	displayMenu();
	menuChoice(bag);
	
	return 0;
}  // end main

/******************************************************************************/
/* Function:   displayMenu
/* Inputs:     None
/* Outputs:    None
/* Purpose:    Displays the list of choices the user can take
/******************************************************************************/
void displayMenu() {
	cout << "Enter the number to the corresponding option you would like\n";
	cout << "-----------------------------------------------------------\n";
	cout << "1. Display the contents of the bag\n";
	cout << "2. Add an element to the bag\n";
	cout << "3. Remove an element from the bag\n";
	cout << "4. Sort the bag's elements\n";
	cout << "5. Recursively search for an element\n";
	cout << "6. Iteratively search for an element\n";
	cout << "7. Exit the program\n";
	cout << "-----------------------------------------------------------\n\n";
} // end displayMenu

/******************************************************************************/
/* Function:   menuChoice
/* Inputs:     A constant reference to an integer ArrayBag,
/* Outputs:    None
/* Purpose:    Prompts the user to enter a choice and routes the
/*	       	   subsequent flow of the program
/******************************************************************************/
void menuChoice(ArrayBag<int>& bag) {
	int userChoice = 0;
	bool bagSorted = false;
	
	//While the user does not want to exit the program...
	while (userChoice != 7) {
		//Attempts to achieve an integer only result from the user
		cout << "Enter your choice: ";
		cin >> userChoice;
		cin.clear();
		cin.ignore(123, '\n');
		
		//Routes the flow of the program to the appropriate function
		//based on the user's choice. Displays the menu after the choice is made.
		switch (userChoice) {
			case 1:
				displayContents(bag);
				displayMenu();
				break;
				
			case 2:
				addElement(bag, bagSorted);
				displayMenu();
				break;
				
			case 3:
				removeElement(bag, bagSorted);
				displayMenu();
				break;
				
			case 4:
				sortContents(bag, bagSorted);
				displayMenu();
				break;
				
			case 5:
				searchRecursive(bag, bagSorted);
				displayMenu();
				break;
				
			case 6: 
				searchIterative(bag, bagSorted);
				displayMenu();
				break;
				
			case 7:
				cout << "Program is exiting...\n";
				break;
				
			default:
				cout << "Not a valid option. Enter again\n\n";
		}
	}	
} // end menuChoice

/******************************************************************************/
/* Function:   displayContents
/* Inputs:     A constant reference to an integer ArrayBag
/* Outputs:    None
/* Purpose:    Handles the choice of displaying the contents of the
/*             integer ArrayBag
/******************************************************************************/
void displayContents(const ArrayBag<int> &bag) {
	//Converts the ArrayBag to a vector and outputs
	//its contents
	vector<int> vectorBag = bag.toVector();
	cout << "Contents of the bag include: ";
	for (int i = 0; i < vectorBag.size(); i++) {
		cout << vectorBag[i] << " ";
	}
	cout << "\n\n";
}	// end displayContents

/******************************************************************************/
/* Function:   addElement
/* Inputs:     A constant reference to an integer ArrayBag,
/*             A reference to the boolean bagSorted
/* Outputs:    None
/* Purpose:    Handles the choice of adding elements to the integer 
/*             ArrayBag
/******************************************************************************/
void addElement(ArrayBag<int> &bag, bool &bagSorted) {
	int element;
	
	cout << "Enter the element you wish to add: ";
	
	//Attempts to achieve an integer only result
	while (!(cin >> element)) {
		cout << "Integer values only. Input element again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	
	//Checks if the bag contains the element
	//If not, attempts to add the element
	//If the add method fails, prompts the user with the message that the bag is already full
	//Else, tells the user that the operation was successful			
	if (bag.contains(element)) {
		cout << "Bag already contains that element. Element not added\n\n";
	} else if (!(bag.add(element))) {
		cout << "Bag is already full. Element not added\n\n";
	} else {
		cout << "Element successfully added\n\n";
		bagSorted = false;
	}
} // end addElement

/******************************************************************************/
/* Function:   removeElement
/* Inputs:     A constant reference to an integer ArrayBag,
/*	           A reference to the boolean bagSorted
/* Outputs:    None
/* Purpose:    Handles the choice of removing elements from the
/*	           integer ArrayBag
/******************************************************************************/
void removeElement(ArrayBag<int> &bag, bool &bagSorted) {
	int element;
	
	cout << "Enter the element you wish to remove: ";
	
	//Attempts to achieve an integer only result
	while (!(cin >> element)) {
		cout << "Integer values only. Input element again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	
	//Attempts the remove method
	//Tells the user whether the operation was successful			
	if (bag.remove(element)) {
		cout << "Element successfully removed\n\n";
		bagSorted = false;
	} else {
		cout << "Bag does not contain that element. Element not removed\n\n";
	}
} // end removeElement

/******************************************************************************/
/* Function:   searchRecursive
/* Inputs:     A constant reference to an integer ArrayBag,
/*	           A reference to the boolean bagSorted
/* Outputs:    None
/* Purpose:    Handles the choice of searching for elements in the 
/*             integer ArrayBag using recursive binary search
/******************************************************************************/
void searchRecursive(const ArrayBag<int>& bag, bool &bagSorted) {
	//If the bag is sorted, attempt the search
	//Else, tell the user they need to sort the bag
	if (bagSorted) {
		int element; 
		cout << "Enter the element you wish to search for: ";
		
		//Attempts to achieve an integer only result
		while (!(cin >> element)) {
			cout << "Integer values only. Input element again: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
		
		int result = bag.binarySearchRecursiveHelper(element);
		//If the result signified the element was not found, tell the user
		//Else, tell the user the index at which the element was found
		(result == -1) ? cout << "Element " << element << " not found\n\n" : cout << "Element " << element << " found at position " << result << "\n\n";
	} else {
		cout << "You must first sort the bag before searching\n\n";
	}
} // end searchRecursive

/******************************************************************************/
/* Function:   searchIterative
/* Inputs:     A constant reference to an integer ArrayBag,
/*	           A reference to the boolean bagSorted
/* Outputs:    None
/* Purpose:    Handles the choice of searching for elements in the 
/*	           integer ArrayBag using recursive iterative search
/******************************************************************************/
void searchIterative(const ArrayBag<int>& bag, bool &bagSorted) {
	//If the bag is sorted, attempt the search
	//Else, tell the user they need to sort the bag
	if (bagSorted) {
		int element;
		cout << "Enter the element you wish to search for: ";
		
		//Attempts to achieve an integer only result
		while (!(cin >> element)) {
		cout << "Integer values only. Input element again: ";
		cin.clear();
		cin.ignore(123, '\n');
		}
		
		int result = bag.binarySearchIterative(element);
		//If the result signified the element was not found, tell the user
		//Else, tell the user the index at which the element was found
		(result == -1) ? cout << "Element " << element << " not found\n\n" : cout << "Element " << element << " found at position " << result << "\n\n";
	} else {
		cout << "You must first sort the bag before searching\n\n";
	}
} // end searchIterative

/******************************************************************************/
/* Function:   sortContents
/* Inputs:     A constant reference to an integer ArrayBag,
/*	           A reference to the boolean bagSorted
/* Outputs:    None
/* Purpose:    Handles the choice of sorting the elements in the
/*             integer ArrayBag
/******************************************************************************/
void sortContents(ArrayBag<int>& bag, bool &bagSorted) {
	bag.bubbleSort();
	bagSorted = true;
	cout << "Bag has been sorted\n\n";
} // end sortContents

/******************************************************************************/
/* Function:   loadValues
/* Inputs:     A constant reference to an integer ArrayBag
/* Outputs:    None
/* Purpose:    Fills the integer ArrayBag with values
/******************************************************************************/
void loadValues(ArrayBag<int>& bag) {
	//For each item in items, add that item to the bag
	int items[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51};
	for (int i = 0; i < sizeof(items)/sizeof(items[0]); i++) {
		bag.add(items[i]);
	}
} // end initBag



