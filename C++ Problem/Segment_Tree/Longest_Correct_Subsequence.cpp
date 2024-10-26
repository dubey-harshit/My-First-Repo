#include <bits/stdc++.h>
using namespace std;

/*
    Problem Description:
    You are given a string consisting of parentheses. Your task is to find the length of the longest valid parentheses subsequence in a given range using a segment tree.

    The segment tree nodes contain:
    - `pairs`: The number of valid parentheses pairs.
    - `open`: The number of unmatched opening parentheses.
    - `closed`: The number of unmatched closing parentheses.

    Time Complexity:
    - **Construction of Segment Tree**: O(n)
    - **Query for Longest Valid Parentheses**: O(log n)
*/

struct Node {
    int pairs;
    int open;   // unused
    int closed; // unused

    Node() { pairs = open = closed = 0; }
};

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

Node merge(Node leftChild, Node rightChild) {
    Node parentNode;
    int minMatched = min(leftChild.open, rightChild.closed);
    parentNode.pairs = leftChild.pairs + rightChild.pairs + minMatched;
    parentNode.open = leftChild.open + rightChild.open - minMatched;
    parentNode.closed = leftChild.closed + rightChild.closed - minMatched;
    return parentNode;
}

void constructSTUtil(string str, int ss, int se, Node* st, int si) {
    if (ss == se) {
        st[si].pairs = 0;
        if (str[ss] == '(')
            st[si].open = 1;
        else
            st[si].closed = 1;

        return;
    }

    int mid = getMid(ss, se);
    constructSTUtil(str, ss, mid, st, si * 2 + 1);
    constructSTUtil(str, mid + 1, se, st, si * 2 + 2);

    st[si] = merge(st[si * 2 + 1], st[si * 2 + 2]);
}

Node* constructST(string str, int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    Node* st = new Node[max_size];
    constructSTUtil(str, 0, n - 1, st, 0);
    return st;
}

// User function template for C++
class Solution
{
    public:
    // Function to returns the maximum length of correct bracket subsequence
    // between starting and ending indexes.
    int getLongestSequence(Node* st, string str, int qs, int qe, int n) 
    {
        // Implement the logic to retrieve the length of the longest valid parentheses subsequence
        Node result = st[qs]; // Retrieve the initial segment tree node
        return result.pairs * 2; // Return the length of valid pairs
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int query;
        string str;

        cin >> str >> query;
        int n = str.length();

        Node* st = constructST(str, n);

        int startIndex, endIndex;
        while (query--) {
            cin >> startIndex >> endIndex;
            Solution obj;
            cout << obj.getLongestSequence(st, str, startIndex, endIndex, n)
                 << endl;
        }
    }

    return 0;
}
