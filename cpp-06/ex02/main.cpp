#include "B.hpp"
#include "C.hpp"
#include "A.hpp"
#include "Base.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

Base* generate(void){
    int random = std::rand() % 3;

    if (random == 0){
        std::cout << "Generated: A" << std::endl;
        return new A();
    }else if (random == 2){
        std::cout << "Generated: B" << std::endl;
        return new B();
    }else {
        std::cout << "Generated: C" << std::endl;
        return new C();
    }
}

void identify(Base* p){
    if (dynamic_cast<A*>(p) != NULL){
        std::cout << "Pointer identified as: A" << std::endl;
    }else if (dynamic_cast<B*>(p) != NULL){
        std::cout << "Pointer identified as: B" << std::endl;
    }else if (dynamic_cast<C*>(p) != NULL){
        std::cout << "Pointer identified as : C" << std::endl;
    }else{
        std::cout << "Unknow Type" << std::endl;
    }
}

void identify(Base& p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "Refrence identified as: A" << std::endl;
        return;
    }catch(std::exception& e){}
     try{
        (void)dynamic_cast<B&>(p);
        std::cout << "Refrence identified as: B" << std::endl;
        return;
    }catch(std::exception& e){}
     try{
        (void)dynamic_cast<C&>(p);
        std::cout << "Refrence identified as: C" << std::endl;
        return;
    }catch(std::exception& e){}
    std::cout << "Unknown Type" << std::endl;
}

int main (){
    std::srand(std::time(NULL));

    std::cout << "--- TEST 1 ---" << std::endl;
    Base* mystery1 = generate();
    identify(mystery1);
    identify(*mystery1);
    delete mystery1;

    std::cout << "--- TEST 2 ---" << std::endl;
    Base* mystery2 = generate();
    identify(mystery2);
    identify(*mystery2);
    delete mystery2;

    std::cout << "--- TEST 3 ---" << std::endl;
    Base* mystery3 = generate();
    identify(mystery3);
    identify(*mystery3);
    delete mystery3;
}