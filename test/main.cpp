#include <iostream>
#include <string>

class Bureaucrat {
private:
    const std::string _name; // CONSTANT!
    int _grade;

public:
    Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {}
    
    // MISSING: No custom Copy Assignment Operator!
};

int main() {
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    // We try to overwrite the intern with the boss's data
    intern = boss; 

    return 0;
}