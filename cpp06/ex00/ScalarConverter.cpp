#include "ScalarConverter.hpp"
#include <iostream>

// ScalarConverter(void);
ScalarConverter::ScalarConverter(void) {}

// ScalarConverter(const ScalarConverter &src);
ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    *this = src;
}

// ~ScalarConverter(void);
ScalarConverter::~ScalarConverter(void) {}

// ScalarConverter operator=(const ScalarConverter &src);
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    if (this != &src)
        *this = src;
    return (*this);
}

// static void execChar(char value);
void ScalarConverter::execChar(char value)
{
    std::cout << "Casting Char to int: " << static_cast<int>(value) << std::endl;
    std::cout << "Casting Char to float: " << static_cast<float>(value) << std::endl;
    std::cout << "Casting Char to double: " << static_cast<double>(value) << std::endl;
}

// static void execInt(int value);
void ScalarConverter::execInt(int value)
{
    std::cout << "Casting Int to char: " << static_cast<char>(value) << std::endl;
    std::cout << "Casting Int to float: " << static_cast<float>(value) << std::endl;
    std::cout << "Casting Int to double: " << static_cast<double>(value) << std::endl;
}

// static void execFloat(float value);
void ScalarConverter::execFloat(float value)
{
    std::cout << "Casting Float to int: " << static_cast<int>(value) << std::endl;
    std::cout << "Casting Float to char: " << static_cast<char>(value) << std::endl;
    std::cout << "Casting Float to double: " << static_cast<double>(value) << std::endl;
}

// static void execDouble(double value);
void ScalarConverter::execDouble(double value)
{
    std::cout << "Casting Double to int: " << static_cast<int>(value) << std::endl;
    std::cout << "Casting Double to char: " << static_cast<char>(value) << std::endl;
    std::cout << "Casting Double to float: " << static_cast<float>(value) << std::endl;
}

// int checkDataType(std::string &s);
int ScalarConverter::checkDataType(std::string &s)
{
    const char *aux;

    if (s.empty())
        return (-1);
    aux = s.c_str();
    if (s.size() == 1 && !isdigit(aux[0]))
    {
        //call function isChar()
    }
    else if (s.find('.', 0) < s.size())
    {
    }
}

// static void convert(std::string &s);
void ScalarConverter::convert(std::string &s)
{

}
