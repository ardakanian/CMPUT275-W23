/*
	A cpp file that defines the main function and includes some header files.

	Course: CMPUT 275
	Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>
#include "second.h"
#include "third.h"

using namespace std;

// function prototype
// compiler processes the .cpp file from top to bottom
int square(int);


// function header
int main() {
	int a = 2;
	// insertion operator can combine multiple statements
	cout << a << " " << square(a) << endl;
	cout << implement_budget_cut(60000, 1500);
	cout << endl;

	// cout << sizeof(short) << endl;
	cout << compare(2, 5) << endl;
	return 0;
}

// function header
int square(int a) {
	return a*a;
}
