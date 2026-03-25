#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm {
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
        ~RobotomyRequestForm();

        RobotomyRequestForm(const std::string& target);

        void executeAction() const;
};

#endif