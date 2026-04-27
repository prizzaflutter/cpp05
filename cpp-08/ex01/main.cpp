#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>  

int main() {
    std::cout << "--- 1. SUBJECT TEST ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest:  " << sp.longestSpan() << std::endl;

    std::cout << "\n--- 2. EXCEPTION TESTS ---" << std::endl;
    try {
        sp.addNumber(42);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    Span emptySpan(5);
    emptySpan.addNumber(1);
    try {
        emptySpan.shortestSpan(); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- 3. RANGE ITERATOR TEST (10,000 Numbers) ---" << std::endl;
    Span massiveSpan(10000);
    std::vector<int> randomNumbers;
    
    std::srand(std::time(NULL));
    for (int i = 0; i < 10000; i++) {
        randomNumbers.push_back(std::rand());
    }

    try {
        massiveSpan.addRange(randomNumbers.begin(), randomNumbers.end());
        std::cout << "Successfully added 10,000 numbers using addRange()!" << std::endl;
        std::cout << "Shortest Span: " << massiveSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span:  " << massiveSpan.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}