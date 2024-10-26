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
    void Colour_check(ll v,bool visited[], ll color);
public:
    Graph(ll V);   
    void addEdge_U(ll v, ll w);
    void addEdge_D(ll v, ll w);
    bool isBipartite();
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

void solve()
{
    Graph g(9);
    g.addEdge_U(1,2);
    g.addEdge_U(2,3);
    g.addEdge_U(3,4);
    g.addEdge_U(4,5);
    g.addEdge_U(5,6);
    g.addEdge_U(6,7);
    g.addEdge_U(7,8);
    g.addEdge_U(8,1);
    if(g.isBipartite()){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
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