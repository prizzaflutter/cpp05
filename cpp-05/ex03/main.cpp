#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    std::cout << "\n--- Hiring an Intern ---" << std::endl;
    Intern someRandomIntern;
    AForm* rrf;
    AForm* scf;
    AForm* ppf;
    AForm* unknown;

    std::cout << "\n--- Intern creating valid forms ---" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");

    std::cout << "\n--- Intern creating an invalid form ---" << std::endl;
    unknown = someRandomIntern.makeForm("time travel request", "Marty McFly");

    std::cout << "\n--- Bureaucrat interacting with Intern's forms ---" << std::endl;
    Bureaucrat boss("The Boss", 1);
    
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
    }

    std::cout << "\n--- Cleaning up memory (PREVENTING LEAKS) ---" << std::endl;
    delete rrf;
    delete scf;
    delete ppf;

    std::cout << "Done!" << std::endl;
    return 0;
}