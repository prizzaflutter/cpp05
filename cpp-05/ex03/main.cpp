#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    Intern intern;
    AForm* rrf = intern.makeForm("robotomy request", "idriss");
    AForm* scf = intern.makeForm("shrubbery creation", "askour");
    AForm* ppf = intern.makeForm("presidential pardon", "room");
    AForm* unknown = intern.makeForm("unknow form", "test");


    delete rrf;
    delete scf;
    delete ppf;
    std::cout << "Done!" << std::endl;
    return 0;
}