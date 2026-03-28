#include <iostream>
#include <string>
#include "Array.hpp"


int main() {

    std::cout << "EMPTY ARRAY " << std::endl;
    Array<int> emptyArr;
    std::cout << "Empty array size: " << emptyArr.size() << std::endl;

    std::cout << " DEFAULT INITIALIZATION" << std::endl;
    Array<int> intArr(5);
    std::cout << "Integer array size: " << intArr.size() << std::endl;
    std::cout << "Value at index 0 (should be 0): " << intArr[0] << std::endl;
    std::cout << "Value at index 1 (should be 1): " << intArr[1] << std::endl;
    std::cout << "Value at index 2 (should be 2): " << intArr[2] << std::endl;
    std::cout << "Value at index 3 (should be 3): " << intArr[3] << std::endl;
    std::cout << "Value at index 4 (should be 4): " << intArr[4] << std::endl;

    std::cout << "POPULATING ARRAY" << std::endl;
    for (unsigned int i = 0; i < intArr.size(); i++) {
        intArr[i] = i * 10;
        std::cout << "intArr[" << i << "] = " << intArr[i] << std::endl;
    }

    std::cout << "DEEP COPY CONSTRUCTOR" << std::endl;
    Array<int> copyArr(intArr);
    std::cout << "Changing copyArr[0] to 999..." << std::endl;
    copyArr[0] = 999;
    std::cout << "copyArr[0]: " << copyArr[0] << std::endl;
    std::cout << "intArr[0] (should still be 0!): " << intArr[0] << std::endl;

    std::cout << "ASSIGNMENT OPERATOR" << std::endl;
    Array<int> assignedArr;
    assignedArr = intArr;
    std::cout << "Changing assignedArr[1] to 888..." << std::endl;
    assignedArr[1] = 888;
    std::cout << "assignedArr[1]: " << assignedArr[1] << std::endl;
    std::cout << "intArr[1] (should still be 10!): " << intArr[1] << std::endl;

    std::cout << "STRING ARRAY" << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "42";
    strArr[2] = "World";
    for (unsigned int i = 0; i < strArr.size(); i++) {
        std::cout << "strArr[" << i << "] = " << strArr[i] << std::endl;
    }

    std::cout << "OUT OF BOUNDS EXCEPTION" << std::endl;
    try {
        std::cout << "Attempting to access intArr[100]..." << std::endl;
        std::cout << intArr[100] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to access intArr[-1]..." << std::endl;
        std::cout << intArr[-1] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}