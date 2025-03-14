#pragma once

# include "AForm.hpp"
# include <exception>

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ShrubberyCreationForm(const std::string &target);
        virtual ~ShrubberyCreationForm(void);

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

        void    execute(Bureaucrat const & executor) const;

        class OpeningFileError : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};