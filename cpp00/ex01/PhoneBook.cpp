#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "Constructor got called." << std::endl;
}
PhoneBook::~PhoneBook()
{
    std::cout << "Destructor got called." << std::endl;
}

void    PhoneBook::set_index(int index)
{
    this->index = index;
}

void    PhoneBook::set_limit(int limit)
{
    this->limit = limit;
}

int PhoneBook::get_index()
{
    return (this->index);
}

int PhoneBook::get_limit()
{
    return (this->limit);
}

// void    PhoneBook::add_function()
// {

// }

// void    PhoneBook::search_function()
// {

// }

// void    PhoneBook::show_contacts()
// {

// }
