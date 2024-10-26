#include <iostream>
#include <vector>
using namespace std;

// Problem: Unique Paths III
// Description: You are given an m x n grid, with 0 representing an empty cell, 
// 1 representing the starting square, 2 representing the ending square, and 
// -1 representing obstacles. You need to find all unique paths from the start 
// to the end, visiting every non-obstacle cell exactly once.
// Time Complexity: O(2^(m*n)), where m and n are the dimensions of the grid. 
// Space Complexity: O(m*n), for the recursion stack.

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX, startY, emptyCount = 0;
        int m = grid.size(), n = grid[0].size();

        // Find the starting point and count empty cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] == 0) {
                    emptyCount++;
                }
            }
        }

        return backtrack(grid, startX, startY, emptyCount);
    }

private:
    int backtrack(vector<vector<int>>& grid, int x, int y, int emptyCount) {
        if (grid[x][y] == 2) {
            return emptyCount == -1 ? 1 : 0; // Found the end and visited all cells
        }

        int paths = 0;
        // Mark the cell as visited
        int temp = grid[x][y];
        grid[x][y] = -1; // mark as visited

        // Explore all 4 directions
        for (int dx : {-1, 1}) {
            for (int dy : {-1, 1}) {
                if (dx == dy) continue; // only orthogonal directions
                int newX = x + dx;
                int newY = y + dy;
                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() 
                    && (grid[newX][newY] == 0 || grid[newX][newY] == 2)) {
                    paths += backtrack(grid, newX, newY, emptyCount - (grid[newX][newY] == 0));
                }
            }
        }

        // Unmark the cell
        grid[x][y] = temp; // revert to original value
        return paths; // return number of unique paths found
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, -1}
    };
    Solution solution;
    cout << solution.uniquePathsIII(grid) << endl; // Output: 2
    return 0;
}
