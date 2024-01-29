#include <iostream>
#include <forward_list>

int main() {
    // (constructor) Construct forward_list object
    std::forward_list<int> myForwardList;

    // (emplace_front) Construct and insert element at beginning
    myForwardList.emplace_front(1);
    myForwardList.emplace_front(2);
    myForwardList.emplace_front(3);

    // (begin) Return iterator to beginning
    auto itBegin = myForwardList.begin();

    // (end) Return iterator to end
    auto itEnd = myForwardList.end();

    // (cbegin) Return const_iterator to beginning
    auto itCBegin = myForwardList.cbegin();

    // (cend) Return const_iterator to end
    auto itCEnd = myForwardList.cend();

    // (front) Access first element
    std::cout << "Front element: " << myForwardList.front() << std::endl;

    // (empty) Test whether forward_list is empty
    std::cout << "Is forward_list empty? " << (myForwardList.empty() ? "Yes" : "No") << std::endl;

    // (max_size) Return maximum size
    std::cout << "Maximum size of forward_list: " << myForwardList.max_size() << std::endl;

    // (emplace_after) Construct and insert element after a specific position
    myForwardList.emplace_after(itBegin, 4);

    // (insert_after) Insert elements after a specific position
    myForwardList.insert_after(itBegin, {5, 6, 7});

    // (erase_after) Erase elements after a specific position. (Modify itBegin with new position)
    itBegin = myForwardList.erase_after(itBegin);

    // (push_front) Insert element at beginning
    myForwardList.push_front(8);

    // (pop_front) Delete first element
    myForwardList.pop_front();

    // (splice_after) Transfer elements to another forward_list
    std::forward_list<int> anotherList = {10, 11, 12};
    myForwardList.splice_after(itBegin, anotherList);

    // (remove) Remove elements with specific value
    myForwardList.remove(5);

    // (remove_if) Remove elements fulfilling condition (lambda)
    myForwardList.remove_if([](int x) { return x > 8; });

    // (unique) Remove duplicate values
    myForwardList.unique();

    // (merge) Merge sorted lists
    std::forward_list<int> sortedList1 = {2, 4, 6};
    std::forward_list<int> sortedList2 = {1, 3, 5};
    sortedList1.merge(sortedList2);

    // (sort) Sort elements in container
    myForwardList.sort();

    // (reverse) Reverse the order of elements
    myForwardList.reverse();

    // (clear) Clear content
    myForwardList.clear();

    return 0;
}
/*
Notes:

- Implements a singly-linked list, where each element (node) in the list contains a value and a pointer to the next element in the sequence
- Suitable for scenarios where fast insertion and deletion at the beginning are critical, 
and random access to elements by index is not required. 

- emplace_after can be more efficient in terms of performance because it constructs elements in-place, avoiding unnecessary copies or moves.
- insert_after is more suitable If you have pre-constructed elements or a range of values, as it allows you to directly provide those elements.

Advantages:
- Tends to have lower memory overhead compared to deque since it uses a singly-linked list.
- Designed to be more memory-efficient and can provide faster insertions and removals from the beginning than list

- Unlike some other containers (e.g., std::vector), inserting or removing elements in a forward_list 
doesn't invalidate iterators to elements other than the one being inserted or removed.

Drawbacks:
- No Bidirectional Iterators: Unlike std::list, std::forward_list provides only forward iterators. 
- This means that you can only traverse the list in the forward direction.

- Doesn't support efficient random access to elements. 
- Accessing an element at a specific position requires traversing the list from the beginning until the desired position is reached.

- Insertions and deletions in the middle or at the end are less efficient compared to std::deque.

*/