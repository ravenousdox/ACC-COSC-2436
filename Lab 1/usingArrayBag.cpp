/******************************************************************************/
/* Program Description: 
/******************************************************************************/

#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;

void displayMenu();

int main()
{
	int userChoice;
	ArrayBag<int> bag;
	int items[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};
	int element;
	bool bagSorted = false;
	
	for (int i = 0; i < sizeof(items)/sizeof(items[0]); i++) {
		bag.add(items[i]);
	}
	
	vector<int> vectorBag;
	displayMenu();
	
	while (userChoice != 8) {
		cout << "Enter your choice: ";
		cin >> userChoice;
		switch (userChoice) {
			case 1:
				cout << "Contents of the bag include: ";
				vectorBag = bag.toVector();
				for (int i = 0; i < vectorBag.size(); i++) {
					cout << vectorBag[i] << " ";
				}
				cout << "\n\n";
				break;
				
			case 2:
				cout << "Enter the element you wish to add: ";
				
				while (!(cin >> element)) {
					cout << "Integer values only. Input element again: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				
				if (!bag.contains(element) && bag.add(element)) {
					cout << "Element successfully added\n\n";
					bagSorted = false;
				} else {
					cout << "Bag is already full or already contains that element. Element not added\n\n";
				}
				break;
				
			case 3:
				cout << "Enter the element you wish to remove: ";
				
				while (!(cin >> element)) {
					cout << "Integer values only. Input element again: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				
				if (bag.remove(element)) {
					cout << "Element successfully removed\n\n";
					bagSorted = false;
				} else {
					cout << "Bag does not contain that element. Element not removed\n\n";
				}
				break;
				
			case 4:
				bag.bubbleSort();
				cout << "Bag has been sorted\n\n";
				bagSorted = true;
				break;
				
			case 5:
				if (bagSorted) {
					cout << "Enter the element you wish to search for: ";
					
					while (!(cin >> element)) {
						cout << "Integer values only. Input element again: ";
						cin.clear();
						cin.ignore(123, '\n');
					}
				
					int result = bag.binarySearchRecursive(element, 0, bag.getCurrentSize());
					(result == -1) ? cout << "Element " << element << " not found\n\n" : cout << "Element " << element << " found at index " << result << "\n\n";
				} else {
					cout << "You must first sort the bag before searching\n\n";
				}
				break;
				
			case 6: 
				if (bagSorted) {
					int element;
					cout << "Enter the element you wish to search for: ";
					
					while (!(cin >> element)) {
					cout << "Integer values only. Input element again: ";
					cin.clear();
					cin.ignore(123, '\n');
					}
					
					int result = bag.binarySearchIterative(element);
					(result == -1) ? cout << "Element " << element << " not found\n\n" : cout << "Element " << element << " found at index " << result << "\n\n";
				} else {
					cout << "You must first sort the bag before searching\n\n";
				}
				break;
				
			case 7:
				cout << "\n";
				displayMenu();
				break;
				
			case 8:
				cout << "Program is exiting...\n";
				break;
				
			default:
				cout << "Not a valid option. Enter again\n\n";
				cin.clear();
				cin.ignore(123, '\n');
		}
	}
		return 0;
}  // end main

/******************************************************************************/
/* Function:   functionName
/* Inputs:       parameters passed and what they represent
/* Outputs:    value(s) returned via return statemen or
/*                     on the parameter list
/* Purpose:    This function blah blah blah….. describing what
/*                     the function does
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
	cout << "7. Display this menu again\n";
	cout << "8. Exit the program\n";
	cout << "-----------------------------------------------------------\n\n";
}




