#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs){
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &rhs){
        this->grade = rhs.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name){
    std::cout << "Bureaucrat parametrized constructor called for: " << name << std::endl;
    if (grade < 1)throw Bureaucrat::GradeTooLowException();
    if (grade > 150) throw Bureaucrat::GradeTooHighException(); 
    this->grade = grade;
}

const std::string& Bureaucrat::getName () const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}


void Bureaucrat::incrementGrade(){
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooLowException();
    this->grade--;
}

void Bureaucrat::decrementGrade(){
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooHighException();
    this->grade++;
}

void Bureaucrat::signForm(Form& form){
    try{
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }catch(std::exception& ex){
        std::cout << this->name << " couldn't sign " << form.getName() << " because " << ex.what() << std::endl; 
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw () {
    return "Grade is too high Maximum grade is 1 ";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low Minimum grade is 150";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
    os << bureaucrat.getName() << ", bureaucrat grade " <<  bureaucrat.getGrade() << ".";
    return os;
}