#include <iostream>
#include <map>

//print in order
void printMap (const std::multimap<int, std::string>& myMultiMap)
    {
    for(auto it = myMultiMap.begin(); it != myMultiMap.end(); ++it)
        {
            std::cout << "key: " << it -> first << ", Value: " << it -> second << std::endl;
        }
    }

int main () 
{
    std::multimap<int, std::string> myMultiMap;

    myMultiMap.insert(std::make_pair(1, "One"));
    myMultiMap.insert(std::make_pair(2, "Two"));
    myMultiMap.insert(std::make_pair(2, "Two - Second time"));
    myMultiMap.insert(std::make_pair(3, "Three"));


    // Print in reverse order
        for(auto it = myMultiMap.rbegin(); it != myMultiMap.rend(); ++it)
    {
        std::cout << "key: " << it -> first << ", Value: " << it -> second << std::endl;
    }

    int keyToFind = 2;
    auto range = myMultiMap.equal_range(keyToFind); // Finding the Range of Elements with a Specific Key:

    for (auto it = range.first; it != range.second; ++it) {
    // 'it' iterates over all elements with key 'keyToFind'
    std::cout << "Value: " << it->second << std::endl;
    }

    // Capacity
    std::cout << "map size: " << myMultiMap.size() << std::endl;
    std::cout << "map max size " << myMultiMap.max_size() << std::endl;
    std::cout << (myMultiMap.empty() ? "Empty map" : "Not empty") << std::endl; // adding brackets enables it to print statement rather than give 0 or 1

    //Element Modifiers
    std::cout << "insert 5, 5 into map" << std::endl;
    myMultiMap.insert(std::make_pair(5, "five")); // make_pair for map insert
    int key5 = 5;

    auto findCount = myMultiMap.count(2); // returns the number of elements with key 1 in the map.
    std::cout << "Count of elements with key 2: " << findCount << std::endl;

    auto lowBound = myMultiMap.lower_bound(2); // returns an iterator pointing to the first element with a key not less than 2.
    std::cout << "Lower bound for key 2: " << lowBound->first << ", Value: " << lowBound->second << std::endl;

    auto uppBound = myMultiMap.upper_bound(3); // returns an iterator pointing to the first element with a key greater than 3.
    std::cout << "Upper bound for key 3: " << uppBound->first << ", Value: " <<uppBound->second << std::endl;

    auto equalRangeResult = myMultiMap.equal_range(6); // returns a pair of iterators representing the range of elements with key 6.
    for (auto it = equalRangeResult.first; it != equalRangeResult.second; ++it) {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;    
    }

    auto allocator = myMultiMap.get_allocator();
    std::cout << "Allocator address: " << &allocator << std::endl;

    // comparing keys/values
    auto keyComp = myMultiMap.key_comp(); // return comparison objects for keys and values, respectively.
    auto valueComp = myMultiMap.value_comp();

    //compares the keys 4 and 5 using the key comparison object. It returns true if 4 is considered less than 5 based on the map's comparison criteria.
    std::cout << "Key comparison result (key_comp): " << keyComp(4, 5) << std::endl;


    // Compares the values at the beginning and end of the map using the value comparison object
    // * deferencer gives actual values, not just iterators
    std::cout << "Value comparison result (value_comp): " << valueComp(*myMultiMap.begin(), *myMultiMap.end()) << std::endl;

    return 0;
}
/*
Notes:
- One-to-many relationships, where a single key can be associated with multiple values
- Automatically sorted based on their keys

-  Problems involving scheduling, resource allocation, or hierarchical relationships can be efficiently solved using multimaps

- If one=to-one, use map

To get values:
- Doesn't use .at() - Instead it uses .find() cpmbined with iteration
- instead of values at key [] - Iterate over the map using range of Elements with a Specific Key (equal_range): and extract the values
*/