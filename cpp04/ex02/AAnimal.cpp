#include "AAnimal.hpp"

AAnimal::AAnimal(void): _type("ABSTRACT")
{
    std::cout << "Abstract Animal base Constructor got called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
    std::cout << "Abstract Animal base copy constructor got called." << std::endl;
    *this = src;
}

AAnimal::~AAnimal(void)
{
    std::cout << "Abstract Animal base destructor got called." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
    std::cout << "Abstract Animal base assignment operator got called." << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

std::string AAnimal::getType(void) const
{
    return (this->_type);
}