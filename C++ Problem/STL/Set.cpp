#include <iostream>
#include <set>
using namespace std;
 


int main()
{
 
    set<int, greater<int> > s1; // If we want to reverse the order of elements in the set which we actually get by defalut
    unordered_set<int> s2;   // This is also a type of set but its element are not sorted some other diff also
    s1.insert(10);
    s1.insert(5);
    s1.insert(12);
    s1.insert(4);
 
    for (auto i : s1) {
        cout << i << ' ';
    }
    return 0;
}

// Some Basic Functions Associated with Set

// 1. begin() – Returns an iterator to the first element in the set.
// 2. end() – Returns an iterator to the theoretical element that follows the last element in the set.
// 3. size() – Returns the number of elements in the set.
// 4. max_size() – Returns the maximum number of elements that the set can hold.
// 5. empty() – Returns whether the set is empty.

// The time complexities for doing various operations on sets are:

// Insertion of Elements – O(log N)
// Deletion of Elements – O(log N)