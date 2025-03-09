#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// Form(void);
Form::Form(void): _name("Generic"), _signedAt(false), _signGrade(1), _execGrade(1) {}

// Form(std::string name, int signGrade, int execGrade);
Form::Form(std::string name, int signGrade, int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    this->_signedAt = false;
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

// Form(const Form &src);
Form::Form(const Form &src): _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
    *this = src;
}

// ~Form(void);
Form::~Form(void) {} 

// Form &operator=(const Form &src);
Form &Form::operator=(const Form &src)
{
    if (this != &src)
        this->_signedAt = src.getSignedAt();
    return (*this);
}

// std::string getName(void) const;
std::string Form::getName(void) const
{
    return (this->_name);
}

// bool        getSignedAt(void) const;
bool Form::getSignedAt(void) const
{
    return (this->_signedAt);
}

// int         getSignGrade(void) const;
int Form::getSignGrade(void) const
{
    return (this->_signGrade);
}

// int         getExecGrade(void) const;
int Form::getExecGrade(void) const
{
    return (this->_execGrade);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form: grade to high...");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form: grade to low...");
}

// void        beSigned(Bureaucrat &src);
void Form::beSigned(const Bureaucrat &src)
{
    if (src.getGrade() <= getSignGrade())
        this->_signedAt = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
    os << form.getName() << " has the following attibutes: " << form.getSignedAt() << " "
    << form.getSignGrade() << " "
    << form.getExecGrade() << std::endl;
    return os;
}
