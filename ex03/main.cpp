#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm* rrf;
    AForm* scf;
    AForm* ppf;
    AForm* unknown;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    unknown = someRandomIntern.makeForm("time travel request", "Marty McFly");

    Bureaucrat boss("The Boss", 1);
        if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
    }
    
    delete rrf;
    delete scf;
    delete ppf;
    std::cout << "Done!" << std::endl;
    return 0;
}