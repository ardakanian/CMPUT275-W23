#include <iostream>
#include <unordered_map>
#include <list>
#include <utility> // for std::pair
// pair is a simple container of two heterogeneous objects
// which can be accessed using the dot operator followed by 
// first or second keyword
#include "wdigraph.h"

using namespace std;

// typedef creates an alias for the specified type
// PIL is the value type of our searchTree 
typedef pair<int, long long> PIL;

// PIPIL is used to insert a key-value pair in our searchTree
// if we declare a variable 'x' as follows:  PIPIL x;
// x.first gives the start vertex of the edge, 
// x.second.first gives the end vertex of the edge, 
// x.second.second gives the cost of the edge
typedef pair<int, PIL> PIPIL;

void dijkstra(const WDigraph& graph, int startVertex, 
    unordered_map<int, PIL>& searchTree) {

    // each active fire is stored as (v, (u, d)) 
    // which implies that it is a fire started at u
    // currently burning the (u,v) edge 
    // and will reach v at time d
    
    // We use a doubly linked list but it can be replaced with a min heap
    // for a more efficient implementation
    // finding and extracting the 'earliest' fire that reaches another vertex
    // is O(N) in a list with N items, but O(log N) in a (binary) min heap
    list<PIPIL> fires;

    // at time 0, the startVertex burns, we set the predecesor of
    // startVertex to startVertex (as it is the first vertex)
    fires.push_back(PIPIL(startVertex, PIL(startVertex, 0)));

    // while there is an active fire
    while (!fires.empty()) {
        // finding the fire that reaches its endpoint earliest
        auto earliestFire = fires.begin();
        for (auto iter = fires.begin(); iter != fires.end(); ++iter) {
            if (iter->second.second < earliestFire->second.second) {
                earliestFire = iter;
            }
        }

        int v = earliestFire->first; 
        int u = earliestFire->second.first; 
        long long d = earliestFire->second.second;

        // remove this fire
        fires.erase(earliestFire);

        // if v is already "burned", there nothing to do
        if (searchTree.find(v) != searchTree.end()) {
            continue;
        }

        // record that 'v' is burned at time 'd' by a fire started from 'u'
        searchTree[v] = PIL(u, d);

        // now start fires from all edges exiting vertex 'v'
        for (auto iter = graph.neighbours(v); iter != graph.endIterator(v); iter++) {
            int nbr = *iter;

            // 'v' catches on fire at time 'd' and the fire will reach 'nbr'
            // at time d + (length of v->nbr edge)
            long long t_burn = d + graph.getCost(v, nbr);
            fires.push_back(PIPIL(nbr, PIL(v, t_burn)));
        }
    }
}

int main() {
    WDigraph graph;

    int startVertex, endVertex;

    // reading in the graph
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int label;
        cin >> label;
        graph.addVertex(label);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        graph.addEdge(u, v, c);
    }
    cin >> startVertex >> endVertex;


    // run the search
    // searchTree[v] will be the pair (u,d) of the node u prior to v
    // in a shortest path to v and d will be the shortest path distance to v
    unordered_map<int, PIL> searchTree;
    dijkstra(graph, startVertex, searchTree);

    // read off a path
    list<int> path;
    if (searchTree.find(endVertex) == searchTree.end()) {
      cout << "Vertex " << endVertex << " not reachable from " << startVertex << endl;
    }
    else {
      int stepping = endVertex;
      while (stepping != startVertex) {
        path.push_front(stepping);

        // crawl up the search tree one step
        stepping = searchTree[stepping].first;
      }
      path.push_front(startVertex);

      cout << "The cost of the least-cost path from " << startVertex << " to "
           << endVertex << " is: " << searchTree[endVertex].second << endl;
      cout << "Path:";
      for (auto it : path) {
        cout << ' ' << it;
      }
      cout << endl;
    }

    return 0;
}
