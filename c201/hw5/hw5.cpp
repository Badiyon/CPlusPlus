/*
 * Bryan Berkey
 * C201 FALL 
 * Dr. Wolfer
 * Putty into the IUSB linux machines and using g++ compilers
 * Hw5:
 * Define a class called Month that is an abstract data type for a month. Your class will have one member variable of type int to represent a month (1 for January, 2 for February, and so forth). Include all the following member functions: a constructor to set the month using the first three letters in the name of the month as three arguments, a constructor to set the month using an integer as an argument (1 for January, 2 for February, and so forth), a default constructor, an input function that reads the month as an integer, an input function that reads the month as the first three letters in the name of the month, an output function that outputs the month as an integer, an output function that outputs the month as the first three letters in the name of the month, and a member function that returns the next month as a value of type Month . Embed your class definition in a test program. 
 * */

#include <iostream>
using namespace std;

class Month {
public:
	Month(); //basic constructor
	Month(int Month); //constructor
	Month(char firstletter, char secondletter, char thirdletter); //constructor
	void InputInteger(int IntMonth); //read month as integer
	void InputLetters(); //read month as the first three characters
	void OutputInteger(); //output the month as an integer
	void OutputLetters(); //output the month as the first three characters
private:
	int Imonth;
};

Month::Month(){

}

int main() {
	Month Integer, Letters; // two testing classes of Month. Integer for inputing the month number. Letters for inputing the first 3 letters of the month

	int IntMonth; //integer variable for the month number
	
	cout << "Enter the number of the month ";
	cin >> IntMonth; // setting the month number
        Integer.InputInteger(IntMonth); // inputting the month number into the class
	cout << "\nThe number of the month is ";
	Integer.OutputInteger(); // outputing the month number
	cout << "\nThe first 3 letters of the month is ";
	Integer.OutputLetters(); // outputing the first 3 letters of the month

	cout << "\nTesting three letters "; // just to let me know its moving on to the next test
	Letters.InputLetters(); // inputing to first 3 letters of the month
	cout << "\nThe 3 letters of the month is ";
	Letters.OutputLetters(); // output the month number
	cout << "\nThe integer of the month is ";
	Letters.OutputInteger(); // output the first 3 letters of the month
	cout << endl;
}

void Month::InputInteger(int IntMonth){
	Imonth = IntMonth; // setting the private variable for the output members
}
void Month::InputLetters(){
	char L1, L2, L3;
	cout << "\nEnter first three letters of the month ";
	cin >> L1 >> L2 >> L3;
	if ((L1 == 'J')&&(L2 == 'a')&&(L3 == 'n'))
                Imonth = 1;
        else if ((L1 == 'F')&&(L2 == 'e')&&(L3 == 'b'))
                Imonth = 2;
        else if ((L1 == 'M')&&(L2 == 'a')&&(L3 == 'r'))
                Imonth = 3;
	else if ((L1 == 'A')&&(L2 == 'p')&&(L3 == 'r'))
		Imonth = 4;
        else if ((L1 == 'M')&&(L2 == 'a')&&(L3 == 'y'))
                Imonth = 5;
        else if ((L1 == 'J')&&(L2 == 'u')&&(L3 == 'n'))
                Imonth = 6;
        else if ((L1 == 'J')&&(L2 == 'u')&&(L3 == 'l'))
                Imonth = 7;
        else if ((L1 == 'A')&&(L2 == 'u')&&(L3 == 'g'))
                Imonth = 8;
        else if ((L1 == 'S')&&(L2 == 'e')&&(L3 == 'p'))
                Imonth = 9;
        else if ((L1 == 'O')&&(L2 == 'c')&&(L3 == 't'))
                Imonth = 10;
        else if ((L1 == 'N')&&(L2 == 'o')&&(L3 == 'v'))
                Imonth = 11;
        else if ((L1 == 'D')&&(L2 == 'e')&&(L3 == 'c'))
                Imonth = 12;
	//helping get and set the Imonth variable for the output members
}
void Month::OutputLetters(){
	if(Imonth == 1)
		cout << "Jan";
	
	else if(Imonth == 2)
		cout << "Feb";
	
	else if(Imonth == 3)
		cout << "Mar";
		
	else if(Imonth == 4)
		cout << "Apr";
		
	else if(Imonth == 5)
		cout << "May";
		
	else if(Imonth == 6)
		cout << "Jun";
		
	else if(Imonth == 7)
		cout << "Jul";
		
	else if(Imonth == 8)
		cout << "Aug";
		
	else if(Imonth == 9)
		cout << "Sep";
		
	else if(Imonth == 10)
		cout << "Oct";
		
	else if(Imonth == 11)
		cout << "Nov";
		
	else if(Imonth == 12)
		cout << "Dec";		
	// using the private variable output the the 
}

void Month::OutputInteger(){
	cout << Imonth;
} // output the month number that gets set earlier

/*Output results
 * Enter the number of the month 5
 *
 * The number of the month is 5
 * The first 3 letters of the month is May
 * Testing three letters
 * Enter first three letters of the month Mar
 *
 * The 3 letters of the month is Mar
 * The integer of the month is 3
 * [beberkey@cs03 hw5]$ ./a.out
 * Enter the number of the month 8
 *
 * The number of the month is 8
 * The first 3 letters of the month is Aug
 * Testing three letters
 * Enter first three letters of the month Dec
 *
 * The 3 letters of the month is Dec
 * The integer of the month is 12
 * [beberkey@cs03 hw5]$
 **/


