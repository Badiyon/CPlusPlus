//bbprobsim.cc:  Build a "probability simularto" using the bag container class (ADT). Create a bag of 100 chars holdingR = red balls and B = blue balls. 50 red in total and 50 blue in total. ask user for "number of trials" (numTrials).sample 10 balls * numTrials. sample 100 balls * numTrials. sample 1000 balls * numTrials. in a nice report, display the average percentage of red balls grabbed from the bag for each sample size//Author: Bryan Berkey
//Date: 02/05/2019
//Compiler: g++

#include <iostream>
#include <cstdlib>
#include "bag3.h"

using namespace std;
using namespace main_savitch_5;

int InsertBag(bag& balls); //insert the balls into the bag
int ProbSimBag(bag& balls); //sample and counting  

int main(){

	bag balls;

	InsertBag(balls);	
	ProbSimBag(balls);

	return 0;
}

//InsertBag: Insert data (being R for red and B for Blue) into the bag we made in the main
//Inputs: 	reference pointer to our bag: balls 
//Outputs: 	Nothing. The input is being referenced so no direct output is being made. 

int InsertBag(bag& balls){

	int x = 0; // using x to help create a for loop that will alternate between inserting R and B 

	for(int i = 0; i < 100; i++){
		if(x == 0){
			balls.insert('R');
		}
		else{
			balls.insert('B');
		}
		x = 1 - x;
	}

	return 0;

}

//ProbSimBag: calculate the probability sims of pulling 10, 100, 1000 balls from the bag and counting how many are red and then outputing the results to the screen
//Inputs: 	reference pointer to our bag: balls
//Ouptputs: 	We will not pass anything back to the main but will output results to the screen. 
int ProbSimBag(bag& balls){
	
	int totRed10Count = 0;
	int totRed100Count = 0;
	int totRed1000Count = 0;
	int numTrials = 0;

	cout << "How many trails should be done? ";
	cin >> numTrials;	

	for(int i = 0; i < numTrials; i++){
		for(int j = 0; j < 10; j++){
			if(balls.grab() == 'R'){
				totRed10Count++;
			}
		}	
	}
	
	for(int i = 0; i < numTrials; i++){
                for(int j = 0; j < 100; j++){
                        if(balls.grab() == 'R'){
                                totRed100Count++;
                        }
                }
        }
	
	for(int i = 0; i < numTrials; i++){
                for(int j = 0; j < 1000; j++){
                        if(balls.grab() == 'R'){
                                totRed1000Count++;
                        }
                }
        }	
	
	cout << "Average of red balls grabbed in 10 grabs in " << numTrials << " trails is " << totRed10Count/numTrials << endl;
	cout << "Average of red balls grabbed in 100 grabs in " << numTrials << " trails is " << totRed100Count/numTrials << endl;
	cout << "Average of red balls grabbed in 1000 grabs in " << numTrials << " trails is " << totRed1000Count/numTrials << endl;

	return 0;

}
