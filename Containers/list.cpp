#include <iostream>
#include <list>

// Function to display the contents of list
void displayList(const std::list<int>& myList) {
    for (const auto& element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Declare list
    std::list<int> myList;

    // Modifiers
    myList.push_back(1);
    myList.push_back(3);
    myList.push_back(2);

    // Display the original list
    std::cout << "Original List: ";
    displayList(myList);

    // Operations
    myList.sort();
    std::cout << "Sorted List: ";
    displayList(myList);

    myList.reverse();
    std::cout << "Reversed List: ";
    displayList(myList);

    myList.push_front(4);
    std::cout << "Element added at the front: ";
    displayList(myList);

    myList.pop_back();
    std::cout << "Last element removed: ";
    displayList(myList);

    myList.emplace_front(5);
    std::cout << "Emplaced at the front: ";
    displayList(myList);

    myList.push_front(6);
    std::cout << "Element pushed at the front: ";
    displayList(myList);

    myList.pop_front();
    std::cout << "First element popped: ";
    displayList(myList);

    myList.emplace_back(7);
    std::cout << "Emplaced at the back: ";
    displayList(myList);

    myList.push_back(8);
    std::cout << "Element pushed at the back: ";
    displayList(myList);

    myList.pop_back();
    std::cout << "Last element popped: ";
    displayList(myList);

    myList.emplace(myList.begin(), 9);
    std::cout << "Emplaced at a specific position: ";
    displayList(myList);

    myList.insert(myList.begin(), 10);
    std::cout << "Element inserted at the beginning: ";
    displayList(myList);

    myList.erase(myList.begin());
    std::cout << "Element at the beginning erased: ";
    displayList(myList);

    // Capacity
    std::cout << "Size of the list: " << myList.size() << std::endl;
    std::cout << "Maximum size of the list: " << myList.max_size() << std::endl;

    // Element Access
    std::cout << "First element: " << myList.front() << std::endl;
    std::cout << "Last element: " << myList.back() << std::endl;

    // Clear the list
    myList.clear();
    std::cout << "List cleared. Is empty: " << (myList.empty() ? "true" : "false") << std::endl;

    return 0;
}

/*
Notes:
- If you don't need bidirectional iteration, reverse iterators, or the additional capabilities provided by list, 
forward_list might be a more memory-efficient choice

- Doubly linked lists (list) -ordering is kept internally by the association to each element of a link to the element preceding it and a link to the element following it.
- This is what makes bi-directional traversing

- list provides bidirectional iterators, allowing you to traverse the list in both forward and backward directions. 
- Has an advantage when it comes to inserting or deleting elements at any position within the list, thanks to bidirectional iterators.
- Also provides a more efficient splice function that transfers elements from one list to another or within the same list.
*/
