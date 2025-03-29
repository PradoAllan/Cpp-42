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
    std::cout << "Casting value to Char: " << static_cast<char>(value[0]) << std::endl;
    std::cout << "Casting value to Int: " << static_cast<int>(value[0]) << std::endl;
    std::cout << "Casting value to Float: " << static_cast<float>(value[0]) << std::endl;
    std::cout << "Casting value to Double: " << static_cast<double>(value[0]) << std::endl;
}

static bool CharLimit(char value)
{
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
	{
		std::cout << "Casting value to Char: impossible" << std::endl;
		return (1);
	}
	return (0);
}

void ScalarConverter::execInt(std::string &s)
{
    std::cout << "EXECINT()" << std::endl;
    int value;

    value = atoi(s.c_str());

    if (!CharLimit(value))
    {
        if (isprint(value))
            std::cout << "Casting value to Char: " << static_cast<char>(value) << std::endl;
        else
            std::cout << "Casting value to Char: Not printable" << std::endl;
    }
    std::cout << "Casting value to Int: " << value << std::endl;
    std::cout << "Casting value to Float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "Casting value to Double: " << static_cast<double>(value) << std::endl;
}

static bool IntLimit(int value)
{
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	{
		std::cout << "Casting value to Int: impossible" << std::endl;
		return (1);
	}
	return (0);
}

void ScalarConverter::execFloat(std::string &s)
{
    std::cout << "EXECFLOAT()" << std::endl;
    float value;
    
    value = atof(s.c_str());
    //check pdf for the science part...
    //if (science())
    //    return ;
    if (!CharLimit(value))
    {
        if (isprint(static_cast<char>(value)))
            std::cout << "Casting value to Char: " << static_cast<char>(value) << std::endl;
        else
            std::cout << "Casting value to Char: Not printable" << std::endl;
    }
    if (!IntLimit(value))
        std::cout << "Casting value to Int: " << static_cast<int>(value) << std::endl;
    std::cout << "Casting value to Float: " << value << "f" << std::endl;
    std::cout << "Casting value to Double: " << static_cast<double>(value) << std::endl;
}

static bool FloatLimit(float value)
{
    if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
	{
		std::cout << "Casting value to Float: impossible" << std::endl;
		return (1);
	}
	return (0);
}

void ScalarConverter::execDouble(std::string &s)
{
    std::cout << "EXECDOUBLE()" << std::endl;
    double value;

    value = atof(s.c_str());
    // if(science())
    //  return ;
    if (!CharLimit(value))
    {
        if (isprint(static_cast<char>(value)))
            std::cout << "Casting value to Char: " << static_cast<char>(value) << std::endl;
        else
            std::cout << "Casting value to Char: Not printable" << std::endl;
    }
    if (!IntLimit(value))
        std::cout << "Casting value to Int: " << static_cast<int>(value) << std::endl;
    if (!FloatLimit(value))
        std::cout << "Casting value to Float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "Casting value to Double: " << value << std::endl;
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
