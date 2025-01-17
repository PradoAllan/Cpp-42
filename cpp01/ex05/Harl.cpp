#include "Harl.hpp"

Harl::Harl(void)
{

}

Harl::~Harl(void)
{

}

void    Harl::debug(void)
{
    std::cout << DEBUG_MESSAGE << std::endl;
}

void    Harl::info(void)
{
    std::cout << INFO_MESSAGE << std::endl;
}

void    Harl::warning(void)
{
    std::cout << WARNING_MESSAGE << std::endl;
}

void    Harl::error(void)
{
    std::cout << ERROR_MESSAGE << std::endl;
}

void    Harl::complain(std::string level)
{
    void(Harl::*funcPtr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int         len = level.length();

    for (int i = 0; i < len; i++)
        level[i] = toupper(level[i]);

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            (this->*funcPtr[i])();
    }
}