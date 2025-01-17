#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void    Contact::set_firstName(void)
{
    std::string firstName;

    do
    {
        std::cout << "Type your first name: ";
        std::getline(std::cin, firstName);
        this->firstName = firstName;
        if (firstName.empty())
            std::cout << "CAN NOT BE EMPTY." << std::endl;
    } while (firstName.empty());
}

void    Contact::set_lastName(void)
{
    std::string lastName;

    do
    {
        std::cout << "Type your last name: ";
        std::getline(std::cin, lastName);
        this->lastName = lastName;
        if (lastName.empty())
            std::cout << "CAN NOT BE EMPTY." << std::endl;
    } while (lastName.empty());
}

void    Contact::set_nickname(void)
{
    std::string nickname;

    do
    {
        std::cout << "Type your nickname: ";
        std::getline(std::cin, nickname);
        this->nickname = nickname;
        if (nickname.empty())
            std::cout << "CAN NOT BE EMPTY." << std::endl;
    } while (nickname.empty());
}

void    Contact::set_darkestSecret(void)
{
    std::string darkestSecret;

    do
    {
        std::cout << "Type your darkest secret: ";
        std::getline(std::cin, darkestSecret);
        this->darkestSecret = darkestSecret;
        if (darkestSecret.empty())
            std::cout << "CAN NOT BE EMPTY." << std::endl;
    } while (darkestSecret.empty());
}

void    Contact::set_phoneNumber(void)
{
    std::string phoneNumber;

    do
    {
        std::cout << "Type your phone number: ";
        std::getline(std::cin, phoneNumber);
        this->phoneNumber = phoneNumber;
        if (phoneNumber.empty())
            std::cout << "CAN NOT BE EMPTY." << std::endl;
    } while (phoneNumber.empty());
}

std::string Contact::get_firstName(void)
{
    return (this->firstName);
}

std::string Contact::get_lastName(void)
{
    return (this->lastName);
}

std::string Contact::get_nickname(void)
{
    return (this->nickname);
}

std::string Contact::get_darkestSecret(void)
{
    return (this->darkestSecret);
}

std::string Contact::get_phoneNumber(void)
{
    return (this->phoneNumber);
}

void    Contact::show_contact()
{
	std::cout << std::setw(10) << verifyLength(this->firstName) << "|";
	std::cout << std::setw(10) << verifyLength(this->lastName) << "|";
	std::cout << std::setw(10) << verifyLength(this->nickname) << "|" << std::endl;
}

void Contact::show_contact_full(void)
{
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone Number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
}

std::string Contact::verifyLength(const std::string &field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}
