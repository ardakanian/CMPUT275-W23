/*
  Implementation of the breadth-first search algorithm

  Course: CMPUT 275
  Omid Ardakanian, University of Alberta (2023)
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <list>
#include "digraph.h"
using namespace std;

void dfs(const Digraph& graph, const int u, const int prev, unordered_map<int, int> & reached) {
  if (reached.find(u) != reached.end())
    return; // it was visited before

  reached[u] = prev;

  // Iterate over all neighbours of u
  for (auto itr = graph.neighbours(u); itr != graph.endIterator(u); ++itr) {
    dfs(graph, *itr, u, reached);
  }
}

void nonrecursive_dfs(const Digraph& graph, const int start, unordered_set<int> & reached) {
  stack<int> unexplored;
  unexplored.push(start);

  while (!unexplored.empty()) {
    // Pick the 'newest' unexplored vertex u
    int u = unexplored.top();
    unexplored.pop();

    if (reached.find(u) != reached.end())
      continue;

    reached.insert(u);

    // Iterate over all neighbours of u
    for (auto itr = graph.neighbours(u); itr != graph.endIterator(u); ++itr) {

      // Check if it has been reached previously
      if (reached.find(*itr) == reached.end()) {

        // Add it to stack but do NOT add it to the reached set yet!
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
    dfs(graph, start, start, search_tree);

    // Non-recursive implementation
    // unordered_set<int> new_search_tree = {};
    // nonrecursive_dfs(graph, start, new_search_tree);

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
        vertex = search_tree[vertex]; // Crawl up the tree
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
