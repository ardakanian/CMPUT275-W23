/*
	A C++ program that has a bug...

	Course: CMPUT 275
	Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>
using namespace std;

int main() {
	// uninitialized pointers are dangerous
	// try dereferencing this pointer and 
	// see what happens (use gdb)
	int *ptr;

	// int a[2] = {11, 12};
	// ptr = a;

	// dereferencing a null pointer will result
	// in a segmentation fault (good practice)
	// ptr = nullptr;	// since C++11

	// did we initialize this pointer 
	// or assign a value to it earlier?
	*ptr = 100;

	// print address and value
	cout << hex << ptr << dec << " " << *ptr << endl;

	return 0;
}
