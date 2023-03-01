/*
  Implementation of the breadth-first search algorithm

  Course: CMPUT 275
  Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include "digraph.h"
using namespace std;

void bfs(const Digraph& graph, const int start, unordered_map<int, int> & reached) {
  reached[start] = start;
  queue<int> unexplored;
  unexplored.push(start);

  while (!unexplored.empty()) {
    // Pick the 'oldest' unexplored vertex u
    int u = unexplored.front();
    unexplored.pop();

    // Iterate over all neighbours of u
    for (auto itr = graph.neighbours(u); itr != graph.endIterator(u); ++itr) {

      // Check if it has been reached previously
      if (reached.find(*itr) == reached.end()) {

        // If it's reached for the first time add it to both containers
        reached[*itr] = u;
        unexplored.push(*itr);
      }
    }
  }
}

int main() {
  Digraph graph;

  int nv, ne, nq;
  cin >> nv >> ne >> nq;

  // Read vertex IDs
  for (int i = 0; i < nv; ++i) {
    int label;
    cin >> label;
    graph.addVertex(label);
  }

  // Read directed edges
  for (int i = 0; i < ne; ++i) {
    int u, v;
    cin >> u >> v;
    graph.addEdge(u, v);
  }

  int start, vertex;
  for (int i = 0; i < nq; ++i) {
    // Read the start vertex
    cin >> start;

    // Solve the graph reachability problem
    unordered_map<int, int> search_tree = {};
    bfs(graph, start, search_tree);

    // Print the subset of all vertices reachable from 'vertex'
    cout << "Set of vertices reachable from " << start << ":" << endl;
    for (unordered_map<int, int>::iterator itr = search_tree.begin(); itr != search_tree.end(); ++itr) {
      cout << itr->first << endl;
    }
    cout << endl;

    // Read the end vertex
    cin >> vertex;
    list<int> path;
    if (search_tree.find(vertex) == search_tree.end()) {
      cout << "No path found!" << endl;
    } else {
      cout << "A path between " << start << " and " << vertex << ":" << endl;

      // Recover the path
      while (vertex != start) {
        path.push_back(vertex);
        vertex = search_tree[vertex];
      }
      path.push_back(start);
      path.reverse();
      for (list<int>::iterator itr = path.begin(); itr != path.end(); ++itr) {
        cout << *itr << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
