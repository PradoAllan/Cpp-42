#include "Weapon.hpp"

Weapon::Weapon(void)
{
    std::cout << "A Weapon was created." << std::endl;
}

Weapon::Weapon(std::string type)
{
    setType(type);
}

Weapon::~Weapon(void)
{
    std::cout << "A Weapon got destroyed." << std::endl;
}

// member function that sets type using the new one passed as parameter.
void    Weapon::setType(std::string type)
{
    this->type = type;
}

// member function that returns a const reference to type.
std::string   Weapon::getType(void) const
{
    const std::string ref = this->type;
    return (ref);
}