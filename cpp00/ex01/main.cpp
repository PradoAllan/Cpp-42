#include "PhoneBook.hpp"

int main(void)
{
    int         status = 1;
    PhoneBook   list;
    std::string option;

    do
    {
        std::cout << std::endl;
        std::cout << "You have 3 options." << std::endl << "ADD, SEARCH or EXIT" << std::endl;
        std::cout << "Type your option: ";
        std::cin >> option;
        status = list.getting_option(option);
    } while (status);
    return (1);
}