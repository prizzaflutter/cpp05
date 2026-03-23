#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("defaul Aform"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "From copy constructor calle" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << "AForm copy assignment operator called" << std::endl;
    if ( this != &other){
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm(){
    std::cout << "From Destructor called For: " << this->name << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    std::cout << "From Parametrized constructor called for " << name << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1) throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150) throw AForm::GradeTooLowException();
}

const std::string& AForm::getName() const {
        return this->name;
}

bool AForm::getIsSigned() const {
    return this->isSigned;
}

int AForm::getGradeToSign() const {
    return this->gradeToSign;
}

int AForm::getGradeToExcute() const {
    return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() <= this->gradeToSign){
        this->isSigned = true;
    }
    else {
        throw AForm::GradeTooLowException();
    }
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->gradeToExecute)
        throw AForm::GradeTooLowException();

    this->executeAction();
}

const char* AForm::FormNotSignedException::what() const throw(){
    return "Form cannot be executed because it is not signed";
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "AForm grade requirement is too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "AForm grade requirement is too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform) {
    os << "AForm: " << Aform.getName() 
       << ", Status: " << (Aform.getIsSigned() ? "Signed" : "Not Signed")
       << ", Sign Grade: " << Aform.getGradeToSign()
       << ", Exec Grade: " << Aform.getGradeToExcute();
    return os;
}




