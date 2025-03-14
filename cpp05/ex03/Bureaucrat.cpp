#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(void): _name("Generic") {}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    *this = src;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
        setGrade(src.getGrade());
    return (*this);
}

void Bureaucrat::setGrade(int grade)
{
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
     else if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    this->_grade = grade;
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade(void)
{
    setGrade(getGrade() - 1);
}

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