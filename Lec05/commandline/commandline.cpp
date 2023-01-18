/*
	A simple demonstration of how to use command-line arguments.

	The second half of the program assumes the parameters are "A <num1> <num2>"
	and it will print the sum of the two numbers.

	Course: CMPUT 275
	Zac Friggstad, 2021
*/

#include <iostream>
#include <cstdlib> // convert character arrays representing integers to actual integers
#include <string>

using namespace std;

int main(int argc, char** argv) {
	// first just print out the parameters

	cout << "Number of parameters: " << argc << endl;

	// now print out each parameter
	cout << "Parameters:" << endl;
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << endl; // argv[i] is a pointer to the start of a null-terminated string
	}
	cout << endl;


	// now check that there were three and the first one was A
	if (argc != 4 || string(argv[1]) != "A") {
		cerr << "Usage: commandline A <num1> <num2>" << endl;
		return 1; // abnormal termination, we won't actually use this in the course
	}

	// atoi will convert a string (represented as a character array) to an integer
	int num1 = atoi(argv[2]);
	int num2 = atoi(argv[3]);

	cout << num1 << " + " << num2 << " = " << (num1+num2) << endl;

	return 0;
}