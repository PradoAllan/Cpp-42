#pragma once

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm(const std::string &target);
        virtual ~RobotomyRequestForm(void);

        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

        void    execute(Bureaucrat const & executor) const;
};