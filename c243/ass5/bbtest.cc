//bbtest.cc: get practice modifying and existing queue adt built on  
//top of a linked list ADT. also get practice using a forward iterator
//Author: Bryan Berkey
//Date:03/06/2019
//Compiler: g++

#include <iostream>
#include "queue4.h"
using namespace std;
using namespace main_savitch_8C;

int main( )
{
  queue<int> myTestQ;
  queue<int>::iterator position;

   myTestQ.enqueue(52);
   myTestQ.enqueue(63);
   myTestQ.enqueue(85);
   myTestQ.enqueue(37);
   myTestQ.enqueue(9);
   myTestQ.enqueue(5);

  
   cout << " Here is what is in the queue currently " << endl;

   for (position = myTestQ.begin(); position != myTestQ.end(); ++position)
  	 cout << endl << *position;
   cout << endl;
   
   myTestQ.dequeue( );
   myTestQ.dequeue( );

   myTestQ.isInQ(5);
   myTestQ.isInQ(4);
   
   cout << " Here is what is in the queue currently " << endl;

   for (position = myTestQ.begin(); position != myTestQ.end(); ++position)
         cout << endl << *position;
   cout << endl;


   return 0;
  
} 
