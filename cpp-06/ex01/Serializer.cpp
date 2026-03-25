#include "Serializer.hpp"

Serializer::Serializer(void){
    std::cout << "default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other){
    (void)other;
    std::cout << "copy constructor called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other){
    (void)other;
    return  *this;
}

Serializer::~Serializer(){
    std::cout << "destuctor called" << std::endl;
}


uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}