#pragma once

# include "AForm.hpp"

//TODO: Makes some drilling noises. Then, informs that <target> has been robotomized
//successfully 50% of the time. Otherwise, informs that the robotomy failed.

class RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm(std::string &target);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

        void    execute(Bureaucrat const & executor) const;
};