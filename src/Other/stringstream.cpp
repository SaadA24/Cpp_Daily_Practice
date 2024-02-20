#include <iostream>
#include <sstream>
#include <string>

int main() {

    std::stringstream ss;

    // Concatenating strings and integer
    ss << "Hello";
    ss << " World";
    ss << 1;

    std::string combinedSs = ss.str(); // Retrieve concatenated string
    std::cout << "Combined: " << combinedSs << std::endl; // Output: Hello World1

    // String to int
    std::string stringWithInt = "1234";
    int intFromString;
    ss.clear(); // Clear any previous state
    ss.str(stringWithInt); // Set the content of stringstream to 'stringWithInt'
    ss >> intFromString; // Extract and assign

    std::cout << "Int from string: " << intFromString << std::endl; // Output: 1234

    // Int to string
    int number = 123456789;
    std::stringstream ss3;
    std::string numberAsString = ss3.str(); // Convert stringstream to string

    std::cout << "Number to string: " << numberAsString << std::endl; // Output: 123456789

    return 0;
}

/*
ss >> intFromString; - Extract and assign
ss3 << number; // Insert the integer

*/

