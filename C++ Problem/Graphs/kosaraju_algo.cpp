#define ll long long
#define pb push_back
#define mod 1000000007
#define fr(c,a,b) for(ll c=a;c<b;c++)
#include<bits/stdc++.h>
using namespace std;

/*  
    Kosaraju's Algorithm is used to find the strongly connected components in
    the graph.
    Strongly Connected graphs are like there is a path between every pair of 
    vertices. So SEC's are like them only but it is a subgraphs in which are
    all vertices are connected so this algo helps to find the no of these subgraphs.

    Algorithm:
    The main logic in this algo is that if a graph is strongly connected it will
    be strongly connected even after if we transpose the graph means u -> v so changing it to
    v -> u .
    So in order to execute this we first -->
        Use dfs to transverse over all the nodes and put the nodes in stack as it finishes 
        here finishes means like when dfs recursion starts when a nodes comes which have no other adjacent node
        so for that node dfs finishes and we push it to the stack. Then we have to again do the 
        dfs on the transpose graph in the same order as in the stack. And for printing and counting
        the SEC's we have to write other fns also. So that was a brief idea.

*/

class Graph
{
    ll V;
    list<ll> *adj;
    void DFSUtil(ll v, bool visited[]);
    void fillorder(int v, bool visited[], stack<int> &Stack);
public:
    Graph(ll V);   
    void addEdge_U(ll v, ll w);
    void addEdge_D(ll v, ll w);
    Graph get_transpose();
    void Main(int v);
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
    cout<<v<<" ";
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}   

Graph Graph::get_transpose(){
    Graph g(V);

    for(int v=0;v<V;v++){
        list<int>::iterator i;
        for(auto i:adj[v]){
            g.adj[*i].push_back(v);
        }
    }
    return g;

}

void Graph::fillorder(int v, bool visited[], stack<int> &Stack){
    visited[v] = true;

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            fillorder(*i, visited,Stack);
    
    Stack.push(v);
}

void Graph::Main(int v){
    stack<int> Stack;
    bool *visited = new bool[V];
    for(int c=0;c<V;c++){
        visited[c]=false;
    }
    for(int c=0;c<V;c++){
        if(visited[c]==false){
            fillorder(c,visited,Stack);
        }
    }

    Graph g2 = get_transpose();

    for(int c=0;c<V;c++){
        visited[c]=false;
    }

    while(Stack.empty()==false){
        int s = Stack.top();
        Stack.pop();

        if(!visited[s]){
            g2.DFSUtil(s,visited);
            cout<<endl;
        }
    }

}


void solve()
{
    Graph g(5);
    g.addEdge_D(1,0);
    g.addEdge_D(0,2);
    g.addEdge_D(2,1);
    g.addEdge_D(0,3);
    g.addEdge_D(3,4);

    g.Main(0);
    
    
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

/*

    Time Complexity:
    The above algorithm calls DFS, fins reverse of the graph and again calls DFS. 
    DFS takes O(V+E) for a graph represented using adjacency list. 
    Reversing a graph also takes O(V+E) time. For reversing the graph, we simply traverse all adjacency lists.

    Auxiliary Space: O(V+E) 

    Applications:

    SCC algorithms can be used as the first step in many graph algorithms that work only on a strongly connected graph. 
    In social networks, a group of people are generally strongly connected (For example, students of a class or any other 
    common place). Many people in these groups generally like some common pages or play common games. 
    The SCC algorithms can be used to find such groups and suggest the commonly liked pages or games to the people in the 
    group who have not yet liked commonly liked a page or played a game.

*/