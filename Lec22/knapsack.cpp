#include <iostream>
#include <algorithm>		// std::max
#include <unordered_map>

using namespace std;

typedef pair<int,int> PII;

struct PairHash { 
	// a function object class, defines operator() const

	template <class K1, class K2>
	size_t operator()(const pair<K1, K2> &pair) const {
		// std::hash is unary function object class

		auto hash_first = hash<K1>()(pair.first);
		auto hash_second = hash<K2>()(pair.second);

		// is (hash_first ^ hash_second) a good hash function? 
		// too many collisions: hash of (a, a) is always zero 
		// and hash of (a, b) is the same as hash of (b, a)
		if (hash_first != hash_second)
			return hash_first ^ hash_second; // taking xor

		return hash_first;
	}
};

// returns the max total value for a subset of the n items
// that fit in the knapsack (i.e., their total weight <= c)
int knapsack(const int *values, const int *weights, int n, 
	int c, unordered_map<PII,int,PairHash> &memo) {

	// make the key pair
	PII mpair(n, c); 
	if (memo.find(mpair) == memo.end()) { 
		int max_val;

		// subproblem not solved before
		if (n == 0 || c == 0) 
			max_val = 0; // base case
		else if (weights[n-1] > c) 
			// we can't pack the nth item because it's too heavy
			max_val = knapsack(values, weights, n-1, c, memo);
		else {
			int v1, v2;
			// case 1: we pack the nth item
			v1 = knapsack(values, weights, n-1, c-weights[n-1], memo) + values[n-1];
			// case 2: we don't pack the nth item
			v2 = knapsack(values, weights, n-1, c, memo);

			// pick the one that results in a higher value
			max_val = max(v1, v2);
		}
		// memoize/cache the result
		memo[mpair] = max_val;
	}
	return memo[mpair];
}

// returns the max total value for a subset of the n items
// that fit in the knapsack (i.e., their total weight <= c)
int knapsack_bu(const int *values, const int *weights, int n, int c) {
	int table[n+1][c+1]; // initialize to zero
	// table[i][j] is the max value that can be obtained by
	// packing the first i items in a knapsack with capacity j


	for (int i=0; i<=n; ++i) {
		for (int j=0; j<=c; ++j) {
			if (i == 0 || j == 0) { // base case
				table[i][j] = 0;
				continue;
			}

			if (j < weights[i-1])
				table[i][j] = table[i-1][j];
			else
				table[i][j] = max(table[i-1][j], values[i-1]+table[i-1][j-weights[i-1]]);
		}
	}

	return table[n][c];
}

int main() {
	int nitems, capacity; 
	cout << "Enter the number of items: ";
	cin >> nitems;
	cout << "Enter the capacity of your knapsack: ";
	cin >> capacity;

	int *values = new int[nitems];
	int *weights = new int[nitems];

	cout << "Enter the value of each item:" << endl;
	for (int i=0; i<nitems; i++) {
		cin >> values[i];
	}
	cout << "Enter the weight of each item:" << endl;
	for (int i=0; i<nitems; i++) {
		cin >> weights[i];
	}

	unordered_map<PII, int, PairHash> cache;
	int total = knapsack(values, weights, nitems, capacity, cache);
	cout << "max total value of the items in your knapsack: " << total << endl;

	total = knapsack_bu(values, weights, nitems, capacity);
	cout << "max total value of the items in your knapsack: " << total << endl;

	delete [] values;
	delete [] weights;

	return 0;
}