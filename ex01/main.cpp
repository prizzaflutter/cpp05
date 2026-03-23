#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>


int main (){
    std::cout << " Bureaucrat is high enough level to sign" << std::endl;
    try {
        Bureaucrat boss("The Boss", 60);
        Form taxDoc("Tax Document", 50, 50);

        std::cout << taxDoc << std::endl;
        boss.signForm(taxDoc);
        std::cout << taxDoc << std::endl;
    }catch(std::exception& ex){
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 1;
}