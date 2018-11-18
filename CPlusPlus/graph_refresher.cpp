#include <iostream>
#include<vector>
#include<queue>

using namespace std;

#define UNVISITED 0
#define PROCESSING 1 
#define VISITED 2

// Directed graph
class Graph {
  public:
    // Constructor to create an adj list of size numNodes
    Graph(int numNodes) {
        adj = new vector<vector<int>>(numNodes);
        num_vertices = numNodes;
    }  
    
    void printVector(vector<vector<int>> v) {
      for (auto it = v.begin(); it != v.end(); it++) {
          cout << "Path: ";
          for (auto iter = (*it).begin(); iter != (*it).end(); iter++) {
            cout << *iter << " "; 
          }
          cout << "\n";
      }
    }
  
    void printAdjList() {
      if (adj) {
        int start_edge = 0;
        for (auto it = adj->begin(); it != adj->end(); it++) {
            for (auto sub_iter = (*it).begin(); sub_iter != (*it).end(); sub_iter++) {
              cout<< start_edge << "-->" << *sub_iter << "\n"; 
            }
            start_edge++;
        }
      }
    }
  
    void addEdge(int from, int to) {
      if (adj) {
        adj->at(from).push_back(to);
      }
    }

    // Remember DFS doesn’t need to be recursive
    bool doesPathExist (int from, int to) {
      if (from == to)
          return true;

      // Mark all vertices as unvisited
      vector<bool> visited(num_vertices, false);
      
      // To track which level is being processed
      queue<int> q;
      
      // Add from vertex to queue, mark as visited
      visited[from] = true;
      q.push(from);
      
      
      while (!q.empty()) {
          
          int curr = q.front();
          q.pop();
        
          // Iterate over all adjacencies of a given node and add them to the q
          for (auto it = adj->at(curr).begin(); it != adj->at(curr).end(); it++) {
              
              // If the to vertex is found, return true
              if (to == (*it)) {
                  return true; 
              }
              
              // To vertex not found, still traversing
              if (visited[*it] != true) {
                  visited[*it] = true;
                  q.push(*it);  
              }
          }

      }
      
      // No path found to node
      return false;  
   }

    vector<vector<int>> printPath(int from, int to) {
        
        
        vector<vector<int>> paths;  
        vector<int> *res = new vector<int>;
      
        // If from and to are same
        if (from == to) {
            res->push_back(from);
            paths.push_back(*res);
            return paths; 
        }
      
        // Keep track of which nodes have been visited (none so far)
        vector<bool> visited(num_vertices, false);
        
        // Create a queue for BFS, push from node, mark as visited
        queue<int> q;
        q.push(from);
        visited[from] = true;
        
        while (!q.empty()) {
          int curr = q.back();
          
          // Save sub path node
          res->push_back(curr);
          q.pop();
          
          // For each adjacency of node curr, if not visited, visit and add to queue
          for (auto it = adj->at(curr).begin(); it != adj->at(curr).end(); it++) {
            
              // If to node is found, path end found
              if (to == *it) {
                  res->push_back(*it);
                  paths.push_back(*res);
                  res = new vector<int>; 
              }
              
              if (visited[*it] != true) {
                  visited[*it] = true;
                  q.push(*it);
              }
          }
        }
        return paths;
    }
  
    vector<vector<int>> findAllPaths(int from, int to) {
      // Maintain a visited vector
      vector<bool> *visited = new vector<bool>(num_vertices, false);
      
      vector<vector<int>> paths;
      vector<int> *sub = new vector<int>;
      cout << "Here are the paths from " << from << " to " << to << " : \n";
      doDFS(from, to, visited, &paths, sub);
      if (paths.empty()) {
        cout << "No paths exist!\n";  
      }
      return paths;
    }
  
    bool hasCycles () {
        // Simple DFS: Keep track of all visited nodes, 
        // nodes in process, completely processed nodes
        
        // Mark all nodes unvisited
        vector<int> state(num_vertices, UNVISITED);  
      
        // Do a dfs for all nodes
        for (int i = 0; i < num_vertices; i++) {
            if (state[i] == UNVISITED) {
                if (simpleDFS(&state, i) == true) {
                    return true;      
                }
            }
        }
        return false;
    }
  
    bool simpleDFS(vector<int> *state, int from) {
      
      // Mark node as in process
      state->at(from) =  PROCESSING;
      
      // For each neighbor of from node, do a dfs.
      for (auto it = adj->at(from).begin(); it != adj->at(from).end(); it++) {
            if (state->at(*it) == UNVISITED && simpleDFS(state, *it)) {
                cout << "Here for node " << *it << " \n";
                return true; // Cycle exists in subtree rooted at *it
            } else if (state->at(*it) == PROCESSING) {
                cout << "Here diff for node " << *it << " \n";
                return true; // Cycle exists at current node
            }
      }
      
      state->at(from) = VISITED;
      return false;
    }
  
  private:
    vector<vector<int>> *adj;
    int num_vertices;
    
    void doDFS (int from, int to, vector<bool> *visited, vector<vector<int>> *paths, vector<int> *sub) {
      // Mark current node as visited
      visited->at(from) = true;
      sub->push_back(from);
      
      // If we reached the destination, push back partial sub to result
      if (from == to) {
          paths->push_back(*sub);
          for (auto it = sub->begin(); it != sub->end(); it++) {
            cout << *it << " ";
          }
          cout << "\n";
          for (unsigned i = 1; i <= sub->size(); i++) {
              sub->pop_back();  
          }
      }
      
      // For each adjacency of the current node, do dfs on neighbor one at a time
      for (auto it = adj->at(from).begin(); it != adj->at(from).end(); it++) {
          if (visited->at(*it) != true || (*it == to)) {
              doDFS(*it, to, visited, paths, sub);  
          }
      }
    }
  
};

// To execute C++, please define "int main()"
int main() {
  
  // Create Graph
  Graph g(5);
  
  g.addEdge(0,1);
  g.addEdge(1,0);
  g.addEdge(0,2);
  g.addEdge(1,4);
  g.addEdge(2,4);
  g.addEdge(3,1);
  g.printAdjList();
  
  // Determine if a path exists between two nodes in graph
  bool path =  g.doesPathExist(4, 3);
  if (path) {
      cout << "Path exists!\n"; 
  } else {
      cout << "Path does not exist!\n"; 
  }
  
  // Determine all paths between two nodes in graph
  vector<vector<int>> paths = g.findAllPaths(0,4);
  
  // Determine cycle in a graph
  bool cyclePresent = g.hasCycles();
  if (cyclePresent) {
      cout << "Detected cycle!\n";
  } else {
      cout << "Cycle not detected\n";  
  }
  
  //g.printVector(paths);
  
  return 0;
}

