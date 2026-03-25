# ifndef AAFORM_HPP
# define AAFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

        AForm(const std::string& name, int gradeToSign, int gradeToExcute);

        const  std::string& getName() const;
        bool                getIsSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExcute() const;

        void beSigned(const Bureaucrat& bureaucrat);

        void execute(Bureaucrat const & executor) const;
        virtual void executeAction() const = 0;

        class GradeTooHighException : public std::exception {
            public: 
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public :
                virtual const char* what () const throw();
        };
        class FormNotSignedException : public std::exception {
            public: virtual const char* what() const throw();
        };
    };

std::ostream& operator<<(std::ostream& os, const AForm& from);

# endif