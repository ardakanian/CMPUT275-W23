#include "digraph.h"

using namespace std;

void Digraph::addVertex(int v) {
  // if it already exists, does nothing.
  // otherwise, adds v with an empty adjacency set.
  nbrs[v];
}

void Digraph::addEdge(int u, int v) {
  // making sure v is in the set of vertices.
  addVertex(v);
  
  // calling addVertex(u) is not necessary.
  // nbrs[u] adds u if it does not exist already.
  nbrs[u].insert(v);
}

bool Digraph::isVertex(int v) {
  // check if v is in the keys

  // recall that unordered_map/set returns the
  // past-the-end iterator if no such key is found
  return nbrs.find(v) != nbrs.end();
}

bool Digraph::isEdge(int u, int v) {
  // check if u is in the keys and that its associated set contains v
  return nbrs.find(u) != nbrs.end() && nbrs[u].find(v) != nbrs[u].end();
}

unordered_set<int>::const_iterator Digraph::neighbours(int v) const {
  // nbrs.find(v) returns an iterator pointing to key-value pairs
  // this will crash the program if v is not a vertex
  return nbrs.find(v)->second.begin();
}

unordered_set<int>::const_iterator Digraph::endIterator(int v) const {
  // nbrs.find(v) returns an iterator pointing to key-value pairs
  // this will crash the program if v is not a vertex
  return nbrs.find(v)->second.end();
}

int Digraph::numNeighbours(int v) {
  // this will crash the program if v is not a vertex
  return nbrs.find(v)->second.size();
}

int Digraph::size() {
  // number of vertices
  return nbrs.size();
}

vector<int> Digraph::vertices() {
  vector<int> v;
  for (unordered_map<int, unordered_set<int>>::const_iterator it = nbrs.begin();
    it != nbrs.end(); it++) {
      v.push_back(it->first);
    }
  return v;
}

bool Digraph::isWalk(vector<int> walk) {
  if (walk.size() == 0)
    return false;
  if (walk.size() == 1)
    return isVertex(walk[0]);
  for (vector<int>::size_type i=0; i<walk.size()-1; i++)
    if (!isEdge(walk[i], walk[i+1]))
      return false;

  return true;

}

bool Digraph::isPath(vector<int> path) {
  // using the range constructor of set
  set<int> s(path.begin(), path.end());

  // check if there are repeated vertices
  if (s.size() < path.size())
    return false;

  return isWalk(path);
}
