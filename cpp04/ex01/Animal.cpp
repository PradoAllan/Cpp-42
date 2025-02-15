#include "Animal.hpp"

Animal::Animal(void): _type("GENERIC")
{
    std::cout << "Animal base Constructor got called." << std::endl;
}

Animal::Animal(const Animal &src)
{
    std::cout << "Animal base copy constructor got called." << std::endl;
    *this = src;
}

Animal::~Animal(void)
{
    std::cout << "Animal base destructor got called." << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    std::cout << "Animal base assignment operator got called." << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

void    Animal::makeSound(void) const
{
    std::cout << this->_type << " is talking!!" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->_type);
}