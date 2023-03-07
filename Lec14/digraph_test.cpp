#include <iostream>
#include <vector>
#include "wdigraph.h"

using namespace std;

int main() {
  WDigraph graph;
  
  graph.addVertex(1);
  graph.addVertex(4);
  graph.addEdge(5, 4, 2);
  graph.addEdge(4, 100, 1);
  graph.addEdge(4, 1, 10);
  graph.addEdge(1, 4, 5);
  graph.addEdge(7, 4, 5);
  graph.addEdge(4, 7, 3);

  cout << "size() - " << graph.size() << endl;
  graph.addVertex(1);
  cout << "size() - " << graph.size() << endl;

  cout << "isVertex(0) - " << graph.isVertex(0) << endl;
  graph.addVertex(0);
  cout << "isVertex(0) - " << graph.isVertex(0) << endl;

  cout << "isEdge(5, 4) - " << graph.isEdge(5, 4) << endl;
  cout << "getCost(5, 4) - " << graph.getCost(5, 4) << endl;
  
  // graph.addEdge(5, 4, 3);
  // cout << "getCost(5, 4) - " << graph.getCost(5, 4) << endl;

  // cout << "getCost(4, 5) - should throw an exception since the key is not present" << graph.getCost(4, 5) << endl;

  cout << "numNeighbours(4) - " << graph.numNeighbours(4) << endl;

  cout << endl;
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
