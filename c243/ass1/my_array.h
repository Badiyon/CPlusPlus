/********************************************************************
  Author:        Dana Vrajitoru, IUSB, CS
  Class:         C243, Spring 2012
  File name:     my_array.h
  Last updated:  January 21, 2013. (Scheessele)
  Last updated:  August 29, 2012.
  Description:   Definition of a class that implements a safe array.
*********************************************************************/

#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class My_array 
{
 protected:
  int size;
  int *array;

 public:
  // Constructor with given size, can be used as default constructor.
  My_array(int the_size = 0);

  // Destructor. If the array is not empty, it must be deallocated.
  ~My_array();

  // Copy constructor
  My_array(My_array &data);

  // Assignment operator
  My_array &operator=(My_array &data);

  // Deletes the array and sets the size to 0.
  void empty();

  // Resize the array.
  void resize(int the_size = 0);

  // Access an element of the array. If the index (subscript) is out
  // of the array, it prints an error message and exits the program.
  int &operator[](int index);

  // Compare the elements of one array with another to see if they are equal.
  bool operator==(My_array &data);
  
  // Compare the elements of one array with another to see if they are unequal.
  bool operator!=(My_array &data);

  // Returns the size of the array.
  int get_size();

  // Output the elements of the array.
  void output();

  // Compute the hamming distance between two arrays.
  //
  // Input: a reference to the object (array) to be compared with this one.
  // Output: the integer distance between the two arrays.
  int hamming(My_array &data);

  // Input the elements of the array.
  //
  // Input:  none.
  // Output: none.
  void input();

  // Initialize the elements of the array with random values
  // between 0 and a given maximum limit which should be a parameter.
  // Input: (maximum) limit (default = 100).
  // Input: the_size - (re-)initialize array to the_size (default = 0 means
  //               don't re-initialize).
  // Output:none.
  void randomize(int limit = 100, int the_size = 0); 

  // We define this so that we can write "cout << a;" if a is an
  // object of this class.
  friend ostream &operator<<(ostream &out, My_array &data);
  //friend istream &operator>>(istream &in, My_array &data);
};

#endif
