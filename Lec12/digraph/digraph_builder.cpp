#include <iostream>
#include "digraph.h"

using namespace std;

// FORMAT
// n m - number of nodes and edges
// list of all n node labels (integers)
// m lines, each giving an edge (u,v)

int main() {
  Digraph graph;
  int vcount, ecount, v, s, t;
  cin >> vcount >> ecount;
  for (int i=0; i<vcount; i++) {
    cin >> v;
    graph.addVertex(v);
  }
  for (int i=0; i<ecount; i++) {
    cin >> s >> t;
    graph.addEdge(s, t);
    graph.addEdge(t, s);
  }
  cout << "Entire adjacency list:" << endl;
  vector<int> vertices = graph.vertices();
  for (auto v : vertices) {
    cout << v << ':';
    for (auto iter = graph.neighbours(v); iter != graph.endIterator(v); iter++) {
      cout << ' ' << *iter;
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
