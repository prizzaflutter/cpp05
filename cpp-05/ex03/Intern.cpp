#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other){
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern& Intern::operator=(const Intern& other){
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern(){
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeShrubbery(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotmy(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*formMakers[3])(const std::string& target) const = {
        &Intern::makeShrubbery,
        &Intern::makeRobotmy,
        &Intern::makePresidential
    };

    for (int i = 0; i < 3; i++){
        if (formName == formNames[i]){
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formMakers[i])(target);
        }
    }

    std::cout << "Error: Intern cannot create form " << formName << "because it deasn't exist." << std::endl;
    return NULL;
}