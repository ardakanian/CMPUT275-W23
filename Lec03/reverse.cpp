/*
	Manipulating c-style strings and string objects

	Course: CMPUT 275
	Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>
#include <cstring>  // for operations on c-style strings
#include <string>   // for string class

// function prototypes
void reverse_inplace_string();
void reverse_inplace_carray();
void reverse_carray();

using namespace std;

int main() {
	cout << "Enter a word: ";
	reverse_inplace_string();
	return 0;
}

void reverse_inplace_string() {
	string str;
	cin >> str;
	for (int i = str.size() - 1; i > (str.size() - 1)/2; i--){
		char temp = str[i];
		str[i] = str[str.size() - 1 - i];
		str[str.size() - 1 - i] = temp;
	}
	cout << str << endl;
}

void reverse_inplace_carray() {
	char mystr[10] = {};
	cin >> mystr;
	// cout << mystr << " " << sizeof mystr << " " << strlen(mystr) << endl;

	for (int i = strlen(mystr)-1; i > (strlen(mystr)-1)/2; i--)
	{
		char temp = mystr[i];
		mystr[i] = mystr[strlen(mystr)-1-i];
		mystr[strlen(mystr)-1-i] = temp;
	}
	cout << mystr << endl;
}

void reverse_carray() {
	char mystr[10] = {};
	char reversed[10] = {};
	cin >> mystr;
	// cout << mystr << " " << sizeof mystr << " " << strlen(mystr) << endl;

	for (int i = strlen(mystr)-1; i>=0; i--)
	{
		reversed[strlen(mystr)-1-i] = mystr[i];
	}
	cout << reversed << endl;
}