#include <iostream>
#include <array>

int main() {
    std::array<int, 5> myArray = {1, 2, 3, 4, 5};

    // Iterator Functions (comments about without *)
    std::cout << "begin(): " << *myArray.begin() << "\n"; // 1st element
    std::cout << "end(): " << *(myArray.end() - 1) << "\n"; // last element
    std::cout << "rbegin(): " << *myArray.rbegin() << "\n"; // reverse (r) begin - from end
    std::cout << "rend(): " << *(myArray.rend() - 1) << "\n"; // Gives first element (start from rend and - 1 to get next (1st) element)
    std::cout << "cbegin(): " << *myArray.cbegin() << "\n"; // constant (c) begin - iterator cannot be modified
    std::cout << "cend(): " << *(myArray.cend() - 1) << "\n"; 
    std::cout << "crbegin(): " << *myArray.crbegin() << "\n";  //immutable reverse iterator 
    std::cout << "crend(): " << *(myArray.crend() - 1) << "\n";

    // Capacity Functions
    std::cout << "size(): " << myArray.size() << "\n";
    std::cout << "max_size(): " << myArray.max_size() << "\n";
    std::cout << "empty(): " << (myArray.empty() ? "true" : "false") << "\n";

    // Element Access Functions
    std::cout << "operator[]: " << myArray[2] << "\n";
    std::cout << "at(): " << myArray.at(3) << "\n";
    std::cout << "front(): " << myArray.front() << "\n";
    std::cout << "back(): " << myArray.back() << "\n"; // 
    std::cout << "data(): " << *(myArray.data()) << "\n"; // pointer to first element

    // Modifiers
    myArray.fill(10); // fill all container
    std::cout << "After fill(10): ";
    for (const auto &element : myArray) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    // Swap
    std::array<int, 5> anotherArray = {6, 7, 8, 9, 10}; // swap array to avoid copy error
    myArray.swap(anotherArray);
    std::cout << "After swap: ";
    for (const auto &element : myArray) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    return 0;
}

/*
Notes:
- myArray.begin(): Returns an iterator pointing to the first element of the array.
- *myArray.begin(): Dereferences (*) the iterator, giving you the value at the first position in the array.

- For loops just require the iterator, not the dereference

- rend/cend always point to an iterator, one position past the first/last element of the container, so need to subtract 1
-- operator on a reverse iterator moves to the next position in the sequence, 

- Use access functions over pointer for readability

- Reasons for constant iterator:
Read-Only Access of elements
Containers immutable throughout the iteration - Eg. client code does not unintentionally modify the container in an API
Multi threading - If one thread is iterating and another thread modifies it, using a constant iterator in the first thread helps avoid potential data races.
Unintended modifications - different functions on same container
Signals to other developers that the intention is to read, not modify, the elements during the iteration.

- myArray[1] = 25; to replace values.

*/
