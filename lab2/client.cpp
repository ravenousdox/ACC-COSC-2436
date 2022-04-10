/** @file client.cpp */

/******************************************************************************/
/* Program Description: Opens a file containing bids, finds the largest one,
/* and outputs it to the user.
/******************************************************************************/

#include <iostream>
#include <fstream>
#include "LinkedStack.h"
using namespace std;

void grabFile(string&, ifstream&);
void findMaxBid(string, ifstream&, LinkedStack<string>&);

int main() {
	LinkedStack<string> bag;
	string fileName = "";
	ifstream auctionFile;
	
	grabFile(fileName, auctionFile);
	findMaxBid(fileName, auctionFile, bag);
	auctionFile.close();
	
	return 0;
}

/******************************************************************************/
/* Function: grabFile    												      */
/* Inputs: A reference to the string fileName and a reference to the ifstream */
/*		   object auctionFile                                                 */
/* Outputs: None							                                  */
/* Purpose: To grab the name of the file from the user, validate the file     */
/*          exists and can be read, and link the file to the file object      */
/******************************************************************************/
void grabFile(string& fileName, ifstream& auctionFile) {
	cout << "Input the auction file to be read without the extension: ";
	cin >> fileName;
	
	auctionFile.open(fileName + ".txt");			//Creates a file object linked to fileName
	
	//If the file could not be properly opened, prompt the user until a valid file is chosen
	while (!auctionFile) {
		cerr << "\nFile \"" << fileName << ".txt\" does not exist or cannot be found.\n";
		cout << "\nRe-enter the auction file to be read without the extension: ";
		cin >> fileName;
		auctionFile.open(fileName + ".txt");
	}
	
}

/******************************************************************************/
/* Function: findMaxBid    												      */
/* Inputs: The string fileName, a reference to the ifstream object            */
/*		   auctionFilem, and a reference to a LinkedStack<string> object      */
/* Outputs: None							                                  */
/* Purpose: To read the bids in the auction file and output the greatest bid  */
/******************************************************************************/
void findMaxBid(string fileName, ifstream& auctionFile, LinkedStack<string>& bag) {
	string value;
	string name;
	getline(auctionFile, name);
	
	cout << "\nItem for auction: " << name;
	
	while (auctionFile >> value) {					//Read in a line from the file into value while you have not reached EOF		
		if (!value.find_first_of("1234567890")) {	//If the occurrence of a digit is found within the line
			if (bag.isEmpty()) {					//If the bag is empty
				bag.push(value);					//Push the first value
			} else if (value > bag.peek()) {		//Else compare the top of the stack with the value being read
				bag.push(value);					//If the read value is larger, push the value onto the stack
			}
		}
	}
	
	//If the stack had values pushed onto it...
	if (!bag.isEmpty()) {
		cout << "\nThe winning bid is " << bag.peek() << "!";
	} else {
		cerr << "\nNo bids found in file: " << fileName << ".txt";
	}
		
}
