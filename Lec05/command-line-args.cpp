/*
	A program that takes one or multiple 
	command line arguments
	
	Course: CMPUT 275
	Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
// argv: an array of pointer to char
// alternative form: int main(int argc, char **argv)

	// the program name is always the first argument
	cout << "number of command-line arguments: " << argc << endl;
	for (int i=0; i<argc; i++)
		cout << argv[i] << endl;

	return 0;
}