#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Problem: Maximum XOR of Two Numbers in an Array
// Description: Given an integer array nums, return the maximum result of 
// nums[i] XOR nums[j], where 0 <= i < j < n.
// We can use a Trie to efficiently calculate the maximum XOR.
// Time Complexity: O(n * log(maxNum)), where n is the number of elements and 
// maxNum is the maximum number in the array.
// Space Complexity: O(n), for the Trie.

class TrieNode {
public:
    TrieNode* children[2];
    
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    
    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (node->children[1 - bit]) {
                maxXOR |= (1 << i);
                node = node->children[1 - bit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXOR;
    }
};

int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    for (int num : nums) {
        trie.insert(num);
    }
    
    int maxXOR = 0;
    for (int num : nums) {
        maxXOR = max(maxXOR, trie.findMaxXOR(num));
    }
    
    return maxXOR;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << findMaximumXOR(nums) << endl; // Output: 28 (5 XOR 25)
    return 0;
}
