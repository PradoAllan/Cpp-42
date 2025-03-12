#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

// ShrubberyCreationForm(void);
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Shrubbery", 145, 137), _target("Generic target") {}

// ShrubberyCreationForm(const ShrubberyCreationForm &src);
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src) {}

// ShrubberyCreationForm(std::string &target);
ShrubberyCreationForm::ShrubberyCreationForm(std::string &target): AForm("Shrubbery", 145, 137), _target(target)
{
    // TODO: Create a file <target>_shrubbery in the working directory, 
    //and writes ASCII trees inside it.
    std::string     newFileName = target + "_shrubbery";
    std::ofstream   newFile;

    newFile.open(newFileName.c_str(), std::ofstream::out);
    if (!newFile.is_open())
        throw ShrubberyCreationForm::OpeningFileError();
    newFile << "Oi" << std::endl;
    newFile << "    &&& &&  & &&   " << std::endl;
    newFile << "   && &\/&\|& ()|/ @, &&" << std::endl;
    newFile << "   &\/(/&/&||/& /_/)_&" << std::endl;
    newFile << " &() &\/&|()|/&\/ '%' &" << std::endl;
    newFile << "&_\/_&&_\ |& |&&/&__%_/" << std::endl;
    newFile << "   &&   ||| " << std::endl;
    newFile << "        ||| " << std::endl;
    newFile << "        ||| " << std::endl;
    newFile << "        ||| " << std::endl;
    newFile << "  , -=-~  .-^- _ " << std::endl; 
    newFile.close();
}

// ~ShrubberyCreationForm(void);
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src)
        AForm::operator=(src);
    return (*this);
}

const char * ShrubberyCreationForm::OpeningFileError::what() const throw()
{
    return ("Could not create the new file.");
}