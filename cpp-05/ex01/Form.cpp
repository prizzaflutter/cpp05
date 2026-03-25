#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("defaul form"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "From copy constructor calle" << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form copy assignment operator called" << std::endl;
    if ( this != &other){
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form(){
    std::cout << "From Destructor called For: " << this->name << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    std::cout << "From Parametrized constructor called for " << name << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1) throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150) throw Form::GradeTooLowException();
}

const std::string& Form::getName() const {
        return this->name;
}

bool Form::getIsSigned() const {
    return this->isSigned;
}

int Form::getGradeToSign() const {
    return this->gradeToSign;
}

int Form::getGradeToExcute() const {
    return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() <= this->gradeToSign){
        this->isSigned = true;
    }
    else {
        throw Form::GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Form grade requirement is too high";
}

const char * Form::GradeTooLowException::what() const throw(){
    return "Form grade requirement is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() 
       << ", Status: " << form.getIsSigned()
       << ", Sign Grade: " << form.getGradeToSign()
       << ", Exec Grade: " << form.getGradeToExcute();
    return os;
}




