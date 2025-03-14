#pragma once

# include <string>
# include "AForm.hpp"

class Intern
{
    private:

    public:
        Intern(void);
        Intern(const Intern &src);
        ~Intern(void);

        AForm *makeForm(std::string formName, std::string target);

        Intern &operator=(const Intern &src);

        class WrongNameForm : public std::exception
        {
            public:
                const char *what() const throw();
        };
};