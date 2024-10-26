#include <iostream>
#include <vector>
using namespace std;

// Problem: Grundy Numbers
// Description: In a game where players can take stones from a pile, 
// we need to find the Grundy number for each position to determine 
// winning strategies. The Grundy number for a position is calculated 
// using the minimum excludant (mex) of the Grundy numbers of all 
// positions reachable from it.
// Time Complexity: O(n * k), where n is the number of piles and k is the maximum number of stones a player can take.
// Space Complexity: O(n), for storing Grundy numbers.

int findGrundy(int n, const vector<int>& moves) {
    vector<int> grundy(n + 1, 0); // Grundy numbers array
    for (int i = 1; i <= n; i++) {
        vector<bool> reachable(n + 1, false); // Track reachable Grundy numbers
        for (int move : moves) {
            if (i - move >= 0) {
                reachable[grundy[i - move]] = true; // Mark reachable
            }
        }
        // Find minimum excluded value (mex)
        for (int j = 0; j <= n; j++) {
            if (!reachable[j]) {
                grundy[i] = j; // Assign the mex value
                break;
            }
        }
    }
    return grundy[n];
}

int main() {
    int n; // Number of stones
    cin >> n;
    vector<int> moves = {1, 2, 3}; // Possible moves
    cout << findGrundy(n, moves) << endl; // Output the Grundy number
    return 0;
}
