#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat *bureaucrat = new Bureaucrat("John", 1);

        ShrubberyCreationForm *form = new ShrubberyCreationForm("home");

        bureaucrat->executeForm(*form);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}