#include <iostream>
using namespace std;

// Problem: Chocolate Game
// Description: Two players take turns breaking a chocolate bar of size n x m.
// The player who cannot make a move loses. The first player wins if both dimensions are odd.
// Time Complexity: O(1), as we only check the dimensions.
// Space Complexity: O(1), no additional space used.

string chocolateGame(int n, int m) {
    return (n % 2 == 1 && m % 2 == 1) ? "First" : "Second"; // First player wins if both dimensions are odd
}

int main() {
    int n, m; // Dimensions of the chocolate
    cin >> n >> m;
    cout << chocolateGame(n, m) << endl; // Output winner
    return 0;
}
