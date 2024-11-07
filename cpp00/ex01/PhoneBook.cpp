#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	set_counter(3);
	set_index(0);
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::set_counter(int counter)
{
	this->counter = counter;
}

void	PhoneBook::set_index(int index)
{
	this->index = index;
}

int		PhoneBook::get_counter()
{
	return (this->counter);
}

int		PhoneBook::get_index()
{
	return (this->index);
}

void	PhoneBook::incrementIndex()
{
	// int		index = get_index();
	
	// set_index(index + 1);
	set_index(get_index() + 1);
}

void	PhoneBook::showAllContacts()
{
	int		counter = get_counter();

	for (int i = 0; i < counter; i++)
	{
		this->contacts[i].showAttributes();
		std::cout << std::endl;
	}
}

void	PhoneBook::addNewContact(std::string name, std::string lastName, std::string nickname, std::string darkestSecret, std::string phoneNumber)
{
	int		index = get_index();

	if (index == 3)
	{
		set_index(0);
		index = 0;
	}
	incrementIndex();
	this->contacts[index].set_name(name);
	this->contacts[index].set_lastName(lastName);
	this->contacts[index].set_nickname(nickname);
	this->contacts[index].set_darkestSecret(darkestSecret);
	this->contacts[index].set_phoneNumber(phoneNumber);
}

void	PhoneBook::addFunction()
{
	int		index = get_index();
	std::string name;
    std::string lastName;
    std::string nickname;
    std::string darkestSecret;
    std::string phoneNumber;

	std::cout << "Type the contact's Name: "<< std::endl;
	std::cin >> name;
	std::cout << "Type the contact's Nast Name: " << std::endl;
	std::cin >> lastName;
	std::cout << "Type the contact's Nickname: " << std::endl;
	std::cin >> nickname;
	std::cout << "Type the contact's Darkest Secret: " << std::endl;
	std::cin >> darkestSecret;
	std::cout << "Type the contact's Phone Number: " << std::endl;
	std::cin >> phoneNumber;
	if (index == 3)
	{
		set_index(0);
		index = 0;
	}
	incrementIndex();
	this->contacts[index].set_name(name);
	this->contacts[index].set_lastName(lastName);
	this->contacts[index].set_nickname(nickname);
	this->contacts[index].set_darkestSecret(darkestSecret);
	this->contacts[index].set_phoneNumber(phoneNumber);
}

void	PhoneBook::searchFunction()
{
	int		index = get_index();
	int		toShow;

	this->showAllContacts();
	std::cout << "Type the INDEX of the contact you want: " << std::endl;
	std::cin >> toShow;
	if (toShow < index)
		this->contacts[toShow].showAttributes();
	else
		std::cout << "INDEX not valid..." << std::endl;
}

void	PhoneBook::showFunction()
{
	int limit = get_counter();
	int	toShow= 0;

	if (limit == 0)
	{
		std::cout << "No contacts found... Try to ADD one!" << std::endl;
		return ;
	}
	std::cout << "|  index   |first name|last name | nickname |" << std::endl;
	for (int i = 0; i < limit; i++)
	{
		this->contacts[i].showAttributes();
	}
	std::cout << "Type the INDEX of the contact you want: " << std::endl;
	std::cin >> toShow;
	if (toShow < limit)
	{
		std::cout << "|  index   |first name|last name | nickname |" << std::endl;
		this->contacts[toShow].showAttributes();
	}
	else
		std::cout << "INDEX NOT VALID..." << std::endl;
}