#include "RobotomyRequestForm.hpp"
#include <iostream>

// RobotomyRequestForm(void);
RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy", 72, 45), _target("Generic Target") {}

// RobotomyRequestForm(const RobotomyRequestForm &src);
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src) {}

// RobotomyRequestForm(std::string &target);
RobotomyRequestForm::RobotomyRequestForm(std::string &target): AForm("Robotomy", 72, 45), _target(target)
{
    std::cout << "DrrrrrDrrrrrrDrrrrr..." << std::endl;
    if ((std::rand() % 2) == 0)
        std::cout << target << " has been robotomized seccessfully!" << std::endl;
    else
        std::cout << "Unfortunately The robotomy failed..." << std::endl;
}

// ~RobotomyRequestForm(void);
RobotomyRequestForm::~RobotomyRequestForm(void) {}

// RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this != &src)
        AForm::operator=(src);
    return (*this);
}