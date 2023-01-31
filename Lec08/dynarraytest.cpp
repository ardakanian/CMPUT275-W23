#include <iostream>
#include "dynarray.h"

using namespace std;

void dumpArray(DynamicArray<int> &a) {
  cout << "Size is: " << a.size() << endl;
  cout << "Items:";
  for (unsigned int i = 0; i < a.size(); i++) {
    cout << ' ' << a[i];
  }
  cout << endl << endl;
}

int main() {
  DynamicArray<int> a(10);

  cout << "Might be nonsense since entries are not initialized yet" << endl;
  dumpArray(a);

  for (unsigned int i = 0; i < a.size(); i++) {
    a[i] = 2*i;
  }

  cout << "Should be even numbers" << endl;
  dumpArray(a);

  a.resize(7);

  for (int i = 0; i < 10; i++) {
    a.pushBack(101+i);
  }

  cout << "After resizing to 7 and then pushing 101, 102, ..., 110 to the back" << endl;
  dumpArray(a);

  // testing copy constructor
  DynamicArray<int> b(a);

  a[0] = -4;
  cout << "Printing the original array again, but with a[0] = -4" << endl;
  dumpArray(a);
  cout << "Printing the copy of a[] that was made before a[0] was set to -4" << endl;
  dumpArray(b);

  // testing assignment operator
  b = a;
  a.resize(3);

  cout << "Printing the new 'a', which was resized to 3" << endl;
  dumpArray(a);
  cout << "Now printing b, which was assigned to be a copy of the old 'a'" << endl;
  dumpArray(b);

  return 0;
}
