#include "Contact.hpp"

Contact::Contact(void)
{
    std::cout << "Constructor got called." << std::endl;
}

Contact::~Contact(void)
{
    std::cout << "Desctructor got called." << std::endl;
}

void    Contact::set_firstName(std::string firstName)
{
    this->firstName = firstName;
}

void    Contact::set_lastName(std::string lastName)
{
    this->lastName = lastName;
}

void    Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void    Contact::set_darkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}

void    Contact::set_phoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
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
    std::cout << get_firstName() << get_lastName() << get_nickname() << get_darkestSecret() << get_phoneNumber() << std::endl;
}