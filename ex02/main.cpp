#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    // Seed the random number generator for the Robotomy form
    srand(time(NULL));

    std::cout << "\n--- Creating Bureaucrats ---" << std::endl;
    Bureaucrat boss("The Boss", 1);
    Bureaucrat intern("Intern", 140);
    
    std::cout << boss << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n--- Testing Shrubbery Creation Form ---" << std::endl;
    ShrubberyCreationForm treeForm("Home");
    intern.signForm(treeForm);     // Intern can sign (140 <= 145)
    intern.executeForm(treeForm);  // Intern CANNOT execute (140 > 137)
    boss.executeForm(treeForm);    // Boss executes it

    std::cout << "\n--- Testing Robotomy Request Form ---" << std::endl;
    RobotomyRequestForm roboForm("Bender");
    boss.signForm(roboForm);
    boss.executeForm(roboForm);
    boss.executeForm(roboForm); // Execute a few times to test the 50% chance
    boss.executeForm(roboForm);

    std::cout << "\n--- Testing Presidential Pardon Form ---" << std::endl;
    PresidentialPardonForm pardonForm("Ford Prefect");
    intern.signForm(pardonForm);  // Intern tries to sign (Fails, 140 > 25)
    boss.signForm(pardonForm);    // Boss signs it
    boss.executeForm(pardonForm); // Boss executes it

    std::cout << "\n--- Done! ---" << std::endl;
    return 0;
}