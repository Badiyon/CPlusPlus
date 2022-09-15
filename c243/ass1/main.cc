/********************************************************************
  Author:        Dana Vrajitoru, IUSB, CS
  Modified by:   Bryan Berkey 
  Class:         C243, Spring 2012
  File name:     main.cc
  Last updated:  Januray 22, 2019.
  Description:   Testing the class My_array.
*********************************************************************/

#include "my_array.h"
#include <iostream>
using namespace std;

int main()
{
  srand((unsigned) time(NULL));  

  My_array a, b, c, d;

  cout << endl;

  a.input();
  d.input();
  
  if (a == d)
	cout << "a and d are equal\n";
  
  b.randomize(10, a.get_size());
  c.randomize(10, a.get_size());
	
  cout << "\nArray: a" << endl;
  a.output();
  cout << "\nArray: b" << endl;
  b.output();
  cout << "\nArray: c" << endl;
  c.output();

  if (a == b)
    cout << "a and b are equal!\n\n";
  else
    cout << "a and b are not equal!\n\n";

  cout << "The Hamming distance between b and c is: "
       << b.hamming(c) << endl << endl;
 
  return 0;
}
