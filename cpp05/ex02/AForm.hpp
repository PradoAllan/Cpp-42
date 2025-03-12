#pragma once

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signedAt;
        const int           _signGrade;
        const int           _execGrade;
    public:
        AForm(void);
        AForm(const AForm &src);
        AForm(std::string name, int signGrade, int execGrade);
        virtual ~AForm(void);
        AForm &operator=(const AForm &src);

        std::string getName(void) const;
        bool        getSignedAt(void) const;
        int         getSignGrade(void) const;
        int         getExecGrade(void) const;

        void        beSigned(const Bureaucrat &src);

        virtual void    execute(Bureaucrat const & executor) const = 0;

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

std::ostream &operator<<(std::ostream &os, AForm const &form);