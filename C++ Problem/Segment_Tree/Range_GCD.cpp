#include <bits/stdc++.h>
using namespace std;

/*
    Problem Description:
    You are given an array of integers and need to perform two types of operations:
    1. **Range GCD Query**: Find the greatest common divisor (GCD) of the elements within a specified range.
    2. **Update Operation**: Update the value of a specific element in the array.

    You should implement a segment tree to efficiently perform these operations.

    Time Complexity:
    - **Construction of Segment Tree**: O(n)
    - **Range GCD Query**: O(log n)
    - **Update Operation**: O(log n)
*/

// Function to find gcd of 2 numbers
int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

// A recursive function that constructs Segment Tree for array[ss..se]
int constructST(int arr[], int st[], int ss, int se, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = getMid(ss, se);
    st[si] = gcd(constructST(arr, st, ss, mid, si * 2 + 1),
                 constructST(arr, st, mid + 1, se, si * 2 + 2));
    return st[si];
}

// Function to construct segment tree from given array
int *constructSegmentTree(int arr[], int n) {
    int height = (int)(ceil(log2(n)));
    int size = 2 * (int)pow(2, height) - 1;
    int *st = new int[size];
    constructST(arr, st, 0, n - 1, 0);
    return st;
}

class Solution {
public:
    int findRangeUtil(int qs, int qe, int ss, int se, int st[], int si) {
        if (qs <= ss && qe >= se) {
            return st[si];
        }
        if (qs > se || qe < ss) {
            return 0;
        }
        
        int mid = (ss + se) / 2;
        return gcd(findRangeUtil(qs, qe, ss, mid, st, si * 2 + 1),  
                   findRangeUtil(qs, qe, mid + 1, se, st, 2 * si + 2)); 
    }
    
    // Function to find gcd of given range
    int findRangeGcd(int l, int r, int st[], int n) {
        return findRangeUtil(l, r, 0, n - 1, st, 0);
    }
    
    void updateValueUtil(int i, int new_val, int ss, int se, int st[], int si) {
        if (i < ss || i > se)
            return;
        if (ss == se) {
            st[si] = new_val;
            return;
        }
        
        int mid = getMid(ss, se);
        updateValueUtil(i, new_val, ss, mid, st, si * 2 + 1);
        updateValueUtil(i, new_val, mid + 1, se, st, si * 2 + 2);
        
        st[si] = gcd(st[si * 2 + 1], st[si * 2 + 2]);
    }
    
    // Function to update a value in input array and segment tree
    void updateValue(int index, int new_val, int *arr, int st[], int n) {
        if (index < 0 || index > n - 1) {
            return;
        }
        arr[index] = new_val;
        updateValueUtil(index, new_val, 0, n - 1, st, 0);
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Build segment tree from given array
        int *st = constructSegmentTree(a, n);
        int type;
        while (q--) {
            cin >> type;

            if (type == 0) {
                int l, r;
                cin >> l >> r;
                Solution obj;
                cout << obj.findRangeGcd(l, r, st, n) << endl;
            } else {
                int ind, val;
                cin >> ind >> val;
                Solution obj;
                obj.updateValue(ind, val, a, st, n);
            }
        }
    }

    return 0;
}
