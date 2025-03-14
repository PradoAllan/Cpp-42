#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(void): _name("Generic"), _signedAt(false), _signGrade(1), _execGrade(1) {}

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    this->_signedAt = false;
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src): _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
    *this = src;
}

AForm::~AForm(void) {} 

AForm &AForm::operator=(const AForm &src)
{
    if (this != &src)
        this->_signedAt = src.getSignedAt();
    return (*this);
}

std::string AForm::getName(void) const
{
    return (this->_name);
}

bool AForm::getSignedAt(void) const
{
    return (this->_signedAt);
}

int AForm::getSignGrade(void) const
{
    return (this->_signGrade);
}

int AForm::getExecGrade(void) const
{
    return (this->_execGrade);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("AForm: grade to high...");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("AForm: grade to low...");
}

const char *AForm::AlreadySigned::what() const throw()
{
    return ("AForm: already signed...");
}

void    AForm::execute(Bureaucrat const & executor) const
{
    if (getSignedAt())
        throw (AForm::AlreadySigned());
    if (executor.getGrade() > getExecGrade())
        throw (AForm::GradeTooLowException());
}

void AForm::beSigned(const Bureaucrat &src)
{
    if (src.getGrade() <= getSignGrade())
        this->_signedAt = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, AForm const &form)
{
    os << form.getName() << " has the following attibutes: " << form.getSignedAt() << " "
    << form.getSignGrade() << " "
    << form.getExecGrade() << std::endl;
    return os;
}
