#include "ScalarConverter.hpp"
#include "dataTypes.hpp"
#include <iostream>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    *this = src;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    if (this != &src)
        *this = src;
    return (*this);
}

void ScalarConverter::execChar(std::string &s)
{
    std::cout << "EXECCHAR()" << std::endl;
    const char *value;

    value = s.c_str();
    std::cout << "Casting Char to Int: " << static_cast<int>(value[0]) << std::endl;
    std::cout << "Casting Char to Float: " << static_cast<float>(value[0]) << std::endl;
    std::cout << "Casting Char to Double: " << static_cast<double>(value[0]) << std::endl;
}

void ScalarConverter::execInt(std::string &s)
{
    (void)s;
    std::cout << "EXECINT()" << std::endl;
}

void ScalarConverter::execFloat(std::string &s)
{
    (void)s;
    std::cout << "EXECFLOAT()" << std::endl;
}

void ScalarConverter::execDouble(std::string &s)
{
    (void)s;
    std::cout << "EXECDOUBLE()" << std::endl;
}

int ScalarConverter::checkDataType(std::string &s)
{
    const char  *aux;
    size_t        size;

    if (s.empty())
        return (ERROR);
    aux = s.c_str();
    size = s.size();
    if (size == 1 && !isdigit(aux[0]))
        return (CHAR);
    else if (s.find('.', 0) < size)
    {
        if (aux[size - 1] == 'f')
            return (FLOAT);
        else
            return (DOUBLE);
    }
    return (INT);
}

void ScalarConverter::convert(std::string &s)
{
    ScalarConverter aux;

    switch (aux.checkDataType(s))
    {
    case CHAR:
        aux.execChar(s);
        break;
    case INT:
        aux.execInt(s);
        break;
    case FLOAT:
        aux.execFloat(s);
        break;
    case DOUBLE:
        aux.execDouble(s);
        break;
    default:
        std::cerr << "Invalid dataType..." << std::endl;
        break;
    }
}
