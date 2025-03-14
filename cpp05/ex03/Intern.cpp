#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

// Intern(void);
Intern::Intern(void) {}

// Intern(const Intern &src);
Intern::Intern(const Intern &src)
{
    *this = src;
}

// ~Intern(void);
Intern::~Intern(void) {}

// AForm *makeForm(const std::string &formName, const std::string &target);
AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string name = formName;
    AForm       *form = NULL;
    int         len = formName.size();

    if (formName.empty())
        throw std::runtime_error("Empty form name...");
    for (int i = 0; i < len; i++)
        formName[i] = toupper(formName[i]);
    try
    {
        switch (formName[0])
        {
            case 'S':
                form = new ShrubberyCreationForm(target);
                std::cout << "Intern creates " << name << std::endl;
                break;
            case 'R':
                form = new RobotomyRequestForm(target);
                std::cout << "Intern creates " << name << std::endl;
                break;
            case 'P':
                form = new PresidentialPardonForm(target);
                std::cout << "Intern creates " << name << std::endl;
                break;
            default:
                throw std::runtime_error("Was not possible to instanciate a new AForm...");
                break;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (form);
}
    
// Intern &operator=(const Intern &src);
Intern &Intern::operator=(const Intern &src)
{
    if (this != &src)
        *this = src;
    return (*this);
}