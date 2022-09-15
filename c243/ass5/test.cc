#include <iostream>
#include "queue4.h"
using namespace std;
using namespace main_savitch_8C;

int main()
{
  queue<int> myTestQ;
  queue<int>::iterator position;

  // Add prime #s to myTestQ.
  myTestQ.enqueue(2);
  myTestQ.enqueue(3);
  myTestQ.enqueue(5);
  myTestQ.enqueue(7);

  // Print contents of myTestQ using a forward iterator.
  for (position = myTestQ.begin(); position != myTestQ.end(); ++position)
      cout << endl << *position;
  cout << endl;

  myTestQ.dequeue( );
  myTestQ.dequeue( );

  for (position = myTestQ.begin(); position != myTestQ.end(); ++position)
      cout << endl << *position;
  cout << endl;
  
  if(myTestQ.isInQ(5))
	{ cout << " 5 is in the queue "; }
  else 
	{ cout << " not in queue "; } 
 
  return 0;
} 
