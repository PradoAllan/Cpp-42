#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->set_limit(3);
    this->set_index(0);
    std::cout << "Phonebook Constructor got called." << std::endl;
}
PhoneBook::~PhoneBook()
{
    std::cout << "Phonebook Destructor got called." << std::endl;
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

void    PhoneBook::add_function()
{
    int i = get_index();

    if (i >= get_limit())
        i = 0;
    contacts[i].set_firstName();
    contacts[i].set_lastName();
    contacts[i].set_nickname();
    contacts[i].set_darkestSecret();
    contacts[i].set_phoneNumber();
    set_index(i + 1);
    std::cout << "Add function was called." << std::endl;
}

void    PhoneBook::search_function()
{
    int info;
    int limit = get_limit();

    show_contacts();
    do
    {
        std::cout << std::endl;
        std::cout << "Which contact do you want to see more infos?" << std::endl;
        std::cout << "Type it's index: ";
        std::cin >> info;
        if (info >= limit || info < 0)
            std::cout << "INDEX OUT OF RANGE..." << std::endl;
    } while(info >= limit || info < 0);
    contacts[info].show_contact();
    std::cout << "Search function was called." << std::endl;
}

void    PhoneBook::show_contacts()
{
    int limit = get_limit();

    std::cout << "Show contacts was called." << std::endl;
    for (int i = 0; i < limit; i++)
    {
        std::cout << i;
        contacts[i].show_contact();
    }
}

int    PhoneBook::getting_option(std::string option)
{
    if (option.empty())
    {
        std::cout << "Type an option." << std::endl;
        return (1);
    }
    if (option == "ADD" || option == "add")
        add_function();
    else if (option == "SEARCH" || option == "search")
        search_function();
    else if (option == "EXIT" || option == "exit")
        return (0);
    else
        std::cout << "Wrong option..." << std::endl;
    return (1);
}

// int     PhoneBook::is_phonebook_empty(void)
// {
//     if (get_index() == 0)
//     {
//         std::cout << "There are no contacts in the phonebook... " << std::endl;
//         return (1);
//     }
//     return (0);
// }
