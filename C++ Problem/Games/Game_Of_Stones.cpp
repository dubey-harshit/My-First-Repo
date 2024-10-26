#include <iostream>
using namespace std;

// Problem: Game of Stones
// Description: Two players take turns removing 1, 2, or 3 stones from a pile. 
// The player who takes the last stone wins. The first player wins if the number of stones is not a multiple of 4.
// Time Complexity: O(1), as we perform a single modulus operation.
// Space Complexity: O(1), no additional space used.

bool canWin(int n) {
    return n % 4 != 0; // Player can win if the number of stones is not a multiple of 4
}

int main() {
    int n; // Number of stones
    cin >> n;
    cout << (canWin(n) ? "First" : "Second") << endl; // Output winner
    return 0;
}
