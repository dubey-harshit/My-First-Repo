#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: Subsets II
// Description: Given an integer array nums that may contain duplicates, 
// return all possible subsets (the power set). The solution set must not 
// contain duplicate subsets. The order of the output subsets should not 
// matter.
// Time Complexity: O(2^n), where n is the number of elements.
// Space Complexity: O(n), for the recursion stack.

void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& subset, 
               int start) {
    res.push_back(subset);
    
    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i - 1]) continue; // Skip duplicates
        subset.push_back(nums[i]);
        backtrack(res, nums, subset, i + 1);
        subset.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> subset;
    sort(nums.begin(), nums.end()); // Sort to handle duplicates
    backtrack(res, nums, subset, 0);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = subsetsWithDup(nums);
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}
