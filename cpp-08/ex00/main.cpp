#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::cout << "--- TEST 1: std::vector ---" << std::endl;
    std::vector<int> myVec;
    myVec.push_back(10);
    myVec.push_back(20);
    myVec.push_back(30);

    try {
        std::cout << "Searching for 20..." << std::endl;
        std::vector<int>::iterator it1 = ::easyfind(myVec, 20);
        std::cout << "Success! Found: " << *it1 << std::endl;

        std::cout << "Searching for 99..." << std::endl;
        std::vector<int>::iterator it2 = ::easyfind(myVec, 99); // This will throw
        std::cout << "Success! Found: " << *it2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: std::list (Using Array Iterator method) ---" << std::endl;
    int arr[] = {1, 2, 42, 4, 5};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);
    std::list<int> myList(arr, arr + arrSize); // C++98 safe initialization!

    try {
        std::cout << "Searching for 42..." << std::endl;
        std::list<int>::iterator it3 = ::easyfind(myList, 42);
        std::cout << "Success! Found: " << *it3 << std::endl;

        std::cout << "Searching for 100..." << std::endl;
        std::list<int>::iterator it4 = ::easyfind(myList, 100); // This will throw
        std::cout << "Success! Found: " << *it4 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}