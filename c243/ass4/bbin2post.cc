// bbin2post.cc: convert infix expression to postfix expression
// Author: Bryan Berkey
// Date: 02/25/2019
// Compiler: g++

#include <iostream>
#include <fstream>
#include <string>
#include "node2.h"
#include "stack2.h"
using namespace std;
using namespace main_savitch_7B;

int main()
{

  stack<char> Character;
  string line;

  ifstream myfile("infix.dat");

  if (myfile.is_open()) {
	
	while ( getline(myfile,line)) {   //keep getting each line of the function until we reach the end of the file. 
		
		for (int i = 0; line[i]; i++) {   //read through the line until we reach the end of the line. 
			
			if (line[i] == '(') {  
				Character.push(line[i]);
			} 
			else if ( (line[i] >= '0' && line[i] <= '9') || (line[i] >= 'A' && line[i] <= 'Z') ) { 
				//check if the character is between 0 and 9 or A and Z
				cout << line[i];
			}
			else if (line[i] >= '*' && line [i] <= '/') { 
				Character.push(line[i]);
			}
			else{	
				if (Character.top() < '*' || Character.top() > '/') { 
					cout << " To few operations";
					break;
				}
				else {
					cout << Character.top();
					Character.pop();
				}
				if (Character.top() != '(') {
					cout << " Unequal Paranthesis ";
					break;
				}	
				else {
					Character.pop();
				}
			}
		}
	if ( !(Character.empty()) ) { 
		cout << " The stack is not empty ";
	  }
	while ( !(Character.empty()) ) {
		Character.pop();
	  }
	cout << endl;
	} 
	myfile.close();
  }  
}



