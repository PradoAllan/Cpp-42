#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void): AForm("Presidential", 25, 5), _target("Generic Target") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm(src) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("Presidential", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this != &src)
        AForm::operator=(src);
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}