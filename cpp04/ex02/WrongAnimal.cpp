#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("GENERIC")
{
    std::cout << "WrongAnimal base Constructor got called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    std::cout << "WrongAnimal base copy constructor got called." << std::endl;
    *this = src;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal base destructor got called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    std::cout << "WrongAnimal base assignment operator got called." << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << this->_type << " is talking!!" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}