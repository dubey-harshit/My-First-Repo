#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Problem: Sliding Window Maximum
// Description: Given an integer array nums and an integer k, return the 
// maximum sliding window of size k.
// Time Complexity: O(n), where n is the number of elements in nums.
// Space Complexity: O(k), for the deque.

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq; // to store indices of elements

    for (int i = 0; i < nums.size(); ++i) {
        // Remove indices that are out of the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // Remove elements from the back that are less than the current element
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        // Add current index
        dq.push_back(i);
        
        // The first element in deque is the largest element in the current window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);
    for (int val : result) {
        cout << val << " "; // Output: 3 3 5 5 6 7
    }
    return 0;
}
