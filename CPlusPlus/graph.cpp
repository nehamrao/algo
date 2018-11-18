#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

class Graph {
    int num_vertices;
    vector<vector<int> *> adj;
public:
    Graph(int V);// Graph with V vertices
    void addEdge(int from, int to);// Construct adj list
    void BFS(int start);// Start node    
    void DFS(int start);// Start node    
    void TopologicalSort();
private:    
    void DFSutil(int curr, bool *visited);// Start node    
    void TopoSortutil(int curr, bool *visited, stack<int>& stk);// Start node    
};

Graph::Graph(int V)
{
    num_vertices = V;
    for (int i = 0; i < V; i++) {
	adj.push_back(new vector<int>());
    }
}

void Graph::addEdge(int from, int to)
{
    adj[from]->push_back(to);
}

void Graph::BFS(int s)
{
    // Visited array stores all visited nodes, avoid cycles
    bool visited[num_vertices];
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = false;
    }

    // Use a queue to store the processed nodes
    queue<int> q;
    q.push(s);

    // Iterate to get adj vertices of any given vertex
    while (!q.empty()) {
        int curr = q.front(); // Get front of queue
        visited[curr] = true;
        q.pop();
        cout << curr << " ";   
      
        // Add all adj of curr to queue
        std::vector<int>::iterator it;
        for (it = adj[curr]->begin(); it != adj[curr]->end(); it++)
	{
            if (!visited[*it])
            {
                 q.push(*it);
            }
        }
    }
}

void Graph::DFSutil(int curr, bool *visited)
{
     // Mark current node as visited
     visited[curr] = true;
     cout << curr << " ";

    // Recursively call DFSutil over all non-visited adj of curr
    std::vector<int>::iterator it;
    for (it = adj[curr]->begin(); it != adj[curr]->end(); it++)
	if (!visited[*it])
	    DFSutil(*it, visited);
}

void Graph::DFS(int s)
{
    // Initialize the visited ary
    bool *visited = new bool[num_vertices];
    for (int i = 0 ; i < num_vertices; i++)
	visited[i] = false;

    DFSutil(s, visited); 
}

void Graph::TopoSortutil(int curr, bool *visited, stack<int>& stk)
{
    visited[curr] = true;

    vector<int>::iterator it;
    for (it = adj[curr]->begin(); it != adj[curr]->end(); it++) {
        if (!visited[*it])
            TopoSortutil(*it, visited, stk);
    }

    stk.push(curr);
}

void Graph::TopologicalSort()
{
    // Declare stack to store temporary nodes
    // Add to stack only after all adj have been
    // recursively traveresed/hit leaf node
    std::stack<int> stk;
    
    bool *visited = new bool[num_vertices];
    for (int i = 0; i < num_vertices; i++) 
	visited[i] = false;
    
    for (int i = 0; i < num_vertices; i++) {
        if (!visited[i])
            TopoSortutil(i, visited, stk);
    }

    // Once above is done, pop stack and print
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
}

int main ()
{
    Graph gph(4);
    gph.addEdge(0,1);
    gph.addEdge(0,2);
    gph.addEdge(1,2);
    gph.addEdge(2,0);
    gph.addEdge(2,3);
    gph.addEdge(3,3);
    gph.BFS(2); cout << "\n";
    gph.DFS(2); cout << "\n";

    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given graph \n";
    g.TopologicalSort(); cout << "\n";

}
