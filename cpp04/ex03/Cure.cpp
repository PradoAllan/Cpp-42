#include "Cure.hpp"

// Cure(void);
Cure::Cure(void): AMateria("cure") {}

// Cure(const Cure &src);
Cure::Cure(const Cure &src): AMateria(src)
{
    *this = src;
}

// ~Cure(void);
Cure::~Cure(void) {}

// Cure &operator=(const Cure &src);
Cure &Cure::operator=(const Cure &src)
{
    if (this != &src)
        AMateria::operator=(src);
    return (*this);
}

// virtual AMateria* clone() const;
AMateria* Cure::clone() const
{
    Cure *another = new Cure();
    return (another);
}
