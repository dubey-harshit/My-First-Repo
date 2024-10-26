#include <bits/stdc++.h>
using namespace std;

/*
 * Segment Trees are a powerful data structure used for efficiently 
 * performing range queries and updates on an array. They allow us 
 * to quickly compute operations like sum, minimum, and maximum over 
 * a range of elements, as well as to update elements in logarithmic time. 
 * This makes them ideal for scenarios where the array is frequently modified 
 * and where we need to frequently query information about ranges.

Time Complexity:
Building the Segment Tree: O(n)
Querying a range: O(logn)
Updating an element: O(logn)
Space Complexity:O(n) for the segment tree storage.

 */

int getMid(int s, int e) {
    return s + (e - s) / 2; // Calculate the middle index
}

// Utility function to get the sum in a given range
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) {
    // If the segment of this node is completely within the query range
    if (qs <= ss && qe >= se)
        return st[si]; // Return the stored sum

    // If the segment of this node is outside the query range
    if (se < qs || ss > qe)
        return 0; // Return 0

    // If the segment is partially inside the query range
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) + // Left child
           getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2); // Right child
}

// Utility function to update a value in the segment tree
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) {
    // If the index to be updated is out of range
    if (i < ss || i > se)
        return;

    // Update the current node
    st[si] = st[si] + diff;

    // If the current segment has more than one element
    if (se != ss) {
        int mid = getMid(ss, se);
        // Recursively update the left and right children
        updateValueUtil(st, ss, mid, i, diff, 2 * si + 1);
        updateValueUtil(st, mid + 1, se, i, diff, 2 * si + 2);
    }
}

// Function to update the value at a specific index
void updateValue(int arr[], int *st, int n, int i, int new_val) {
    if (i < 0 || i >= n) {
        cout << "Invalid Input";
        return;
    }
    int diff = new_val - arr[i]; // Calculate difference
    arr[i] = new_val; // Update the original array
    updateValueUtil(st, 0, n - 1, i, diff, 0); // Update the segment tree
}

// Function to get the sum in a given range
int getSum(int *st, int n, int qs, int qe) {
    if (qs < 0 || qe >= n || qs > qe) {
        cout << "Invalid Input";
        return -1;
    }
    return getSumUtil(st, 0, n - 1, qs, qe, 0); // Call the utility function
}

// Utility function to construct the segment tree
int constructSTUtil(int arr[], int ss, int se, int *st, int si) {
    if (ss == se) { // Leaf node
        st[si] = arr[ss]; // Store value in segment tree
        return arr[ss];
    }
    int mid = getMid(ss, se);
    // Recursively construct the segment tree
    st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
             constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
    return st[si];
}

// Function to create and construct the segment tree
int *constructST(int arr[], int n) {
    int x = (int)(ceil(log2(n))); // Height of segment tree
    int max_size = 2 * (int)pow(2, x) - 1; // Maximum size of segment tree
    int *st = new int[max_size]; // Allocate memory for segment tree
    constructSTUtil(arr, 0, n - 1, st, 0); // Build the tree
    return st;
}

// Main function to demonstrate the segment tree functionality
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11}; // Sample array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array
    int *st = constructST(arr, n); // Construct the segment tree

    // Get sum of values in range [1, 3]
    cout << "Sum of values in given range = " << getSum(st, n, 1, 3) << endl;

    // Update value at index 1 to 10
    updateValue(arr, st, n, 1, 10);
    
    // Get updated sum of values in range [1, 3]
    cout << "Updated sum of values in given range = " << getSum(st, n, 1, 3) << endl;

    delete[] st; // Free allocated memory for the segment tree
    return 0;
}
