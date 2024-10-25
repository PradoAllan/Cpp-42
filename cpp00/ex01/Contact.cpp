#include "Contact.hpp"

Contact::Contact(void)
{
    this->name = "|";
    this->lastName = "|";
    this->nickname = "|";
    this->darkestSecret = "|";
    this->phoneNumber = "|";
}

Contact::~Contact(void) {}

void    Contact::set_name(std::string name)
{
    this->name = name;
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

std::string Contact::get_name()
{
    return (this->name);
}

std::string Contact::get_lastName()
{
    return (this->lastName);
}

std::string Contact::get_nickname()
{
    return (this->nickname);
}

std::string Contact::get_darkestSecret()
{
    return (this->darkestSecret);
}

std::string Contact::get_phoneNumber()
{
    return (this->phoneNumber);
}

void    Contact::showAttributes()
{
    std::cout << this->name << std::endl;
    std::cout << this->lastName << std::endl;
    std::cout << this->nickname << std::endl;
    std::cout << this->darkestSecret << std::endl;
    std::cout << this->phoneNumber << std::endl;
}