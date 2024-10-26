#include <iostream>
#include <map>

// Some basic functions associated with Map: 

// 1. begin() – Returns an iterator to the first element in the map.
// 2. end() – Returns an iterator to the theoretical element that follows the last element in the map.
// 3. size() – Returns the number of elements in the map.
// 4. max_size() – Returns the maximum number of elements that the map can hold.
// 5. empty() – Returns whether the map is empty.
// 6. pair insert(keyvalue, mapvalue) – Adds a new element to the map.
// 7. erase(iterator position) – Removes the element at the position pointed by the iterator.
// 8. erase(const g)– Removes the key-value ‘g’ from the map.
// 9. clear() – Removes all the elements from the map.

int main()
{
// Create a map of strings to integers
std::map<std::string, int> map;

// Insert some values into the map
map["one"] = 1;
map["two"] = 2;
map["three"] = 3;

// Get an iterator pointing to the first element in the map
std::map<std::string, int>::iterator it = map.begin();

// Iterate through the map and print the elements
while (it != map.end())
{
	std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	++it;
}

return 0;
}
