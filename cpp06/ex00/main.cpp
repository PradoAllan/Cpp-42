#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string string = av[1];
        ScalarConverter::convert(string);
    }
    else
        std::cerr << "try smth like this: ./convert 42" << std::endl;
    return (0);
}