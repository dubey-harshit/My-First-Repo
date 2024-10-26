#include <iostream>
#include <vector>
using namespace std;

// Problem: K Game
// Description: In a game where two players alternate taking stones from a 
// pile, with each player allowed to take 1 to K stones per turn. The player 
// unable to make a move loses. Determine if the first player can win given the 
// total number of stones and K.
// Time Complexity: O(n*K), where n is the total number of stones and K is the max stones that can be taken.
// Space Complexity: O(n), for storing the winning states.

bool canFirstPlayerWin(int n, int k) {
    vector<bool> dp(n + 1, false); // Winning positions
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0 && !dp[i - j]) {
                dp[i] = true; // If I can force the opponent to lose
                break;
            }
        }
    }
    return dp[n]; // Return the result for n stones
}

int main() {
    int n, k; // Total number of stones and max stones that can be taken
    cin >> n >> k;
    cout << (canFirstPlayerWin(n, k) ? "First" : "Second") << endl; // Output winner
    return 0;
}
