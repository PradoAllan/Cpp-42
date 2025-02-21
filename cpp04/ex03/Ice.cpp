#include "Ice.hpp"

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