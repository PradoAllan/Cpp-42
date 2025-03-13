#include "PresidentialPardonForm.hpp"
#include <iostream>

// PresidentialPardonForm(void);
PresidentialPardonForm::PresidentialPardonForm(void): AForm("Presidential", 25, 5), _target("Generic Target") {}

// PresidentialPardonForm(const PresidentialPardonForm &src);
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm(src) {}

// PresidentialPardonForm(std::string &target);
PresidentialPardonForm::PresidentialPardonForm(std::string &target): AForm("Presidential", 25, 5), _target(target) {}

// ~PresidentialPardonForm(void);
PresidentialPardonForm::~PresidentialPardonForm(void) {}

// PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this != &src)
        AForm::operator=(src);
    return (*this);
}

// virtual void    execute(Bureaucrat const & executor) const;
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}