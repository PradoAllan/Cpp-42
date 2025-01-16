#include "utils.hpp"

void    errorsDealer(std::string message)
{
    if (message.empty())
        std::cerr << NO_MESSAGE << std::endl;
    else
        std::cerr << message << std::endl;
}