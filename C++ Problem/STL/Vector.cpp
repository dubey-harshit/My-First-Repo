//Topic : std::vector

//Notes:
//1. std::vecotr is a sequence container and also known as Dynamic array .
//2. It is basically made of linked list whose main func is that it is dynamic and array - its access time is O(1) .So vector is a combination of both.
//3.Its size can grow and shrink dynamically , and no need to provide size at compile time.

//Element Access
// at(), [], front(), back(), data()

//Modifiers
//insert(), emplace(), push_back(), empace_back(), pop_back(), resize(), swap(), erase(), clear()

#include <iostrem>
#include <vector>
using namespace std;

int main(){
    vector<int> array (1,2);
    vector<int> array = (1,2);
}

//basically when we push_back element in vector it creates  an array then if there is no space in array to take element
// it creates another array of 2* size and copy the elements from previous array to reduce this much operations we can use 
//v.reserve(100);  this will initially make and array of size 100 

