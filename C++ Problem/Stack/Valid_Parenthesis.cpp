#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Problem: Valid Parentheses
// Description: Given a string s containing just the characters '(', ')', '{', '}', 
// '[' and ']', determine if the input string is valid. An input string is valid if 
// the brackets are closed in the correct order.
// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(n), for the stack.

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s = "{[()]}";
    cout << isValid(s) << endl; // Output: 1 (true)
    return 0;
}
