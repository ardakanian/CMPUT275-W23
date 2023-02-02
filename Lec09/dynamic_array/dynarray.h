/*
  Implementation of an array that can be resized during run time.

  Version 2: Includes both const and non-const operator[] overloads.

  We didn't separate the declaration from the implementation in
  .h and .cpp files because this is template code. Unfortunately,
  code that uses template parameters cannot be put in a standalone
  .cpp file.
*/

#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_

#include <cassert>
#include <cstdlib>

using namespace std;

// A dynamic array that can be resized when desired.
template <typename T>
class DynamicArray {
public:
  // create a new array with the given size
  DynamicArray(unsigned int size = 0);
  ~DynamicArray();

  // copy constructor
  DynamicArray(const DynamicArray& copy);

  // assignment operator overload
  DynamicArray& operator=(const DynamicArray& rhs);

  // add a new entry to the end of the array
  void pushBack(const T& item);

  // resize the array, keeping the items in the current array
  // except for ones that are indexed >= size (if any)
  void resize(unsigned int newSize);

  // these behave the same, but we need both versions
  // the compiler will call the appropriate one (depending on whether
  // the instance is a const instance or not)
  T& operator[](unsigned int index);
  const T& operator[](unsigned int index) const;

  // just return the # of slots allocated to the array
  unsigned int size() const;

private:
  T *array; // the actual array allocated in the heap
  unsigned int numItems;  // number of items in the array, for the user
  unsigned int arraySize; // size of the underlying array in the heap
};

template <typename T>
DynamicArray<T>::DynamicArray(unsigned int size) {
  // just point array to NULL and let resize do the work
  array = NULL;
  resize(size);
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
  delete[] array;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& copy) {
  // first get an array of the appropriate size,
  // since this is a constructor, we treat it as if the array pointer
  // was not initialized at all
  // FURTHER STUDY FOR THE CURIOUS: constructor delegation
  array = NULL;
  resize(copy.numItems);

  // now the array has the proper size, so just copy the contents of the other
  // array into this array
  for (unsigned int i = 0; i < numItems; i++) {
    array[i] = copy.array[i];
  }
}

// different than the copy constructor, see the lecture slides for a discussion
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& rhs) {
  resize(rhs.numItems);

  for (unsigned int i = 0; i < numItems; i++) {
    array[i] = rhs.array[i];
  }

  return *this;
}

template <typename T>
void DynamicArray<T>::resize(unsigned int newSize) {
  // get an array from the heap with twice the new user array size
  // (or 10, if the new size is really small)
  unsigned int newArraySize = max(newSize*2, 10u);

  // get the new array
  T *newArray = new T[newArraySize];

  // if we had an old array (i.e. this was not called from the constructor),
  // copy the contents over to the new array and then delete this array
  if (array != NULL) {
    // copy the old array over until we fill the new array (according to user size)
    // or we copied all contents from the old array
    for (unsigned int i = 0; i < min(numItems, newSize); i++) {
      newArray[i] = array[i];
    }
    delete[] array;
  }

  // update the class members for this new array and point to it now
  numItems = newSize;
  arraySize = newArraySize;
  array = newArray;
}

template <typename T>
unsigned int DynamicArray<T>::size() const {
  return numItems;
}

template <typename T>
void DynamicArray<T>::pushBack(const T& item) {
  // if the dynamic array is already full, resize it
  if (numItems == arraySize) {
    // resize to get enough space for more items
    resize(numItems+1);
    // but we haven't actually put the new item in yet
    numItems--;
  }

  // either way, we now have space to add the item
  // to the end of the user's array
  array[numItems] = item;
  numItems++;
}

template <typename T>
T& DynamicArray<T>::operator[](unsigned int index) {
  assert(index < numItems);
  return array[index];
}


template <typename T>
const T& DynamicArray<T>::operator[](unsigned int index) const {
  assert(index < numItems);
  return array[index];
}

#endif
