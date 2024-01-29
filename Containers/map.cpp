#include <iostream>
#include <map>

//print in order
void printMap (const std::map<int, std::string>& myMap)
    {
    for(auto it = myMap.begin(); it != myMap.end(); ++it)
        {
            std::cout << "key: " << it -> first << ", Value: " << it -> second << std::endl;
        }
    }

int main () 
{
    std::map<int, std::string> myMap;
    myMap[1] = "1";
    myMap[2] = "2";
    myMap[3] = "3";
    myMap[4] = "4";


    // Print in reverse order
        for(auto it = myMap.rbegin(); it != myMap.rend(); ++it)
    {
        std::cout << "key: " << it -> first << ", Value: " << it -> second << std::endl;
    }

    // Capacity
    std::cout << "map size: " << myMap.size() << std::endl;
    std::cout << "map max size " << myMap.max_size() << std::endl;
    std::cout << (myMap.empty() ? "Empty map" : "Not empty") << std::endl; // adding brackets enables it to print statement rather than give 0 or 1

    // Element Access
    std::cout << myMap.at(1) << std::endl; // value at [key] safer, will return out of bounds error if no key
    std::cout << myMap[1] << std::endl; //  value at [key],  This inserts a default-constructed value for key 1 if key doesn't exist

    //Element Modifiers
    std::cout << "insert 5, 5 into map" << std::endl;
    myMap.insert(std::make_pair(5, "five")); // make_pair for map insert
    int key5 = 5;
    std::cout << key5 << " " << myMap.at(5) << std::endl;

    //contains the code that might throw an exception
    try{ 
        myMap.erase(5); 
        std::cout << myMap.at(5) << std::endl;
    } catch (const std::out_of_range& e) // If an exception of type std::out_of_range is thrown during the try
    {
        std::cerr << "Error: " << e.what() << std::endl; //standard error stream (cerr) e.what() gives info
    }

    std::map<int, std::string> myMap1 = {{6, "6"}, {7, "7"}}; // single line add elements
    myMap.swap(myMap1);
    std::cout << "Swapped myMap1 with myMap" << std::endl;
    printMap(myMap1);
    std::cout << "Swapped myMap with myMap1" << std::endl;
    printMap(myMap);

    myMap.clear();
    std::cout << "myMap cleared" << std::endl;
    printMap(myMap);

    myMap1.emplace(7, "7");

    myMap1.emplace_hint(myMap1.end(), 8, "8");

    printMap(myMap1);

    auto findCount = myMap1.count(1); // returns the number of elements with key 1 in the map.
    std::cout << "Count of elements with key 1: " << findCount << std::endl;

    auto lowBound = myMap1.lower_bound(2); // returns an iterator pointing to the first element with a key not less than 2.
    std::cout << "Lower bound for key 2: " << lowBound->first << ", Value: " << lowBound->second << std::endl;

    auto uppBound = myMap1.upper_bound(3); // returns an iterator pointing to the first element with a key greater than 3.
    std::cout << "Upper bound for key 3: " << uppBound->first << ", Value: " <<uppBound->second << std::endl;

    auto equalRangeResult = myMap1.equal_range(6); // returns a pair of iterators representing the range of elements with key 6.
    for (auto it = equalRangeResult.first; it != equalRangeResult.second; ++it) {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;    
    }

    auto allocator = myMap1.get_allocator();
    std::cout << "Allocator address: " << &allocator << std::endl;

    // comparing keys/values
    auto keyComp = myMap1.key_comp(); // return comparison objects for keys and values, respectively.
    auto valueComp = myMap1.value_comp();

    //compares the keys 4 and 5 using the key comparison object. It returns true if 4 is considered less than 5 based on the map's comparison criteria.
    std::cout << "Key comparison result (key_comp): " << keyComp(4, 5) << std::endl;


    // Compares the values at the beginning and end of the map using the value comparison object
    std::cout << "Value comparison result (value_comp): " << valueComp(*myMap1.begin(), *myMap1.end()) << std::endl;

    return 0;
}
/*
Notes:

- Use when the order of elements matters, or when you need sorted access to the keys. 
It's suitable for cases where logarithmic search and ordered iteration are acceptable.

- for loop, you can use either ++it or it++, and the loop will behave the same way,
however, the convention in C++ is to prefer ++it for efficiency reasons.
because it doesn't involve creating a temporary copy of the original iterator.

- No direct function to retrieve the key based on the value, have to iterate for unique key/values

- Using templates, allows the print function to work with maps of different types. 
It provides flexibility and reusability in cases where the exact types might vary.

- Remember void because the primary purpose is to perform an action, 
not to produce a result that needs to be captured.

- Emplace function directly constructs the element in-place without the need to create a temporary object. 
This can be more efficient than other insertion methods

- emplace_hint is similar to emplace, but it takes a hint iterator as an argument, 
providing a suggestion to the position where the new element should be inserted.
- .end() is passed as the hint, suggesting that the insertion should be done at the end of the map.

- Fast search and retrieval, map implemented as binary search tree (red-black tree)
- logarithmic time complexity for search operations (O(log n)), where n is the number of elements
- maps automatically sort elements based on keys
- dynamic size
*/