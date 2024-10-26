#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(c,a,b) for(ll c=a;c<b;c++)
#include<bits/stdc++.h>
using namespace std;

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices 
// such that for every directed edge uv, vertex u comes before v in the ordering. 
// Topological Sorting for a graph is not possible if the graph is not a DAG.

class Graph
{
    ll V;
    list<ll> *adj;

public:
    Graph(ll V);   
    void addEdge_U(ll v, ll w);
    void addEdge_D(ll v, ll w);
    void T_S();
};

Graph::Graph(ll V)
{
    this->V = V;
    adj = new list<ll>[V];
}

void Graph::addEdge_U(ll v, ll w)
{
    adj[v].pb(w); 
    adj[w].pb(v);
}
void Graph::addEdge_D(ll v, ll w)
{
    adj[v].pb(w); 
}

// Implementing Kahn's Alogorithm using BFS for topological sort
// In this we first print the nodes with indegree 0 and then 1 and so on


void Graph::T_S(){
    vector<ll> in_degree(V,0);
    for (int u = 0; u < V; u++) {
        for (auto i=adj[u].begin();i!=adj[u].end(); i++) {
            in_degree[*i]++;
        }
    }

    queue<ll> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);

    // Initialize count of visited vertices
    int cnt = 0;

    // Create a vector to store result (A topological ordering of the vertices)
    vector<ll> top_order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        top_order.push_back(node);
        for (auto i=adj[node].begin();i!=adj[node].end(); i++) {
            if (--in_degree[*i] == 0)
                q.push(*i);
        }
        cnt++;

    }
    if (cnt != V) {
        cout << "There exists a cycle in the graph\n";
        return ;
    }

    // Print topological order
    for (int i = 0; i < top_order.size(); i++)
        cout << top_order[i] << " ";
    cout << endl;
}

void solve()
{
    Graph g(9);
    g.addEdge_D(1,2);
    g.addEdge_D(2,3);
    g.addEdge_D(2,4);
    g.addEdge_D(4,5);
    g.addEdge_D(3,6);
    g.addEdge_D(1,7);
    g.addEdge_D(7,8);
    g.T_S();
    
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--)
    {
        solve();
    }
}