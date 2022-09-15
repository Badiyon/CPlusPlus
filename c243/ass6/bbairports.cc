//bbairports.cc: to store airport records into a hash table. 
//Author: Bryan Berkey
//Date: 03/20/2019
//Compiler: g++
//Problems: unable to keep the strings passed to the hash table intack
//everytimg i insert new data it overwrites the data already in the table. 
//Was unable to find what causes this and couldn't find a work around. 

#include <iostream>
#include <fstream>
#include <string>
#include "table1.h"
using namespace std;
using namespace main_savitch_12A;

struct airports {
	int key;
	string code;
	string location;
};

void printmenu();
char getinput();
int getkey(string letters, const int M);
int getcode(const int M);
airports getinfo(string line, const int M);

int main( ) {

	table<airports> airport;
	airports AP;
	string line;
	ifstream myfile("airports.dat");
	int keycode = 0;
	bool found;
	char choice;
	
	if (myfile.is_open()) { 
		
		while (getline(myfile, line)) {
			
			for (int i = 0; i < 3; i++)
               			AP.code[i] = line[i];
		// to help test that its being read from the file correctly	
		//	for (int i = 0; i < 3; i++)
		//		cout << AP.code[i];
        		
			for (int i = 3; line[i]; i++)
                		AP.location[i] = line[i];

        		AP.key = ( getkey(AP.code, airport.CAPACITY ) );
	 	
			airport.insert( AP );
		}	
			
	}
	
	myfile.close();
	
	do {
		printmenu();

		choice = toupper(getinput());

		switch(choice) {
			case 'R': airport.remove(getcode(airport.CAPACITY));
				  break; 
			case 'F': airport.find(getcode(airport.CAPACITY), found, AP); 
				  if (found) {
					cout << "Key was found. Code = ";
					for (int i = 0; i < 3; i++) {
						cout << AP.code[i];
					} 
					cout << endl << " Location = ";
					for (int i = 0; AP.location[i]; i++) {
						cout << AP.location[i];
					} 
				  }
				  else {
					cout << "Key was not found. " << endl;
				  }
				  break;
			case 'Q': cout << "Quitting now. " << endl;
				  break;
		}
	}while(choice != 'Q');	
	
}

//printmenu: prints the menu for the user to choose from. 
//inputs: no inputs
//outputs: no direct outputs except for outputting to the screen for the user to read from. 
void printmenu() {
	cout << "R = Remove" << endl;
	cout << "F = Find" << endl;
	cout << "Q = Quit" << endl;
}

//getinput: used to get the input on what they want to do 
//inputs: no inputs
//outputs: returns the character choice the user inputted. 
char getinput() {
	char choice;
	cout << "Input your choice now. ";
	cin >> choice;
	return choice;
}

//getkey: used to get the key that we will use to hash to the table with
//inputs: the 3 letter airport code and the table capacity
//outputs; the key to hash to 
int getkey(string letters, const int M) {

	int keycode = 0;
		
	for(int i = 0; i < 3; i++) {
		keycode += (5 * i + 3) * int(letters[i]); 
	}

	return keycode % M;
}

//getcode: used to get the airport code given by the user
//inputs; bring in the tables capacity to help pass to getkey
//output: the airport keycode to help look throught table for the airport
int getcode(const int M) {
	string lettercode;
	int keycode = 0;
	
	cout << "Input three letter code ";
	cin >> lettercode;

	keycode = getkey(lettercode, M);
//	cout << keycode;
	return keycode;	
}


