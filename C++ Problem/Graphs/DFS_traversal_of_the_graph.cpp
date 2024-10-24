#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int src, vector<bool>& vis, vector<int> adj[], vector<int>& ans) {
        vis[src] = true;
        ans.push_back(src);
        
        for (auto nbr : adj[src]) {
            if (!vis[nbr]) {
                dfs(nbr, vis, adj, ans);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<int> ans;
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, ans);
            }
        }
        
        return ans;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter the edges (u v) for the graph:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution solution;
    vector<int> dfsResult = solution.dfsOfGraph(V, adj);

    cout << "DFS traversal of the graph: ";
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
