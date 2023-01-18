/*
	The const keyword can be used at declaration time
	It means different things depending on the context
	
	Course: CMPUT 275
	Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>

using namespace std;

int main() {
	// const variable
	const int total = -100;
	// total += 10;				// compile error

	int steps = 10, distance = 250;

	// pointer to const variable/object (for read-only access)
	const int * i_ptr = &steps;
	// i_ptr += 1;				// compile error
	steps++;
	i_ptr = &distance;

	// const pointer
	int * const i_ptr2 = &steps;
	// i_ptr2 = &distance;		// compile error
	*i_ptr2 += 1;

	// const pointer to const
	const int * const i_ptr3 = &steps;
	// i_ptr3 = &distance;		// compile error
	// *i_ptr3 = 100;			// compile error

	// reference variable (aliasing)
	int diamond = 10;
	int &diamond_ref = diamond;
	cout << diamond_ref << " " << diamond << endl;
	diamond_ref = 20;			// references are dereferenced automatically
	cout << diamond_ref << " " << diamond << endl;
	cout << &diamond_ref << " " << &diamond << endl;
		
	return 0;
}