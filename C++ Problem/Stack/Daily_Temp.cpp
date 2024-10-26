#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Problem: Daily Temperatures
// Description: Given an array of integers temperatures represents the daily temperatures, 
// return an array such that answer[i] is the number of days you have to wait until a warmer 
// temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
// Time Complexity: O(n), where n is the number of days.
// Space Complexity: O(n), for the stack.

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> st; // To store indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int idx = st.top();
            st.pop();
            result[idx] = i - idx; // Calculate the wait time
        }
        st.push(i);
    }

    return result;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);
    for (int days : result) {
        cout << days << " "; // Output: 1 1 4 2 1 1 0 0
    }
    return 0;
}
