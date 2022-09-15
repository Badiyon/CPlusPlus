#include <iostream>
#include "node2.h"
#include "stack2.h"
using namespace std;
using namespace main_savitch_7B;

int main()
{
  stack<char> word;

  word.push('o');
  word.push('w');
  word.push('l');
  cout << endl << word.top();
  word.pop();
  cout << endl << word.top();
  word.pop();
  cout << endl << word.top();
  word.pop();
  cout << endl;

  return 0;
}
