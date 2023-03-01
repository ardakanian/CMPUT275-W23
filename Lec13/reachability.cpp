/*
  Implementation of the basic reachability algorithm

  Course: CMPUT 275
  Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>
#include <unordered_set>
#include "digraph.h"

using namespace std;

unordered_set<int> reachability(const Digraph& graph, int v) {
  unordered_set<int> reached = {v}, unexplored = {v};
  
  while (unexplored.size()>0) {
    // dereferencing the iterator to get an unexplored node
    int u = *unexplored.begin();

    // remove that node from the unexplored set
    // recall: unordered_set makes no guarantees about 
    // the order in which elements are extracted
    unexplored.erase(unexplored.begin()); 

    // consider neighbours of that node
    for (auto iter = graph.neighbours(u); iter != graph.endIterator(u); iter++) {
      if (reached.find(*iter) == reached.end()) {
        // if not reached before

        reached.insert(*iter);
        unexplored.insert(*iter);
      }
    }
  }

  return reached;
}

int main() {
  Digraph graph;

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int label;
    cin >> label;
    graph.addVertex(label);
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph.addEdge(u, v);
  }
  int vertex;
  cin >> vertex;

  // solve the graph reachability problem
  unordered_set<int> reachable_set = reachability(graph, vertex);

  // print the subset of all vertices reachable from 'vertex'
  cout << "Set of vertices reachable from " << vertex << ":" << endl;
  for (unordered_set<int>::iterator it = reachable_set.begin(); it != reachable_set.end(); ++it) {
    cout << (*it) << endl;
  }
  cout << endl;

  return 0;
}
