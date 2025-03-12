#include "RobotomyRequestForm.hpp"

// RobotomyRequestForm(void);
RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy", 72, 45), _target("Generic Target") {}

// RobotomyRequestForm(const RobotomyRequestForm &src);
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src) {}

// RobotomyRequestForm(std::string &target);
RobotomyRequestForm::RobotomyRequestForm(std::string &target): AForm("Robotomy", 72, 45), _target(target) {}

// ~RobotomyRequestForm(void);
RobotomyRequestForm::~RobotomyRequestForm(void) {}

// RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this != &src)
        AForm::operator=(src);
    return (*this);
}