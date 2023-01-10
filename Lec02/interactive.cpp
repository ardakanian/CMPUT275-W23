/*
	Showcasing type conversion and working with iostream objects

	Course: CMPUT 275
	Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>
#include <cctype>	// for toupper(), tolower(), isupper(), islower()
#include <cmath>	// for pow()

using namespace std;

void int_builder();

int main()
{
	char c1, c2;
	cin >> c1 >> c2;

	// toupper() takes int and returns int
	cout << (char) toupper(c1) << (char) toupper(c2) << endl;

	char c = 1;
	while(c != '\t') {
		cin.get(c);
		cout << c;
	}
	cout << endl;

	// int_builder();

	return 0;
}

void int_builder() 
{
	int nd, digit, num = 0;
	cin >> nd;
	while(nd>0) {
		cin >> digit;
		num += digit * pow(10, nd-1);
		nd--;
	} 
	cout << num << endl;
} 
