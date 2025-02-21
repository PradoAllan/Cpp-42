#include "Ice.hpp"
#include <iostream>

// Ice(void);
Ice::Ice(void): AMateria("ice") {}

// Ice(const Ice &src);
Ice::Ice(const Ice &src): AMateria(src)
{
    *this = src;
}

// ~Ice(void);
Ice::~Ice(void) {}

// Ice &operator=(const Ice &src);
Ice &Ice::operator=(const Ice &src)
{
    if (this != &src)
        AMateria::operator=(src);
    return(*this);
}

// virtual AMateria* clone() const;
AMateria* Ice::clone() const
{
    Ice *another = new Ice();
    return (another);
}

// virtual void use(ICharacter& target);
void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at <name> *" << std::endl;
    // <name> is the character name.
}
