/*
	An example of recursion
	Use the backtrace command in gdb

	Course: CMPUT 275
	Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>
#include <cassert>	// for assert statement

using namespace std;

int fib(int n);
int fib_recursive(int n);

int main() {
	int n;
	cin >> n;

	// if false, a message is written stderr and abort is called
	assert(n>=0);

	cout << "fib(" << n << ") = " << fib(n) << endl;
	cout << "fib_recursive(" << n << ") = " << fib_recursive(n) << endl;
	return 0;
}

int fib_recursive(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fib_recursive(n-1) + fib_recursive(n-2); 
}

int fib(int n) {
	int temp, first = 0, second = 1, index = 2;
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		while (index <= n) {
			temp = first;
			first = second;
			second += temp;
			index++; 
		}
	}
	return second;
}
