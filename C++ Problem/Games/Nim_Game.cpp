#include <iostream>
#include <vector>
using namespace std;

// Problem: Nim Game
// Description: Two players take turns removing objects from distinct piles.
// The player who takes the last object wins. The winner can be determined using the nim-sum (XOR of pile sizes).
// Time Complexity: O(n), where n is the number of piles.
// Space Complexity: O(1), no additional space used.

string nimGame(vector<int>& piles) {
    int nimSum = 0;
    for (int pile : piles) {
        nimSum ^= pile; // Calculate the nim-sum
    }
    return (nimSum != 0) ? "First" : "Second"; // First player wins if nim-sum is non-zero
}

int main() {
    int n; // Number of piles
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i]; // Input pile sizes
    }
    cout << nimGame(piles) << endl; // Output winner
    return 0;
}
