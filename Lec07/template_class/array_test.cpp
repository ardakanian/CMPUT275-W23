#include <iostream>
#include "array.h"

using namespace std;

int main() {
  unsigned int len;
  cout << "Number of entries: ";
  cin >> len;

  Array<int> myArray(len);
  for (int i = 0; i < myArray.size(); i++) {
    myArray[i] = 2*i+1;
  }

  cout << "myArray contents:";
  for (int i = 0; i < myArray.size(); i++) {
    cout << ' ' << myArray[i];
  }
  cout << endl;

  Array<char> charArray(3);
  charArray[0] = 'c';
  charArray[1] = 'a';
  charArray[2] = 't';

  cout << "charArray contents: ";
  for (int i = 0; i < charArray.size(); i++) {
    cout << charArray[i];
  }
  cout << endl;

  return 0;
}
