#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;

/*
  Represents a graph using an adjacency list representation.
  Vertices are assumed to be integers.
*/
class Digraph {
public:
  // no constructor or destructor are necessary this time.
  // a new instance will be an empty graph with no nodes.

  // add a vertex, does nothing if it already exists
  void addVertex(int v);

  // adds an edge, creating the vertices if they do not exist
  // if the edge already existed, does nothing
  void addEdge(int u, int v);

  // returns true if and only if v is a vertex in the graph
  bool isVertex(int v);

  // returns true if and only if (u,v) is an edge in the graph
  // will certainly return false if neither vertex is in the graph
  bool isEdge(int u, int v);

  // returns a const iterator to the neighbours of v
  unordered_set<int>::const_iterator neighbours(int v) const;

  // returns a const iterator to the end of v's neighour set
  unordered_set<int>::const_iterator endIterator(int v) const;

  // return the number of outgoing neighbours of v
  int numNeighbours(int v);

  // returns the number of nodes
  int size();

  // return a vector with all vertices
  vector<int> vertices();
  
  // returns true if 'walk' represents a walk on this graph
  // A walk is a sequence of vertices (perhaps with repeated vertices) 
  // v0, v1, . . . , vk where (vi,vi+1) is an edge for each 0 <= i < k.
  // the length of a walk is the number of edges traversed 
  bool isWalk(vector<int> walk);

  // returns true if 'path' represents a path on this graph
  // a path is a walk with no repeated vertices
  bool isPath(vector<int> path);

private:
  // with this representation the amortized time for 
  // finding or adding a vertex or an edge is O(1)
  unordered_map<int, unordered_set<int>> nbrs;
};

#endif
