#include "Contact.hpp"

Contact::Contact(void)
{
    std::cout << "Contact Constructor got called." << std::endl;
}

Contact::~Contact(void)
{
    std::cout << "Contact Desctructor got called." << std::endl;
}

void    Contact::set_firstName(void)
{
    std::string firstName;

    std::cout << std::endl;
    std::cout << "Type your first name: ";
    std::cin >> firstName;
    this->firstName = firstName;
}

void    Contact::set_lastName(void)
{
    std::string lastName;

    std::cout << std::endl;
    std::cout << "Type your last name: ";
    std::cin >> lastName;
    this->lastName = lastName;
}

void    Contact::set_nickname(void)
{
    std::string nickname;

    std::cout << std::endl;
    std::cout << "Type your nickname: ";
    std::cin >> nickname;
    this->nickname = nickname;
}

void    Contact::set_darkestSecret(void)
{
    std::string darkestSecret;

    std::cout << std::endl;
    std::cout << "Type your darkest secret: ";
    std::cin >> darkestSecret;
    this->darkestSecret = darkestSecret;
}

void    Contact::set_phoneNumber(void)
{
    std::string phoneNumber;

    std::cout << std::endl;
    std::cout << "Type your phone number: ";
    std::cin >> phoneNumber;
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