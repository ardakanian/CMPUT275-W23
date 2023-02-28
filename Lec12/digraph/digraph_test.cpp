#include <iostream>
#include <vector>
#include "digraph.h"

using namespace std;

int main() {
  Digraph graph;

  graph.addVertex(1);
  graph.addVertex(4);
  graph.addEdge(5, 4);
  graph.addEdge(4, 100);
  graph.addEdge(4, 1);
  graph.addEdge(1, 4);

  cout << "size() - " << graph.size() << endl;
  graph.addVertex(1);
  cout << "size() - " << graph.size() << endl;

  cout << "isVertex(100) - " << graph.isVertex(100) << endl;
  cout << "isVertex(4) - " << graph.isVertex(4) << endl;
  cout << "isVertex(0) - " << graph.isVertex(0) << endl;
  graph.addVertex(0);
  cout << "isVertex(0) - " << graph.isVertex(0) << endl;

  cout << "isEdge(5, 4) - " << graph.isEdge(5, 4) << endl;
  cout << "isEdge(4, 7) - " << graph.isEdge(4, 7) << endl;
  graph.addEdge(7, 4);
  cout << "isEdge(4, 7) - " << graph.isEdge(4, 7) << endl;
  graph.addEdge(4, 7);
  cout << "isEdge(4, 7) - " << graph.isEdge(4, 7) << endl;

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

  // cout << "neighbours(123) - would crash the program" << endl;
  // graph.neighbours(123);

  vector<int> p1;
  cout << "isWalk() - " << graph.isWalk(p1) << endl;
  cout << "isPath() - " << graph.isPath(p1) << endl;

  p1.push_back(7); 

  cout << "isWalk(7) - " << graph.isWalk(p1) << endl;
  cout << "isPath(7) - " << graph.isPath(p1) << endl;
  
  p1.push_back(4); 
  p1.push_back(1); 

  cout << "isWalk(7, 4, 1) - " << graph.isWalk(p1) << endl;
  cout << "isPath(7, 4, 1) - " << graph.isPath(p1) << endl;

  p1.push_back(4);

  cout << "isWalk(7, 4, 1, 4) - " << graph.isWalk(p1) << endl;
  cout << "isPath(7, 4, 1, 4) - " << graph.isPath(p1) << endl;

  p1.push_back(5);

  cout << "isWalk(7, 4, 1, 4, 5) - " << graph.isWalk(p1) << endl;
  cout << "isPath(7, 4, 1, 4, 5) - " << graph.isPath(p1) << endl;

  return 0;
}
