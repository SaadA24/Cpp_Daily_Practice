#include <iostream>
#include <deque>

#include <iostream>
#include <deque>

int main() {
    // Constructors
    std::deque<int> myDeque;  // Default constructor

    // Modifiers
    myDeque.push_back(1);  // Add element at the end
    myDeque.push_back(2);
    myDeque.push_front(0);  // Insert element at the beginning
    myDeque.emplace_back(3);  // Construct and insert element at the end (avoid copy/move with push_back)
    myDeque.emplace_front(7);

    // Element access
    std::cout << "Front: " << myDeque.front() << std::endl;  // Access first element
    std::cout << "Back: " << myDeque.back() << std::endl;    // Access last element

    // Iterators
    std::cout << "Deque elements: ";
    for (auto it = myDeque.begin(); it != myDeque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Reverse iterators
    std::cout << "Reverse deque elements: ";
    for (auto rit = myDeque.rbegin(); rit != myDeque.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Capacity
    std::cout << "Size: " << myDeque.size() << std::endl;
    std::cout << "Max Size: " << myDeque.max_size() << std::endl;

    // Modifiers
    myDeque.pop_back();  // Delete last element
    myDeque.pop_front();  // Delete first element

    //myDeque.begin() returns an iterator pointing to the beginning of the deque, and + 1 moves the iterator one position forward
    myDeque.insert(myDeque.begin() + 1, 99);  // Insert 99 element at position 1

    // Display modified deque
    std::cout << "Modified deque elements: ";
    for (const auto& element : myDeque) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Erase element at position 2
    myDeque.erase(myDeque.begin() + 2);

    // Display final deque
    std::cout << "Final deque elements: ";
    for (const auto& element : myDeque) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}


/*
Notes:
- Deque allows efficient insertion and deletion at both ends of container
- Deques can dynamically grow or shrink in size
- Constant-time random access to elements, similar to arrays
- Can be used to implement both queues and stacks efficiently (FIFO/LIFO)
- Breadth-first search (BFS) algorithms can benefit from deque's constant-time insertion and deletion at both ends.

- Useful in solving problems that involve sliding windows, where a window of a fixed size moves through a sequence of elements. 
Deques can efficiently maintain the elements within the window as it slides through the sequence.

- Suitable for scenarios where efficient insertion and deletion at both ends, as well as in the middle, are important

- Deques are typically implemented as a collection of fixed-size blocks (chunks), allowing for better memory utilization compared to dynamic arrays.
- Unlike vectors, deques provide efficient insertions and erasures in the middle of the container without invalidating iterators or element references 

- Compared to vectors, lists and forward lists:
- sequential access, cache locality, and minimal memory overhead are critical
- Need to reallocate all elements to a new memory location when their capacity is exceeded unlike deque which allocates new memory blocks
- Inserting or removing elements at the beginning of a vector involves shifting all subsequent elements, which has a linear time complexity

- For operations that involve frequent insertion or removals of elements at positions other than the beginning or the end, 
deques perform worse and have less consistent iterators and references than lists and forward lists.
*/
