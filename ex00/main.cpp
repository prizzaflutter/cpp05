#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    // std::cout << "\n--- Test 1: The Perfect Bureaucrat ---" << std::endl;
    // try {
    //     Bureaucrat hermes("Hermes", 34);
    //     std::cout << hermes << std::endl; // Testing the << overload
        
    //     hermes.incrementGrade();
    //     std::cout << "After promotion: " << hermes << std::endl;
        
    //     hermes.decrementGrade();
    //     std::cout << "After demotion: " << hermes << std::endl;
    // } 
    // catch (std::exception &e) {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }

    // std::cout << "\n--- Test 2: Creating a Bureaucrat with a grade too high ---" << std::endl;
    // try {
    //     Bureaucrat boss("The Boss", 0); // Should throw an exception
    //     std::cout << boss << std::endl; // This line won't execute
    // } 
    // catch (std::exception &e) {
    //     std::cerr << "Error Caught: " << e.what() << std::endl;
    // }

    // std::cout << "\n--- Test 3: Creating a Bureaucrat with a grade too low ---" << std::endl;
    // try {
    //     Bureaucrat slacker("Slacker", 200); // Should throw an exception
    // } 
    // catch (std::exception &e) {
    //     std::cerr << "Error Caught: " << e.what() << std::endl;
    // }

    std::cout << "\n--- Test 4: Incrementing past grade 1 ---" << std::endl;
    try {
        Bureaucrat overachiever("Overachiever", 1);
        std::cout << overachiever << std::endl;
        overachiever.incrementGrade(); // Should throw here!
    } 
    catch (std::exception &e) {
        std::cerr << "Error Caught: " << e.what() << std::endl;
    }

    // std::cout << "\n--- Test 5: Decrementing past grade 150 ---" << std::endl;
    // try {
    //     Bureaucrat newbie("Newbie", 150);
    //     std::cout << newbie << std::endl;
    //     newbie.decrementGrade(); // Should throw here!
    // } 
    // catch (std::exception &e) {
    //     std::cerr << "Error Caught: " << e.what() << std::endl;
    // }

    // std::cout << "\nDone testing!" << std::endl;
    return 0;
}