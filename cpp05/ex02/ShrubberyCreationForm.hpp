#pragma once

# include "AForm.hpp"
# include <exception>

// TODO: Create a file <target>_shrubbery in the working directory, 
//and writes ASCII trees inside it.
class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ShrubberyCreationForm(std::string &target);
        ~ShrubberyCreationForm(void);

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

        // virtual void    execute(Bureaucrat const & executor);

        class OpeningFileError : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};