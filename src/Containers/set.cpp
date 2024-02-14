#include <iostream>
#include <set>

int main ()
{
    std::set<int> set1;
    set1.insert(1); 
    set1.insert(2); 
    set1.insert(3); 
    set1.insert(4); 
    set1.insert(1); 

    std::set<int> set2 = {5, 6, 7, 8, 9, 10};

    set1.merge(set2);
    for (const auto &element : set1)
    {
        std::cout << element << std::endl;
    }

    int value = 3;
    if(set1.find(value) != set1.end())
    {
        std::cout << value << " - is in set" << std::endl;
    }
    return 0;
}
/*
Notes
- std::set is an associative container that contains a sorted set of unique objects of type Key. 

- Sorting is done using the key omparison function Compare. Search, removal, and insertion operations have logarithmic complexity. 

- Sets are usually implemented as Red–black trees

- equivalence relation used to determine uniqueness. Can be reversed
*/
