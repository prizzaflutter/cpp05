#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open()){
        std::cerr << "Error: Could not open file shrubbery." << std::endl;
        return ; 
    }
    file << "  ^  \n";
    file << " ^^^ \n";
    file << "^^^^^\n";
    file << "  |  \n";

    file.close();
}

