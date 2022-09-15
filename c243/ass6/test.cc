#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct airports{
	int key;
	string code;
	string location;
};

int main() {
	airports ap;
	airports ap1;
	ap.code = "hello";
	ap1.code = ap.code;
	for(int i = 0; ap1.code[i]; i++)
		cout << ap1.code[i];
	ap.code = "goodbye";
	for(int i = 0; ap1.code[i]; i++)
		cout << ap1.code[i];	
}
