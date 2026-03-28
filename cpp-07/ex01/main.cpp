#include "iter.hpp"

void addOne (int& number){
    number += 1;
}

template <typename T>

void printElement(const T& element){
    std::cout << element << " ";
}

int main (){

    int array[] = {1, 2, 3, 4, 5};

    std::cout << "original array: ";
    ::iter(array, 4, printElement<int>);

    ::iter(array, 4, addOne);
    std::cout << "\nAdding one : ";
    ::iter(array, 4, printElement<int>);

    std::cout << "\nprinting  a string array" << std::endl;

    std::string strArray[] = {"idriss", "askour", "is not here"};
    ::iter(strArray, 3, printElement<std::string>);

    std::cout << "\ntest const array" << std::endl;
    
    const double constArray[] = {1.3, 4.23, 1.12};
    std::cout << "\nprinting the const double array: ";
    ::iter(constArray, 3, printElement<double>);


    return 0;
}