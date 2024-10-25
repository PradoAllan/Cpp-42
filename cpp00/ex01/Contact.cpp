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

void    set_name(std::string name)
{
    this->name = name;
}

void    set_lastName(std::string lastName)
{
    this->lastName = lastName;
}

void    set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void    set_darkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}

void    set_phoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

std::string get_name(std::string name)
{
    return (this->name);
}

std::string get_lastName(std::string lastName)
{
    return (this->lastName);
}

std::string get_nickname(std::string nickname)
{
    return (this->nickname);
}

std::string get_darkestSecret(std::string darkestSecret)
{
    return (this->darkestSecret);
}

std::string get_phoneNumber(std::string phoneNumber)
{
    return (this->phoneNumber);
}