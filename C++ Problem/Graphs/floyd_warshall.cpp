#define ll long long
#define pb push_back
#define vl vector<long long>
#define mll map<long long, long long>
#define pll pair<long long,long long>
#define mod 1000000007
#define fr(c,a,b) for(ll c=a;c<b;c++)
#include<bits/stdc++.h>
using namespace std;

// Floyd Warshall Algo is used to find the shortest paths btw all pairs in 
// both directed and undirected

// same logic as of BF algo - relaxing the edges

vector<vector<ll>> graph; 
vector<vector<ll>> dist;

void FW_Algo(ll u, ll v, ll n) {
    fr(c,0,n){
        fr(d,0,n){
            fr(e,0,n){
                dist[d][e]=min(dist[d][e],dist[d][c]+dist[c][e]);
            }
        }
    }

    cout<<dist[u][v]<<endl;
    
}

void solve() {
    ll n;cin>>n;
    ll u,v;cin>>u>>v;
    fr(c, 0, n) {
        vector<ll> g;
        fr(d, 0, n){
            ll x;cin>>x;
            g.pb(x);
        }
        graph.pb(g);
    }
    dist = graph;
    FW_Algo(u,v,n);
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