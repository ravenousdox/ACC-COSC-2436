#include <fstream>
#include <iostream>
#include <iomanip>
#include "LinkedList.h"
using namespace std;

void grabFile(ifstream& file);
int readLines(ifstream& file, LinkedList& list);
void displayLines(const LinkedList& list);

int main() {
	LinkedList list;
	ifstream file;
	
	grabFile(file);
	cout << "grabFile executed" << '\n';
	int linesRead = readLines(file, list);
	cout << "linesRead executed" << '\n';
	
	cout << "Number of lines read: " << linesRead << '\n';
	
	displayLines(list);

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
	
	file.open(fileName + ".txt"); //Creates a file object linked to fileName
	
	cout << "File has been opened" << '\n';
	
	//If the file could not be properly opened, prompt the user until a valid file is chosen
	while (!file) {
		cerr << "\nFile \"" << fileName << ".txt\" does not exist or cannot be found.\n";
		cout << "\nRe-enter the auction file to be read without the extension: ";
		cin >> fileName;
		file.open(fileName + ".txt");
	}

}

int readLines(ifstream& file, LinkedList& list) {
	int numLines = 0;
	string line;
	

	cout << "Reading lines now" << '\n';

	cout << "----------------------------------------------------------------------------------------------------------\n";
	cout << "|                                    LINE                                    | READ  | ADDED | DUPLICATE |\n";
	cout << "----------------------------------------------------------------------------------------------------------\n";
	while (getline(file, line)) {
		cout << left << "| " << setw(75) << line;
		if (list.addLine(line)) {
			cout << "|   X   |   X   |           | \n";
		} else {
			cout << "|   X   |       |     X     | \n";
		}
		
		numLines++;
	}
	cout << "----------------------------------------------------------------------------------------------------------\n";
	cout << "All lines have been read" << "\n\n";
	
	return numLines;
}

void displayLines(const LinkedList& list) {
	vector<string> listVector = list.toVector();
	
	cout << "--------------------------------------LINES------------------------------------\n";
	for (int i = 0; i < list.getNumLines(); i++) {
		cout << "Line " << i + 1 << ": " << listVector[i] << '\n';
	}
	cout << "-------------------------------------------------------------------------------\n\n";

	cout << "Number of lines in vector: " << listVector.size();
	
}
