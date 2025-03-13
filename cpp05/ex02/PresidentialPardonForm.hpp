#pragma once

# include "AForm.hpp"
# include <string>

//TODO: Informs that <target> has been pardoned by Zaphod Beeblebrox.
class PresidentialPardonForm : public AForm
{
    private:
        const std::string _target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm(std::string &target);
        virtual ~PresidentialPardonForm(void);

        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

        void    execute(Bureaucrat const & executor) const;
};