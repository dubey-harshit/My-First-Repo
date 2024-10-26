#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Problem: Task Scheduler
// Description: Given a characters array tasks, representing the tasks 
// that you need to do, and an integer n, representing the cooldown period 
// between the same tasks, return the least number of units of times that 
// you need to take to finish all tasks.
// Time Complexity: O(m + k log k), where m is the number of tasks and k is the number of unique tasks.
// Space Complexity: O(k), for the task count map.

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> taskCount;
    for (char task : tasks) {
        taskCount[task]++;
    }

    priority_queue<int> maxHeap;
    for (auto& [task, count] : taskCount) {
        maxHeap.push(count);
    }

    int cycles = 0;
    while (!maxHeap.empty()) {
        vector<int> temp;
        int len = min(n + 1, (int)maxHeap.size());
        
        for (int i = 0; i < len; i++) {
            temp.push_back(maxHeap.top());
            maxHeap.pop();
        }

        for (int count : temp) {
            if (--count > 0) {
                maxHeap.push(count);
            }
        }
        
        cycles += maxHeap.empty() ? temp.size() : n + 1; // if queue is empty, add temp size
    }
    return cycles;
}

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << leastInterval(tasks, n) << endl; // Output: 8
    return 0;
}
