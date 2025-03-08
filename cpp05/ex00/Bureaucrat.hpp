#pragma once

# include <string>
# include <exception>

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat(const std::string name, int grade);

        ~Bureaucrat(void);

        Bureaucrat &operator=(const Bureaucrat &src);

        void        setGrade(int grade);
        std::string getName(void) const;
        int         getGrade(void) const;
        void        incrementGrade(void);
        void        decrementGrade(void);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);