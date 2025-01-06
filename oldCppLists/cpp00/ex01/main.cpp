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
        list.showFunction();
    }
    else if (option.compare("EXIT") == 0)
        std::cout << "Exit option..." << std::endl;
    else
        std::cout << "Type only these options: ADD, EXIT or SEARCH." << std::endl;
}

//###########################
//#       correct main      #
//###########################
int	main(void)
{
    PhoneBook   book;
    std::string option;

    do
    {
        std::cout << "Type your option: ADD, SEARCH or EXIT." << std::endl;
        std::cin >> option;
        stringToUpper(option);
        checkAndExecute(option, book);
    }
    while (option.compare("EXIT") != 0);
    book.showAllContacts();
	return (1);
}

/* int     main(void)
{
    Contact c1;

    c1.set_name("Allan");
    c1.set_lastName("Prado");
    c1.set_darkestSecret("adadadwwd");
    c1.set_nickname("aprado");
    c1.set_phoneNumber("987654321");
    c1.showAttributes();
} */
