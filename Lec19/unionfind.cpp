#include "unionfind.h"
#include <cassert>

void UnionFind::add_item(int v) {
	if (parent.find(v) == parent.end()) {
		parent[v] = v;
		rank[v] = 0;
	}
}

// Without path compression
// int UnionFind::find(int v) {
// 	// make sure v is in the data structure
// 	assert(parent.find(v) != parent.end());

// 	while (v != parent[v]) {
// 		v = parent[v];
// 	}

// 	return v;
// }

// With path compression
int UnionFind::find(int v) {
	// make sure v is in the data structure
	assert(parent.find(v) != parent.end());
	
	if (v != parent[v]) {
		parent[v] = find(parent[v]);
	}

	return parent[v];
}

bool UnionFind::merge(int u, int v) {
	int rep_u = find(u), rep_v = find(v);

	// already in the same connected component
	if (rep_u == rep_v) {
		return false;
	}

	// redirect the smaller rank to point to the larger rank
	if (rank[rep_u] < rank[rep_v]) {
		parent[rep_u] = rep_v;
	}
	else if (rank[rep_u] > rank[rep_v]) {
		parent[rep_v] = rep_u;
	}
	else {
		// if ranks are the same,
		// point rep_u to rep_v and increase the rank of rep_v
		parent[rep_u] = rep_v;
		rank[rep_v]++;
	}

	return true;
}
