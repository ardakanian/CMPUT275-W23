#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "How big should the array be?" << endl;
  cin >> n;

  int *array = new int[n];

  cout << "We got it!" << endl;

  // the location of the pointer variable itself (should be the stack)
  cout << (&array) << endl;

  // the location of the dynamically-allocated memory (should be the heap)
  cout << (array) << endl;

  for (int i = 0; i < n; ++i) {
    array[i] = i;
    // same as *(array+i) = i
  }

  for (int i = 0; i < n; ++i) {
    cout << array[i] << endl;
  }

  // uncomment to get an error, you cannot delete partway through an array
  // delete[] (array+5);

  cout << "First delete" << endl;
  delete[] array;

  cout << "Second delete" << endl;
  // we already deleted it, so trying to delete it again
  // will crash the program
  delete[] array;

  cout << "Test" << endl;

  return 0;
}
