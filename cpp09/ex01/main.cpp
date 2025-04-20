#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "Wrong number of parameters." << std::endl, -1);
    RPN exec(av[1]);
    // RPN exec = RPN(av[1]);

    try
    {
        exec.execute();
        std::cout << "Result of the Reverse Polish Notation operation is: " << exec.getResult() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Input: " << av[1] << std::endl;

    return (0);
}