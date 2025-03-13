#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

// Bureaucrat(const std::string name, int grade);
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
    setGrade(grade);
}

// Bureaucrat(void);
Bureaucrat::Bureaucrat(void): _name("Generic") {}

// Bureaucrat(const Bureaucrat &src);
Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    *this = src;
}

// ~Bureaucrat(void);
Bureaucrat::~Bureaucrat(void) {}

// Bureaucrat operator=(const Bureaucrat &src);
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
        setGrade(src.getGrade());
    return (*this);
}

// void        setGrade(int grade);
void Bureaucrat::setGrade(int grade)
{
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
     else if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    this->_grade = grade;
}

// std::string getName(void) const;
std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

// int         getGrade(void) const;
int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

// void        incrementGrade(void);
void    Bureaucrat::incrementGrade(void)
{
    setGrade(getGrade() - 1);
}

// void        decrementGrade(void);
void    Bureaucrat::decrementGrade(void)
{
    setGrade(getGrade() + 1);
}

void Bureaucrat::signForm(AForm &src) const
{
    try
    {
        src.beSigned(*this);
        std::cout << getName() << " signed " << src.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << getName() << " couldn’t sign " << src.getName() << " because " << e.what() << "." << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const
{
    try
    {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    } catch (std::exception &e)
    {
        std::cout << getName() << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}