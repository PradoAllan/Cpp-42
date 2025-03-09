#pragma once

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signedAt;
        const int           _signGrade;
        const int           _execGrade;
    public:
        Form(void);
        Form(const Form &src);
        Form(std::string name, int signGrade, int execGrade);
        ~Form(void);
        Form &operator=(const Form &src);

        std::string getName(void) const;
        bool        getSignedAt(void) const;
        int         getSignGrade(void) const;
        int         getExecGrade(void) const;

        void        beSigned(const Bureaucrat &src);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, Form const &form);