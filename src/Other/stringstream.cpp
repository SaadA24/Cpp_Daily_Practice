#include <iostream>
#include <sstream>
#include <string>

int main () {

    std::stringstream ss;

    ss << "Hello";
    ss << " World";
    ss << 1;

    std::string combinedSs = ss.str(); // to retrieve
    std::cout << combinedSs << std::endl; // Hello World1

    std::cout << "Combined: " << combinedSs << std::endl; // Hello World1


    // string to int
    std::string stringWithInt = "1234";
    int intFromString;
    ss.clear();
    ss >> intFromString; // extract and assign
    ss.str(stringWithInt);
    

    std::cout << "Intfromstring: " << intFromString << std::endl; // Hello World1

    // int to string
    int number = 123456789;
    ss.clear();
    std::string numberAsString = ss.str(number);
    ss >> numberAsString;

    std::cout << "numtostring: " << numberAsString << std::endl;


    return 0;
}