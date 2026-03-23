#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));

    std::cout << "\n--- Creating Bureaucrats ---" << std::endl;
    Bureaucrat boss("The Boss", 1);
    Bureaucrat intern("Intern", 140);
    
    std::cout << boss << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n--- Testing Shrubbery Creation Form ---" << std::endl;
    ShrubberyCreationForm treeForm("Home");
    intern.signForm(treeForm);  
    intern.executeForm(treeForm); 
    boss.executeForm(treeForm);  

    std::cout << "\n--- Testing Robotomy Request Form ---" << std::endl;
    RobotomyRequestForm roboForm("Bender");
    boss.signForm(roboForm);
    boss.executeForm(roboForm);
    boss.executeForm(roboForm);
    boss.executeForm(roboForm);

    std::cout << "\n--- Testing Presidential Pardon Form ---" << std::endl;
    PresidentialPardonForm pardonForm("Ford Prefect");
    intern.signForm(pardonForm);
    boss.signForm(pardonForm);
    boss.executeForm(pardonForm); 

    std::cout << "\n--- Done! ---" << std::endl;
    return 0;
}