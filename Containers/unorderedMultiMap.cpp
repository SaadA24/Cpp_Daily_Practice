#include <iostream>
#include <unordered_map>

//print in order
void printMap (const std::unordered_multimap<int, std::string>& myUnorderedMultiMap)
    {
    for(auto it = myUnorderedMultiMap.begin(); it != myUnorderedMultiMap.end(); ++it)
        {
            std::cout << "key: " << it -> first << ", Value: " << it -> second << std::endl;
        }
    }

int main () 
{
    std::unordered_multimap<int, std::string> myUnorderedMultiMap;

    myUnorderedMultiMap.insert(std::make_pair(10, "Ten"));
    myUnorderedMultiMap.insert(std::make_pair(2, "Two"));
    myUnorderedMultiMap.insert(std::make_pair(2, "Two - Second time"));
    myUnorderedMultiMap.insert(std::make_pair(3, "Three"));

    int keyToFind = 2;
    auto range = myUnorderedMultiMap.equal_range(keyToFind); // Finding the Range of Elements with a Specific Key:

    for (auto it = range.first; it != range.second; ++it) {
    // 'it' iterates over all elements with key 'keyToFind'
    std::cout << "Value: " << it->second << std::endl;
    }

    // Capacity
    std::cout << "map size: " << myUnorderedMultiMap.size() << std::endl;
    std::cout << "map max size " << myUnorderedMultiMap.max_size() << std::endl;
    std::cout << (myUnorderedMultiMap.empty() ? "Empty map" : "Not empty") << std::endl; // adding brackets enables it to print statement rather than give 0 or 1

    //Element Modifiers
    std::cout << "insert 5, 5 into map" << std::endl;
    myUnorderedMultiMap.insert(std::make_pair(5, "five")); // make_pair for map insert
    int key5 = 5;

    auto findCount = myUnorderedMultiMap.count(2); // returns the number of elements with key 1 in the map.
    std::cout << "Count of elements with key 2: " << findCount << std::endl;

    auto equalRangeResult = myUnorderedMultiMap.equal_range(6); // returns a pair of iterators representing the range of elements with key 6.
    for (auto it = equalRangeResult.first; it != equalRangeResult.second; ++it) {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;    
    }
    auto allocator = myUnorderedMultiMap.get_allocator();
    std::cout << "Allocator address: " << &allocator << std::endl;

    //Will print it based on hash table implementation
    for (const auto& pair : myUnorderedMultiMap) {
    std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl; //note pair.first / second
    }

    return 0;
}
/*
Notes:
- When you need to store multiple values for a single key
- This is particularly useful when you are dealing with data where keys are not unique.

- In situations where you want to group items based on some common characteristic or attribute but order doesn't matter 
- When creating an index to quickly look up records based on a non-unique key (e.g., indexing names of people or tags in a blog)
- Event system where events are associated with specific tags or categories, and you want to efficiently look up all events related to a particular category.
- Handling multiple responses or events associated with the same request or identifier

- Same functions of multimap, with no sorting
*/