/*
	Contains an implementation of Kruskal's MST algorithm using the
	union-find data structure.

	Zac Friggstad, 2021

	Reads input in the format:

	First line:
	n m
	(n == # nodes, m = # edges)

	Then m lines follow, each of the form
	u v c
	describing an edge connecting u to v with cost c.

	The vertices are assumed to be labelled from 0 to n-1.

	You can put extra comments at the bottom of a .txt file containing the
	description of a graph, they will not be read by this program.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>	// std::sort
#include "unionfind.h"

using namespace std;

/*
	To model an edge (mainly for sorting them by cost)
*/
class Edge {
public:
	int u, v, cost;
	bool operator<(const Edge& rhs) const {
		return cost < rhs.cost;
	}
};

int main() {
	// n == number of nodes
	int n, m;
	cin >> n >> m;

	// Read in the vertices and initialize the union find data structure
	// by adding all vertices one at a time.
	UnionFind uf;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		uf.add_item(v);
	}

	// Read in the edges.
	vector<Edge> edges(m);

	// Using a range-based for loop
	// Declaring this by reference allows us to read directly into the vector.
	// This is equivalent to
	// for (int i = 0, i < m; i++) {
	//   cin >> e[i].u >> e[i].v >> e[i].cost;
	// }
	for (Edge& e : edges) {
		cin >> e.u >> e.v >> e.cost;
	}

	// Kruskal's algorithm: first sort them in increasing order of cost.

	// std::sort sorts the elements in the range [first,last) into ascending order.
	// the edges are compared using operator< 
	sort(edges.begin(), edges.end());

	// Try merging the components by processing the edges in order of cost.
	// Every successful merge means we bridge two previously-disconnected
	// components so we should add the edge to the MST we are building.
	vector<Edge> mst;
	int mstCost = 0;
	for (Edge e : edges) {
		// merge does nothing if they are already in the same part
		if (uf.merge(e.u, e.v)) {
			mst.push_back(e);
			mstCost += e.cost;
		}
	}

	cout << "Minimum spanning tree has cost " << mstCost << endl;
	cout << "Edges:" << endl;
	for (Edge e : mst) {
		cout << "(" << e.u << "," << e.v << ") - with cost: " << e.cost << endl;
	}

	return 0;
}
