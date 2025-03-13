#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy", 72, 45), _target("Generic Target") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("Robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this != &src)
        AForm::operator=(src);
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    std::cout << "DrrrrrDrrrrrrDrrrrr..." << std::endl;
    if ((std::rand() % 2) == 0)
        std::cout << this->_target << " has been robotomized seccessfully!" << std::endl;
    else
        std::cout << "Unfortunately The robotomy failed..." << std::endl;
}