#include <iostream>
#include <vector>
using namespace std;

// Problem: Coin Game
// Description: Two players take coins from either end of a line of coins, 
// trying to maximize their total value. Each player has perfect knowledge of the game.
// Time Complexity: O(n^2), due to filling the DP table.
// Space Complexity: O(n^2), for the DP table.

int coinGame(vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = coins[i]; // If only one coin, take it
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            dp[i][j] = max(coins[i] - dp[i + 1][j], coins[j] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}

int main() {
    int n; // Number of coins
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i]; // Input coin values
    }
    cout << coinGame(coins) << endl; // Output maximum value
    return 0;
}
