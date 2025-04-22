#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "Wrong number of parameters..." << std::endl, -1);

    BitcoinExchange btc(av[1]);

    btc.populateData();
    return (0);
}