/*
	Implementation of the union-find data structure
	for the int type (i.e. the set we are partitioning
	is a set of integers).

	We can easily extend it to a generic type T specified
	as a template parameter, but we stuck to the int type
	to reduce the amount of code.
*/

#ifndef _UNION_FIND_H_
#define _UNION_FIND_H_

#include <unordered_map>

using namespace std;

class UnionFind {
public:
	// A constructor is not necessary, the parent and rank
	// mappings will just be empty upon initialization.

	// Adds an item to the data structure, if it was there already
	// then it does nothing (it does not change the partition).
	// If not, it is added as a singleton part {v} in the partition.
	void add_item(int v);

	// Finds the representative for the set containing u.
	int find(int u);

	// Merges the two sets, returns true if the merge was successful
	// (i.e. they were not in the same part already).
	// We can't use the function name "union" :(  
	// It is a keyword in C++. So we call it "merge"
	bool merge(int u, int v);

private:
	// maps an item to its parent
	unordered_map<int, int> parent;

	// maps an item to its rank
	unordered_map<int, int> rank;
};

#endif
