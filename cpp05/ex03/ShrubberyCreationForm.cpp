#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Shrubbery", 145, 137), _target("Generic target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src)
        AForm::operator=(src);
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    std::string     newFileName = this->_target + "_shrubbery";
    std::ofstream   newFile;

    newFile.open(newFileName.c_str(), std::ofstream::out);
    if (!newFile.is_open())
        throw ShrubberyCreationForm::OpeningFileError();
    newFile << "      *      " << std::endl;
    newFile << "     ***     " << std::endl;
    newFile << "    *****    " << std::endl;
    newFile << "   *******   " << std::endl;
    newFile << "  *********  " << std::endl;
    newFile << " *********** " << std::endl;
    newFile << "*************" << std::endl;
    newFile << "      |      " << std::endl;
    newFile << "      |      " << std::endl;
    newFile.close();
}

const char * ShrubberyCreationForm::OpeningFileError::what() const throw()
{
    return ("Could not create the new file.");
}