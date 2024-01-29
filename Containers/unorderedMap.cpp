#include <iostream>
#include <unordered_map>

//print in order
void printMap (const std::unordered_map<int, std::string>& myUnorderedMap)
    {
    for(auto it = myUnorderedMap.begin(); it != myUnorderedMap.end(); ++it)
        {
            std::cout << "key: " << it -> first << ", Value: " << it -> second << std::endl;
        }
    }

int main () 
{
    std::unordered_map<int, std::string> myUnorderedMap;
    myUnorderedMap[1] = "1";
    myUnorderedMap[2] = "2";
    myUnorderedMap[3] = "3";
    myUnorderedMap[4] = "4";

    // Capacity
    std::cout << "map size: " << myUnorderedMap.size() << std::endl;
    std::cout << "map max size " << myUnorderedMap.max_size() << std::endl;
    std::cout << (myUnorderedMap.empty() ? "Empty map" : "Not empty") << std::endl; // adding brackets enables it to print statement rather than give 0 or 1

    // Element Access
    std::cout << myUnorderedMap.at(1) << std::endl; // value at [key] safer, will return out of bounds error if no key
    std::cout << myUnorderedMap[1] << std::endl; //  value at [key],  This inserts a default-constructed value for key 1 if key doesn't exist

    //Element Modifiers
    std::cout << "insert 5, 5 into map" << std::endl;
    myUnorderedMap.insert(std::make_pair(5, "5")); // make_pair for map insert
    int key5 = 5;
    std::cout << key5 << " " << myUnorderedMap.at(5) << std::endl;

    //contains the code that might throw an exception
    try{ 
        myUnorderedMap.erase(4); 
        std::cout << myUnorderedMap.at(4) << std::endl;
    } catch (const std::out_of_range& e) // If an exception of type std::out_of_range is thrown during the try
    {
        std::cerr << "Error: " << e.what() << std::endl; //standard error stream (cerr) e.what() gives info
    }

    // Swap
    std::unordered_map<int, std::string> myUnorderedMap1 = {{6, "6"}, {7, "7"}}; // single line add elements
    myUnorderedMap.swap(myUnorderedMap1);
    std::cout << "Swapped myUnorderedMap1 with myUnorderedMap" << std::endl;
    printMap(myUnorderedMap1);
    std::cout << "Swapped myUnorderedMap with myUnorderedMap1" << std::endl;
    printMap(myUnorderedMap);

    // Modifiers    
    myUnorderedMap.clear();
    std::cout << "myUnorderedMap cleared" << std::endl;
    printMap(myUnorderedMap);
    myUnorderedMap1.emplace(7, "7");
    myUnorderedMap1.emplace_hint(myUnorderedMap1.end(), 8, "8");
    printMap(myUnorderedMap1);

    //Element Lookup
    auto findCount = myUnorderedMap1.count(1); // returns the number of elements with key 1 in the map.
    std::cout << "Count of elements with key 1: " << findCount << std::endl;

    auto equalRangeResult = myUnorderedMap1.equal_range(2); // returns a pair of iterators representing the range of elements with key 6.
    for (auto it = equalRangeResult.first; it != equalRangeResult.second; ++it) {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;    
    }
    auto allocator = myUnorderedMap1.get_allocator();
    std::cout << "Allocator address: " << &allocator << std::endl;

    // Will revise hash tables and return to this
    // *Buckets:
    std::cout << "Number of buckets: " << myUnorderedMap.bucket_count() << std::endl;
    std::cout << "Maximum number of buckets: " << myUnorderedMap.max_bucket_count() << std::endl;  
    int keyToFindBucket = 2;
    std::cout << "Bucket for key " << keyToFindBucket << ": " << myUnorderedMap.bucket(keyToFindBucket) << std::endl;
    for (size_t i = 0; i < myUnorderedMap.bucket_count(); ++i) {
        std::cout << "Bucket " << i << " size: " << myUnorderedMap.bucket_size(i) << std::endl;
    }
    // *hash policy
    std::cout << "Load factor: " << myUnorderedMap.load_factor() << std::endl;
    std::cout << "Maximum load factor: " << myUnorderedMap.max_load_factor() << std::endl;

    return 0;
}
/*
Notes:
- For more efficient lookup when order doesn't matter and point of insertion doesn't matter
- Can't traverse in reverse and can't use compare values functions like map
- *Need to better understand hash tables
- Like for checking for the existence of unique identifiers or data caching
*/