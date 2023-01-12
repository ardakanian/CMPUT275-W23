/*
	A C++ program that prints the size of data types, variables, and literals

	Course: CMPUT 275
	Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>
using namespace std;

void var_size() {
	cout << "char takes " << sizeof(unsigned char) << " bytes" << endl;
	cout << "short takes " << sizeof(short) << " bytes" << endl;
	cout << "int takes " << sizeof(int) << " bytes" << endl;
	cout << "long takes " << sizeof(long) << " bytes" << endl;
	cout << "long long takes " << sizeof(long long) << " bytes" << endl;
	cout << "float takes " << sizeof(float) << " bytes" << endl;
	cout << "double takes " << sizeof(double) << " bytes" << endl;
	cout << "long double takes " << sizeof(long double) << " bytes" << endl << endl;
}

int main() {
	var_size();

	int num = 0x7c;
	cout << hex << "hex format: " << num << endl;
	cout << dec << "dec format: " << num << endl;
	cout << oct << "octal format: " << num << dec << endl << endl;

	cout << sizeof -1.23E-3F << endl;
	cout << sizeof -1.23E-3 << endl << endl;

	cout << sizeof "cat" << endl;
	cout << sizeof "c" << endl;
	cout << sizeof 'c' << endl << endl;

	double dnum = -1.23E-3F;
	cout << sizeof dnum << endl;

	short snum = 10;
	auto total = num + snum;
	cout << sizeof total << endl;

	auto sum = long(10) + snum;
	cout << sizeof sum << endl;

	return 0;
}
