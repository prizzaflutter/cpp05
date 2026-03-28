#include <iostream>
#include <string>
#include "Array.hpp"


template <typename T1, typename T2, typename T3> class askour {
    public  : 
        T1 x;
        T2 y; 
        T3 z;
        askour(T1 v1, T2 v2, T3 v3) : x(v1), y(v2), z(v3) {}

        void getValues(){
            std::cout << x << " " << y << " " << z << std::endl;
        }
};

int main() {
    askour<int, double, char> a(124, 11.3, 'a');
    a.getValues();

    askour<double, char, int> b(11.3, 'b', 12);
    b.getValues();

    
    // std::cout << "--- TEST 1: EMPTY ARRAY ---" << std::endl;
    // Array<int> emptyArr;
    // std::cout << "Empty array size: " << emptyArr.size() << std::endl;

    // std::cout << "\n--- TEST 2: DEFAULT INITIALIZATION ---" << std::endl;
    // Array<int> intArr(5);
    // std::cout << "Integer array size: " << intArr.size() << std::endl;
    // std::cout << "Value at index 0 (should be 0): " << intArr[0] << std::endl;

    // std::cout << "\n--- TEST 3: POPULATING ARRAY ---" << std::endl;
    // for (unsigned int i = 0; i < intArr.size(); i++) {
    //     intArr[i] = i * 10;
    //     std::cout << "intArr[" << i << "] = " << intArr[i] << std::endl;
    // }

    // std::cout << "\n--- TEST 4: DEEP COPY CONSTRUCTOR ---" << std::endl;
    // Array<int> copyArr(intArr); // Copying intArr
    // std::cout << "Changing copyArr[0] to 999..." << std::endl;
    // copyArr[0] = 999;
    // std::cout << "copyArr[0]: " << copyArr[0] << std::endl;
    // std::cout << "intArr[0] (should still be 0!): " << intArr[0] << std::endl;

    // std::cout << "\n--- TEST 5: ASSIGNMENT OPERATOR ---" << std::endl;
    // Array<int> assignedArr;
    // assignedArr = intArr; // Assigning intArr
    // std::cout << "Changing assignedArr[1] to 888..." << std::endl;
    // assignedArr[1] = 888;
    // std::cout << "assignedArr[1]: " << assignedArr[1] << std::endl;
    // std::cout << "intArr[1] (should still be 10!): " << intArr[1] << std::endl;

    // std::cout << "\n--- TEST 6: STRING ARRAY ---" << std::endl;
    // Array<std::string> strArr(3);
    // strArr[0] = "Hello";
    // strArr[1] = "42";
    // strArr[2] = "World";
    // for (unsigned int i = 0; i < strArr.size(); i++) {
    //     std::cout << "strArr[" << i << "] = " << strArr[i] << std::endl;
    // }

    // std::cout << "\n--- TEST 7: OUT OF BOUNDS EXCEPTION ---" << std::endl;
    // try {
    //     std::cout << "Attempting to access intArr[100]..." << std::endl;
    //     std::cout << intArr[100] << std::endl; // This should throw!
    // } catch (const std::exception& e) {
    //     std::cerr << "Caught exception: " << e.what() << std::endl;
    // }

    // try {
    //     std::cout << "Attempting to access intArr[-1]..." << std::endl;
    //     std::cout << intArr[-1] << std::endl; // -1 becomes a massive unsigned int, which throws!
    // } catch (const std::exception& e) {
    //     std::cerr << "Caught exception: " << e.what() << std::endl;
    // }

    return 0;
}