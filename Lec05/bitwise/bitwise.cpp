/*
	A simple demonstration of bitwise operations.

	Course: CMPUT 275
	Zachary Friggstad
*/

#include <iostream>

using namespace std;

int main() {
	// caution! If you change this to int8_t then it will in fact be a char so cin and cout will
	// treat it like a char (i.e. cin will read in the first digit as a character)

	// If you want to play with 8-bit integers, you will have to read in 16-bit integers, cast them to 8-bit
	// values, do what you want, and cast it back to a 16-bit integer for output

	int16_t a, b;

	cout << "Enter two signed 16-bit integers: ";
	cin >> a >> b; // if you enter numbers outside the range, cin enters a fail state and refuses to read anything else


	cout << endl << "You entered " << a << " and " << b << endl << endl;

	// without some of the explicit casts to int16_t below, the compiler might try to be
	// smart and interpret the result as a 32-bit number (to avoid overflow)

	cout << "Bitwise and:      " << int16_t(a&b) << endl
	     << "Bitwise or:       " << int16_t(a|b) << endl
	     << "Bitwise xor:      " << int16_t(a^b) << endl
	     << "Bitwise negation: " << int16_t(~a) << " and " << (~b) << endl
	     << "Left shift:       " << int16_t(a<<b) << endl
	     << "Right shift:      " << int16_t(a>>b) << endl;

	return 0;
}