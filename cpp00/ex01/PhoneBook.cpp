#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	set_counter(8);
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
	int		index = get_index();
	
	set_index(index + 1);
	//this->set_index(this->get_index() + 1);
}

void	PhoneBook::showAllContacts()
{
	int		counter = get_counter();

	std::cout << "PRINTING INSIDE SHOW ALL CONTACTS FUNC: " << counter << std::endl;
	for (int i = 0; i < counter; i++)
	{
		this->contacts[i].showAttributes();
		std::cout << std::endl;
	}
}

void	PhoneBook::addNewContact(std::string name, std::string lastName, std::string nickname, std::string darkestSecret, std::string phoneNumber)
{
	int		index = get_index();

	if (index == 8)
	{
		//std::cout << "No more room for another contact..." << std::endl;
		//std::cout << "Updating the first contact..." << std::endl;
		set_index(0);
		index = 0;
		//return ;
	}
	incrementIndex();
	this->contacts[index].set_name(name);
	this->contacts[index].set_lastName(lastName);
	this->contacts[index].set_nickname(nickname);
	this->contacts[index].set_darkestSecret(darkestSecret);
	this->contacts[index].set_phoneNumber(phoneNumber);
}

// Sample::Sample(void)
// {
// 	std::cout << "Constructor was called!" << std::endl;
// }

// Sample::~Sample(void)
// {
// 	std::cout << "Destructor was called!" << std::endl;
// }

// void	Sample::bar(void)
// {
// 	std::cout << "Method bar was called!" << std::endl;
// }

/*
Car::Car(char brand[], char model[], int year)
{
	brand = brand;
	model = model;
	year = year;
}
*/
