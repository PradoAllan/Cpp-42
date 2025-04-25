#include "Fwoosh.hpp"

// Fwoosh(void);
Fwoosh::Fwoosh(void): ASpell("Fwoosh", "fwooshed") {}
// ~Fwoosh(void);
Fwoosh::~Fwoosh(void) {}

// virtual ASpell *clone(void) const;
ASpell *Fwoosh::clone(void) const
{
    return (new Fwoosh());
}