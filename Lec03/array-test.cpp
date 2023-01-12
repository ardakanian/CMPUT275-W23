/*
	A simple demonstration of arrays and strings

	Course: CMPUT 275
	Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	int coins[8] = {1, 5, 10, 25, 50, 100, 200}; 
	// last element is set to zero

	cout << coins[7] << endl;
	cout << sizeof coins << endl;
	cout << sizeof coins[0] << endl << endl;

	int addresses[] = {1, 2, 3};	
	// let the compiler set the length

	cout << addresses << endl;
	cout << addresses[2] << endl;
	cout << sizeof addresses << endl << endl;

	char mystr[7] = "cat";
	// null terminated
	cout << sizeof "cat" << endl;	
	cout << sizeof mystr << endl;
	// number of characters before the null character
	cout << strlen("cat") << endl;	
	cout << strlen(mystr) << endl;
	cout << mystr << endl << endl;

	// mystr[3] = 'e';
	mystr[4] = 'r';
	cout << mystr << endl << endl;

	strcat(mystr, "dog");
	cout << mystr << endl;

	string newstr = "ping";
	newstr[0] = 'w';
	cout << newstr << endl;
	newstr = "can";					// auto resized
	cout << newstr << endl;

	return 0;
}