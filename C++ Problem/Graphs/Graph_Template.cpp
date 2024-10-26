#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(c,a,b) for(ll c=a;c<b;c++)
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    ll V;
    list<ll> *adj;
    void DFSUtil(ll v, bool visited[]);
    bool isCyclicUtil_U(ll v, bool visited[], ll parent);
    bool isCyclicUtil_D(ll v, bool visited[], bool *recStack);
    ll C_C(ll v, bool visited[]);
    void Colour_check(ll v,bool visited[], ll color);
public:
    Graph(ll V);   
    void addEdge_U(ll v, ll w);
    void addEdge_D(ll v, ll w);
    void DFS(ll v);
    void BFS(ll v);
    bool isCyclic_U();
    bool isCyclic_D();
    vector<ll> Conected_Comp();
    bool isBipartite();
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

void Graph::DFSUtil(ll v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::DFS(ll v)
{

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(v, visited);
    cout<<endl;
}

void Graph::BFS(ll v){
    bool visited[V];

    fr(i,0,V+1)
        visited[i] = false;

    queue<int> q;
    auto s = v;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto i=adj[node].begin();i!=adj[node].end(); i++) {
            if (visited[*i] == false) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }cout<<endl;
}


bool Graph::isCyclicUtil_U(ll v, bool visited[], ll parent)
{
    visited[v] = true;
    list<ll>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            if (isCyclicUtil_U(*i, visited, v))
                return true;
        }
        else if (*i != parent)
            return true;
    }
    return false;
}

bool Graph::isCyclic_U()
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int u = 0; u < V; u++) {
        if (!visited[u])
            if (isCyclicUtil_U(u, visited, -1))
                return true;
    }
    return false;
}

bool Graph::isCyclicUtil_D(ll v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        list<ll>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil_D(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }

    }
    recStack[v] = false; 
    return false;
}

bool Graph::isCyclic_D()
{

    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i = 0; i < V; i++)
        if ( !visited[i] && isCyclicUtil_D(i, visited, recStack))
            return true;

    return false;
}

ll Graph::C_C(ll v, bool visited[]){
    visited[v]=true;
    ll ans=1;
    list<ll>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i]){
            ans+=C_C(*i,visited);
        }
    }
    return ans;
}

vector<ll> Graph::Conected_Comp()
{
    vector<ll> v;
    bool *visited = new bool[V];
    fr(c,0,V){
        visited[c]=false;
    }
    fr(c,1,V){
        if(!visited[c]){
            v.pb(C_C(c,visited));
        }
    }
    return v;
}

vector<ll> color;
bool bipart;
void Graph::Colour_check(ll v,bool visited[], ll col)
{
    if(color[v]!=-1 && color[v]!=col){
        bipart = false;
        return;
    }color[v]=col;
    if(visited[v]){
        return;
    }
    visited[v] = true;
    list<ll>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        Colour_check(*i, visited, (col^1));
    }
    
}

bool Graph::isBipartite()
{
    bipart = true;
    bool *visited = new bool[V];
    color = vector<ll> (V,-1);
    fr(c,1,V){
        visited[c]=false;
    }
    fr(c,1,V){
        if(!visited[c]){
            Colour_check(c, visited, 0);
        }
    }
    return bipart;
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