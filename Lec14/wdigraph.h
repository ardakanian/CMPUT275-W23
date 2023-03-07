#ifndef _WEIGHTED_GRAPH_H_
#define _WEIGHTED_GRAPH_H_

#include <unordered_map>
#include "digraph.h"

using namespace std;

/*
Represents a weighted graph using the adjacency list representation.
Vertex identifiers are of type int. Weights are of type long long. 
*/

// WDigraph extends Digraph
class WDigraph : public Digraph {
public:
  // No constructor or destructor are necessary this time.
  // A new instance will be an empty graph with no nodes.

  // Adds a weighted edge (overriding the base class method)
  // if the edge already existed, does nothing
  void addEdge(int u, int v, long long w){
    // Calling Digraph's addEdge()
    Digraph::addEdge(u, v);
    cost[u][v] = w;
  }

  // Returns the cost/weight of an edge
  // if it does not exist, returns error
  long long getCost(int u, int v) const {
    // Using at() here instead of operator[] because: 
    // (1) getCost is a const method so it receives a const 'this' pointer
    // (2) the cost attribute is accessed using the const 'this' pointer 
    //     so it is const 
    // (3) there is no const version of operator[] for class unordered_map
    return cost.at(u).at(v);
  }

private:
  unordered_map<int, unordered_map<int, long long>> cost;
};

#endif
