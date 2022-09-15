//testing file for input
//Bryan Berkey
//02/20/2019

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
string line;

ifstream myfile ("infix.dat");
if (myfile.is_open()){
	while( getline (myfile,line)){
		for(int i=0;line[i];i++)
			cout << line[i];	
		cout << endl;	
	}
	myfile.close();
	} 
else { cout << "error";}

}
