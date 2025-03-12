#include "ShrubberyCreationForm.hpp"

// ShrubberyCreationForm(void);
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Shrubbery", 145, 137), _target("Generic target") {}

// ShrubberyCreationForm(const ShrubberyCreationForm &src);
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src) {}

// ShrubberyCreationForm(std::string &target);
ShrubberyCreationForm::ShrubberyCreationForm(std::string &target): AForm("Shrubbery", 145, 137), _target(target) {}

// ~ShrubberyCreationForm(void);
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src)
        AForm::operator=(src);
    return (*this);
}