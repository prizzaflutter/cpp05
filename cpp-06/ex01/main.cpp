#include "Serializer.hpp"

int main(){

    Data myData;
    myData.name = "askour";
    myData.age = 24;
    myData.level = 99;

    std::cout << "--- ORIGINAL DATA ---" << std::endl;
    std::cout << "Address: " << &myData << std::endl;
    std::cout << "Name: " << myData.name << " | Age: " << myData.age << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "--- SERIALIZED ---" << std::endl;
    std::cout << "Raw Integer (GPS Coordinate): " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "\n ----- DESERIALIZED DATA---" << std::endl;
    std::cout << "Name: " << ptr->name << " | Age: " << ptr->age << std::endl;

    std::cout << "--- VERIFICATION ---" << std::endl;
    if (ptr == &myData) {
        std::cout << "SUCCESS! The pointers match perfectly." << std::endl;
    } else {
        std::cout << "FAILURE! The pointers are different." << std::endl;
    }

    return 0;
}