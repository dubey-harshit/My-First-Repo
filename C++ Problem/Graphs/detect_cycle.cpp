/*
Time Complexity: O(m * α(V)), where m is the number of edges and V is the number of vertices.
Space Complexity: O(V + m), where V is the number of vertices and m is the number of edges.

Given an undirected graph with V vertices labelled from 0 to V-1 and E 
edges, check whether it contains any cycle or not. Graph is in the form 
of adjacency list where adj[i] contains all the nodes ith node is having
edge with.
*/

/*
 * Cycle Detection in an Undirected Graph
 *
 * Example:
 * Input:
 * 5 6
 * 0 1
 * 1 2
 * 2 0
 * 1 3
 * 3 4
 * 4 3
 *
 * Output:
 * Yes (there is a cycle)
 *
 * Explanation:
 * The edges form a cycle (0 -> 1 -> 2 -> 0) and (3 -> 4 -> 3).
 */

#define ll long long
#define pb push_back
#define vl vector<long long>
#define mll map<long long, long long>
#define pll pair<long long, long long>
#define mod 1000000007
#define fr(c,a,b) for(ll c = a; c < b; c++)

#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU) class for cycle detection
class DSU {
    ll V;              // Number of vertices
    ll *size;         // Array to store size of each set
    ll *parent;       // Array to store parent of each vertex

public:
    DSU(ll V);        // Constructor
    ll find_set(ll v); // Find the root of the set containing 'v'
    void union_sets(ll a, ll b); // Union of two sets
};

// Constructor to initialize the DSU
DSU::DSU(ll V) {
    this->V = V;
    size = new ll[V];
    parent = new ll[V];
    fr(c, 0, V) {
        size[c] = 1;        // Initialize size of each set as 1
        parent[c] = c;     // Each vertex is its own parent (initially)
    }
}

// Find the root of the set containing 'v' with path compression
ll DSU::find_set(ll v) {
    if (v == parent[v]) {
        return v; // If 'v' is the root, return it
    }
    return parent[v] = find_set(parent[v]); // Path compression
}

// Union of two sets 'a' and 'b'
void DSU::union_sets(ll a, ll b) {
    a = find_set(a); // Find the root of set containing 'a'
    b = find_set(b); // Find the root of set containing 'b'
    
    if (a != b) { // Only union if they are in different sets
        if (size[a] < size[b]) {
            swap(a, b); // Ensure 'a' is the larger set
        }
        parent[b] = a; // Make 'a' the parent of 'b'
        size[a] += size[b]; // Update the size of the new root
    }
}

// Function to solve the cycle detection problem
void solve() {
    ll n, m; // n = number of vertices, m = number of edges
    cin >> n >> m; // Read number of vertices and edges
    vector<vector<ll>> edges; // Store edges in a vector
    fr(c, 0, m) {
        ll u, v; // Read each edge
        cin >> u >> v;
        edges.pb({u, v}); // Add edge to the vector
    }

    DSU d(n); // Create a DSU instance for 'n' vertices
    bool cycle = false; // Flag to check for cycles

    // Process each edge
    for (auto i : edges) {
        ll x = i[0]; // First vertex of the edge
        ll y = i[1]; // Second vertex of the edge
        if (d.find_set(x) == d.find_set(y)) { // Check if x and y are in the same set
            cycle = true; // A cycle is detected
        } else {
            d.union_sets(x, y); // Union the sets of x and y
        }
    }
    
    if (cycle) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl; 
    }
}

// Main function to execute the program
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    int t = 1; 
    while (t--) {
        solve(); 
    }
    return 0; 
}
