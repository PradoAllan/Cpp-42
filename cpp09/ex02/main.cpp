#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac <= 2)
        return (std::cerr << "Error" << std::endl, -1);
    try
    {
        PmergeMe my(ac, av);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    

    return (0);
}