#include "Cure.hpp"
#include <iostram>

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

// virtual void use(ICharacter& target);
void Cure::use(ICharacter& target)
{
    std::cout << "* heals <name>’s wounds *" << std::endl;
    // <name>'s the name of the character
}
