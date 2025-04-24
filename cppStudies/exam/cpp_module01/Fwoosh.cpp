#include "Fwoosh.hpp"

// Fwoosh(void);
Fwoosh::Fwoosh(void): ASpell("Fwoosh", "fwooshed") {}

// Fwoosh(const Fwoosh &src);
Fwoosh::Fwoosh(const Fwoosh &src)
{
    *this = src;
}

// ~Fwoosh(void);
Fwoosh::~Fwoosh(void) {}

// Fwoosh &operator=(const Fwoosh &src);
// Fwoosh &Fwoosh::operator=(const Fwoosh &src)
// {
//     *this = src;
//     return (*this);
// }

ASpell *Fwoosh::clone(void) const
{
    return (new Fwoosh());
}