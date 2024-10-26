#define ll long long
#define pb push_back
#define vl vector<long long>
#define mll map<long long, long long>
#define pll pair<long long,long long>
#define mod 1000000007
#define fr(c,a,b) for(ll c=a;c<b;c++)
#include<bits/stdc++.h>
using namespace std;

// Bellman Ford Algo is used to find the single source shortest paths in 
// both directed and undirected

// But it has some advantages over Dijkstra algo that we can have negative
// edges and can also detect negative cycles as it only takes n-1 
// passes to find the shortest path if the values still changes after that
// then negative cycles exist

vector<vector<ll>> edges; 
vector<ll> dist;

void BF_Algo(ll source, ll n) {
    fr(c, 0, n) {
        dist.pb(INT_MAX);
    }
    dist[source] = 0;
    ll cost = 0;

    fr(c,0,n-1){
        for (auto it : edges) {
            ll u = it[1];
            ll v = it[2];
            ll w = it[0];
            dist[v]=min(dist[v],dist[u]+w);
        }
    }

    fr(c,0,n){
        if(dist[c]!=INT_MAX){
            cout<<dist[c]<<" ";
        }else{
            cout<<-1<<endl;
        }
    }
    
}

void solve() {
    ll n, m;
    cin >> n >> m;
    fr(c, 0, m) {
        ll w, u, v;
        cin >> w >> u >> v;
        edges.pb({w,u,v});
    }
    BF_Algo(0, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

/*
    Negative weights are found in various applications of graphs. 
    For example, instead of paying the cost for a path, we may get some advantage if we follow the path.

    Bellman-Ford works better (better than Dijkstra's) for distributed systems. Unlike Dijksra's where we need 
    to find the minimum value of all vertices, in Bellman-Ford, edges are considered one by one.
*/