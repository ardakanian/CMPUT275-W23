/*
  Operator overloading, example #1

  Course: CMPUT 275
  Zac Friggstad, 2021
*/

#include <iostream>
#include <cassert>

using namespace std;

class IntArray {
public:
  // constructor, one must specify a size
  // (which is why there is no default value)
  IntArray(unsigned int arrayLength);
  ~IntArray();

  // can index the class using []
  // will return a reference (i.e. lvalue) to that item
  int& operator[](unsigned int index);

  unsigned int size() const;

private:
  unsigned int arrayLen;
  int* array;
};

IntArray::IntArray(unsigned int arrayLength) {
  assert(arrayLength > 0);

  arrayLen = arrayLength;
  array = new int[arrayLen];
}

IntArray::~IntArray() {
  delete[] array;
}

int& IntArray::operator[](unsigned int index) {
  assert(index < arrayLen);
  return array[index];
}

unsigned int IntArray::size() const {
  return arrayLen;
}

int main() {
  IntArray myArray(10);

  for (int i = 0; i < myArray.size(); i++) {
    myArray[i] = i+1;
  }

  for (int i = 0; i < myArray.size(); i++) {
    cout << myArray[i] << endl;
  }

  IntArray second(2);

  /*
    Challenge:

    Consider this line
    IntArray arrayCopy = myArray;


    Uh-Oh!

    This assignment copied the private pointer "array", now both arrayCopy
    and myArray point to the same location in the heap. Further, if one
    of them goes out of scope before the other (eg. one is declared
    in a nested if statement) then it will delete this memory but the other
    refers to it!

    Do some research on the copy constructor and overloading the assignment
    operator to see how to do this safely
    (tip, it involves having arrayCopy allocate its own memory and then
     copying the contents of myArray over to this new memory)
  */


  return 0;
}
