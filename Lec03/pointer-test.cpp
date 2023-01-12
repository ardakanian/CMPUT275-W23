/*
	A simple demonstration of pointer arithmetic
	Notice similarities between arrays and pointers

	Course: CMPUT 275
	Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>
using namespace std;

int main()
{
	int coins[8] = {1, 5, 10, 25, 50, 100, 200};
	cout << *(coins + 6) << " " << coins[6] << endl;

	// array name is address of the 1st element
	int *i_ptr = coins;
	i_ptr = &coins[0];	// same thing
	
	// increases the ptr value by sizeof(int)
	i_ptr++;	// i_ptr += 1

	cout << *i_ptr + 1 << endl;		// prints 6
	cout << i_ptr[2] << endl;		// prints 25
	cout << *(i_ptr + 1) << endl;	// prints 10

	return 0;
}