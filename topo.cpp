
/*
* [A] [Question]:  We have a bunch of jobs and each has dependancies, give an order in which the jobs can be completed
*/

#include <iostream>
#include <stdio.h>
#include <list>
#include <stack>
#include <vector>
using namespace std;

#define UNVISITED 0
#define PROCESSING 1
#define VISITED 2

class Graph {
  int numVertices; // Number of vertices in graph
  vector<vector<int> > *adj; // Adj list 
  void TopoSortUtil(vector<vector<int> > *adj, list<int>& ret, vector<int>& visited, int i);
    
public:
  Graph(int V); // Constructor 
  void addEdge(int a, int b); // Add an edge to the graph
  list<int> TopoSort ();
};


Graph::Graph (int V)
{
    numVertices = V;
    adj = new vector<vector<int> >();
    adj->resize(V, vector<int>());
}

// Add an edge to a graph
void Graph::addEdge (int a, int b)
{
    (adj->at(a)).push_back(b);
}


void Graph::TopoSortUtil(vector<vector<int> > *adj, list<int>& ret, vector<int>& visited, int i)
{
  if (visited[i] == VISITED) return;

  // Mark vertex as visited
  visited[i] = PROCESSING;
  
  // Recurse over its adj and so on
  for (auto it = (adj->at(i)).begin(); it != (adj->at(i)).end();  it++) {
    if (visited[*it] == UNVISITED)
      TopoSortUtil(adj, ret, visited, *it);
    else if (visited[*it] == PROCESSING) {
      cout << "Cycle exists at " << i << " to " << *it << "\n";
      exit(1);
    }
  }

  // When you reach a vertex with no adjacencies/completely visited
  ret.push_front(i);
  visited[i] = VISITED;
}

// TopSort Method: Recursively do DFS on a
// vertex and it’s adjacent vertices, till we reach
// a vertex which has already been placed in the visited list,
// or has no other vertices connected to it in the adj list, we then
// push it to a stack. A vertex is pushed on to a stack only when 
// all its adj , ad it adj vertices are processed.
list<int> Graph::TopoSort ()
{
  list<int> ret; // Keep track of top sort

  // Maintain a vector of visited vertices
  // BUG: uninitialized visited
  vector<int> visited(numVertices);
  for (int i = 0; i < numVertices; i++)
       visited[i] = UNVISITED;
  
  // Iterate over all the vertices and call topo sort
  for (int i = 0; i < numVertices; i++)
    TopoSortUtil(adj, ret, visited, i);

  return ret;
}

// Create a graph and call topological sort
int main ()
{
     Graph g(7);
     g.addEdge(0,1);
     g.addEdge(1,3);
     g.addEdge(2,1);
     g.addEdge(6,5);
     g.addEdge(5,4);
     //g.addEdge(3,2);

     // ANSWER: 0 2 1 3 or 2 0 1 3
     list<int> ret = g.TopoSort();
     for (auto it = ret.begin(); it != ret.end(); it++) {
       cout << *it << " ";
     } cout << "\n";
}
