#include <iostream>
#include <stack>
using namespace std;

// Problem: Implement a Queue using Stacks
// Description: Implement a queue using two stacks. The queue should support 
// the standard operations: push, pop, peek, and empty.
// Time Complexity: O(1) for push and empty, O(n) for pop and peek in the worst case.
// Space Complexity: O(n) for the two stacks.

class MyQueue {
private:
    stack<int> inputStack, outputStack;

    void transferInputToOutput() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (outputStack.empty()) {
            transferInputToOutput();
        }
        int val = outputStack.top();
        outputStack.pop();
        return val;
    }

    int peek() {
        if (outputStack.empty()) {
            transferInputToOutput();
        }
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl; // Output: 1
    cout << q.pop() << endl;  // Output: 1
    cout << q.empty() << endl; // Output: false
    return 0;
}
