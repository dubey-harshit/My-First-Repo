/*
Given an undirected graph with V vertices labelled from 0 to V-1 and E 
edges, check whether it contains any cycle or not. Graph is in the form 
of adjacency list where adj[i] contains all the nodes ith node is having
edge with.
*/

#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    bool isCyclic(int V, vector<int> adj[]);

private:
    bool dfs(int node, int parent, vector<int> &visited, vector<int> adj[]);
};

bool Graph::dfs(int node, int parent, vector<int> &visited, vector<int> adj[]) {
    visited[node] = 1; 

    for (int adjacent : adj[node]) {
        if (!visited[adjacent]) {
            if (dfs(adjacent, node, visited, adj)) {
                return true; 
            }
        }
         else if (adjacent != parent) {
            return true;
        }
    }

    return false;
}

bool Graph::isCyclic(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) { 
            if (dfs(i, -1, visited, adj)) {
                return true; 
            }
        }
    }

    return false; 
}

int main() {
    int V = 5;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);

    Graph g;
    if (g.isCyclic(V, adj)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}
