/*
  A simple template example.

  Try compiling to an executable and then running

  nm a.out (or whatever you called the executable)

  to see that code for three versions of the getMax function was generated
  by the compiler.

  Course: CMPUT 275
  Zac Friggstad, 2021
*/

#include <iostream>

using namespace std;

template <typename T>
T getMax(T arg1, T arg2) {
  if (arg1 < arg2) return arg2;
  else return arg1;
}

int main() {
  cout << getMax(10, 20) << endl;
  cout << getMax('x', 'y') << endl;
  cout << getMax(3LL, 4LL) << endl;
  cout << getMax(50, 60) << endl;

  return 0;
}
