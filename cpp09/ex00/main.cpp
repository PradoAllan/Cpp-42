#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "Error: could not open file." << std::endl, -1);
    try
    {
        BitcoinExchange btc(av[1]);
        btc.populateData();
        btc.readExecInput();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}