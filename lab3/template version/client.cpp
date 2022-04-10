#include <fstream>
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

void grabFile(ifstream& file);
int readLines(ifstream& file, LinkedList<string>& list);

int main() {
	LinkedList<string> list;
	ifstream file;
	
	grabFile(file);														//Grabs the file object
	int linesRead = readLines(file, list);								//Stores the number of lines read from the file
	
	cout << "\nNumber of lines read: " << linesRead << '\n';
	
	vector<string> listVector = list.toVector();						// Converts list to a vector
	cout << "Number of lines in list: " << listVector.size() << '\n';   // Outputs the number of lines in the vector

	// Displays the lines in the list
	cout << "\n--------------------------------------LINES------------------------------------\n";
	for (int i = 0; i < list.getCurrentSize(); i++) 					// Traverses the vector
		cout << "Line " << i + 1 << ": " << listVector[i] << '\n';		// Outputting each line in the vector
	cout << "-------------------------------------------------------------------------------\n";

	return 0;	
}

/******************************************************************************/
/* Function: grabFile		                                                  */
/* Inputs: A constant reference to a string that is the fileName of the file  */
/*         being opened. A constant reference to a file object                */
/* Outputs: None                                                              */
/* Purpose: To properly retrieve the file name from the user and open the     */
/*          file                                                              */
/******************************************************************************/
void grabFile(ifstream& file) {
	string fileName;
	
	cout << "Input the file to be read without the extension: ";
	cin >> fileName;
	
	//Creates a file object linked to fileName
	file.open(fileName + ".txt"); 

	//If the file could not be properly opened, prompt the user until a valid file is chosen
	while (!file) {
		cerr << "\nFile \"" << fileName << ".txt\" does not exist or cannot be found.\n";
		cout << "\nRe-enter the auction file to be read without the extension: ";
		cin >> fileName;
		file.open(fileName + ".txt");
	}
	
}

/******************************************************************************/
/* Function: readLines                                                        */
/* Inputs: A constant reference to the file object, A constant reference to   */
/*         the LinkedList object                                              */
/* Outputs: The number of lines read from the file                            */
/* Purpose: To read the file line by line, attempting to insert those lines   */
/*          into the list. To retrieve how many lines are in the file.        */
/******************************************************************************/
int readLines(ifstream& file, LinkedList<string>& list) {
	int numLines = 0;
	string line;
	
	while (getline(file, line)) {
		list.addItem(line);
		numLines++;
	}
	
	return numLines;
}

