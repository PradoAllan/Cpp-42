#include "PhoneBook.hpp"
#include "Contact.hpp"

void    stringToUpper(std::string &s)
{
    if (s.empty())
        return ;
    //if (!s)
    //   return ;
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = toupper(s[i]);
}

void    checkAndExecute(std::string option, PhoneBook &list)
{
    if (option.compare("ADD") == 0)
    {
        std::cout << "Add option..." << std::endl;
        list.addFunction();
    }
    else if (option.compare("SEARCH") == 0)
    {
        std::cout << "Search option..." << std::endl;
        list.showAllContacts();
    }
    else if (option.compare("EXIT") == 0)
        std::cout << "Exit option..." << std::endl;
    else
        std::cout << "Type only these options: ADD, EXIT or SEARCH." << std::endl;
}

int	main(void)
{
    PhoneBook   book;
    std::string option;

    do
    {
        std::cout << "Type your option: " << std::endl;
        std::cin >> option;
        stringToUpper(option);
        checkAndExecute(option, book);
    }
    while (option.compare("EXIT") != 0);
    book.showAllContacts();
	return (1);
}
