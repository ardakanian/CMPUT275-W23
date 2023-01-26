/*
  Header file for an array class that can hold an array of any type
  (all entries must be of the same type, but we can choose the type
  via the template parameter). It also does bounds checking when you
  access an element.

  We *have* to implement the class methods in this file because it
  has a template parameter.

  That is, we cannot compile it in a separate .cpp file because the compiler
  would not know which types to compile the code for.
*/

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cassert>

template <typename T>
class Array {
public:
  Array(unsigned int a_len);
  T& operator[](unsigned int index);
  unsigned int size() const;

private:
  T* array;
  unsigned int array_len;
};

template <typename T>
Array<T>::Array(unsigned int a_len) {
  this->array_len = a_len;
  this->array = new T[this->array_len];
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
  assert(index < this->array_len);
  return this->array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
  return this->array_len;
}


#endif
