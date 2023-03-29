#include <iostream>
#include <unordered_map>
#include <chrono> // std::chrono is available since C++11
#include <cassert>

using namespace std;

// calculate elapsed time
#define duration(t) chrono::duration_cast<chrono::nanoseconds>(t).count()

// a time point represnting the current time
// now() is a static method of class steady_clock
#define timeNow() chrono::steady_clock::now()

// naive recursive
long long fib(int n) {
	if (n < 2) return n;
	return fib(n-1) + fib(n-2);
}

// top-down DP approach
// pass the hash table by reference to avoid the overhead of copying data
long long fib_td(int n, unordered_map<int, long long> &memo) {
	// since key is an integer, we could use an array instead of 
    // an unordered_map to cache and retrieve the result later
	if (memo.find(n) == memo.end()) {
		// this must be the first time that fib(n) recurses
		if (n < 2) memo[n] = n;
		else memo[n] = fib_td(n-1, memo) + fib_td(n-2, memo);
	}
	// finally return memo[n]
	return memo[n];
}

// bottom-up DP approach
long long fib_bu(int n) {
	long long table[n+1];

	// solving smaller problems first
	for (int i=0; i<=n; i++) {
		if (i < 2) table[i] = i;
		else table[i] = table[i-1] + table[i-2];
	}
	return table[n];
}


int main() {
	int n; 
	long long fib_n;
	cin >> n;
	assert (n>=0);

	// measuring the execution time...
	auto start = timeNow();
	fib_n = fib(n);
	cout << "Execution time of fib(n): " << duration(timeNow()-start) << "ns" << endl;
	cout << "fib(n) is: " << fib_n << endl;

	
	// declare a hash table for caching the solution of each subproblem
	// key: the argument of the fib function
	// value: return value of that function
	unordered_map<int, long long> table;

	// measuring the execution time...
	start = timeNow();
	fib_n = fib_td(n, table);
	cout << "Execution time of fib_td(n): " << duration(timeNow()-start) << "ns" << endl;
	cout << "fib_td(n) is: " << fib_n << endl;

	start = timeNow();
	fib_n = fib_bu(n);
	cout << "Execution time of fib_bu(n): " << duration(timeNow()-start) << "ns" << endl;
	cout << "fib_bu(n) is: " << fib_n << endl;
	
	return 0;
}