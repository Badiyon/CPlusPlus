/*Bryan Berkey
 * 11/13/2018
 * C201 Fall Semester 
 * Dr. Wolfer
 * Hw4: Define a class called Pizza that has member variables to track the type of pizza (either deep dish, hand tossed, or pan) along with the size (either small, medium, or large) and the number of pepperoni or cheese toppings. You can use constants to represent the type and size. Include mutator and accessor functions for your class. Create a void function, outputDescription( ) , that outputs a textual description of the pizza object. Also include a function, computePrice( ) , that computes the cost of the pizza and returns it as a double according to the following rules:
 *
 * Small pizza = $10 + $2 per topping
 *
 * Medium pizza = $14 + $2 per topping
 *
 * Large pizza = $17 + $2 per topping
 *
 * Write a suitable test program that creates and outputs a description and price of various pizza objects.
 *
 * */

#include <iostream>
using namespace std;

	const int DEEPDISH = 1; // Constants used to set the variables for size and types
	const int HANDTOSSED = 2;
	const int PAN = 3;
	const int SMALL = 1;
	const int MEDIUM = 2;
	const int LARGE = 3;

class Pizza{

	public:
	Pizza();
	void setType(int t); //to set the type
	void setSize(int s); //to set the size
	void setCheese(int c); //to set the amount of cheese
	void setPep(int p); //to set the amount of pepperoni

	void outputDescription(); //to output the description
        double computerPrice(); //to get the final price 

	private:
	int type; //type of pizza that gets set in the class
	int size; //size of pizza that gets set in the class
	int cheese; //amount of cheese that gets set in the class
	int pep; //amount of pepperoni that gets set in the class

};

	Pizza::Pizza(){
		type = DEEPDISH;
		size = SMALL;
		cheese = 0;
		pep = 0;
	} //set the variables to basic pre sets

int main(){

	char tType, tSize, tCheese, tPep;
	int Type, Size, Cheese, Pep;

	cout << "What size pizza? (S/M/L): " << endl;
	cin >> tSize;
	cin.clear(); //get the user input for size of the pizza

	cout << "What Type of pizza? (DeepDish/HandTossed/Pan): " << endl;
	cin >> tType;
	cin.clear(); //get the user input for the type of pizza
	
	switch(tType){
	
	case 'D': case 'd':
		Type = DEEPDISH;
		break;
	case 'H': case 'h':
		Type = HANDTOSSED;
		break;
	case 'P': case 'p':
		Type = PAN;
		break;
	} //set the type to the corresponding integer set in the global 

	switch(tSize){

        case 'S': case 's':
                Size = SMALL;
                break;
        case 'M': case 'm':
                Size = MEDIUM;
                break;
        case 'L': case 'l':
                Size = LARGE;
                break;
        } // set the size to the corresponding integer set in the global

	Pizza MyPizza; //create a new class called MyPizza
	MyPizza.setSize(Size); //set the size in the class 
	MyPizza.setType(Type); //set the type in the class

	cout << "Cheese? (Y/N): " << endl;
	cin >> tCheese;
	cin.clear(); //get the user input for amount of cheese
	
	if(tCheese == 'Y' || tCheese == 'y'){
		cout << "How many serving toppings of cheese? " << endl;
		cin >> Cheese;
		cin.clear();
	} //set the amount of cheese in the main

	cout << "Pepperoni? (Y/N) " << endl;
	cin >> tPep;
	cin.clear(); //get the user input for amount of pepperoni
	
	if(tPep == 'Y' || tPep == 'y'){
		cout << "How many serving toppings of Pepperoni? " << endl;
		cin >> Pep;
		cin.clear();
	} //set the amount of pepperoni in the main

	MyPizza.setCheese(Cheese); //set the amount of cheese in the class
	MyPizza.setPep(Pep); //set the amount of pepperoni in the class

	cout << "You ordered: ";	

	MyPizza.outputDescription(); //output the description of the pizza from what the user provided us

	cout << endl;

	cout << "Price = $" << MyPizza.computerPrice() << endl; // output the price using what the user has provided

	return 0;
}


void Pizza::setType(int t){
	type = t;	
} //set the type of pizza in the class
void Pizza::setSize(int s){
	size = s;
} //set the size of pizza in the class
void Pizza::setCheese(int c){
	cheese = c;
} //set the amount of cheese in the class
void Pizza::setPep(int p){
	pep = p;
} //set the amount of pepperoni in the class

void Pizza::outputDescription(){
	switch(size){
	
	case SMALL:
		cout << "Small ";
		break;
	case MEDIUM:
		cout << "Medium ";
		break;
	case LARGE:
		cout << "Large ";
		break;
	} //print to the screen the size from the variable size in the class
	switch(type){
	
	case DEEPDISH:
		cout << "Deepdish ";
		break;
	case HANDTOSSED:
		cout << "HandTossed ";
		break;
	case PAN:
		cout << "Pan ";
		break;
	} //print to the screen the type from the variable type in the class
	cout << "pizza ";
	cout << "Cheese (" << cheese << ") ";
	cout << "Pep (" << pep << ") ";	
}

double Pizza::computerPrice(){
	double Price = 0;
	double Toppings = 0;

	switch(type){

	case SMALL:
		Price = Price + 10;
		break;
	case MEDIUM:
		Price = Price + 12;
		break;
	case LARGE:
		Price = Price + 14;
		break;
	}

	Toppings = cheese + pep; //the amount of toppings will be the amount of cheese and pepperoni
	Price = Price + (Toppings * 2); //price will be the price of the size of the pizza found earlier plus the amount of toppings multiplied by 2 since its 2 dollars for each topping
	
	return Price;
}

/*Output:
 * What size pizza? (S/M/L):
 * M
 * What Type of pizza? (DeepDish/HandTossed/Pan):
 * P
 * Cheese? (Y/N):
 * Y
 * How many serving toppings of cheese?
 * 2
 * Pepperoni? (Y/N)
 * N
 * You ordered: Medium Pan pizza Cheese (2) Pep (0)
 * Price = $18
 */
