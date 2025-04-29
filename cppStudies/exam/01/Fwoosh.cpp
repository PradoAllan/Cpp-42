#include "Fwoosh.hpp"

// Fwoosh();
Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed") {}

// ~Fwoosh();
Fwoosh::~Fwoosh() {}

// virtual ASpell *clone() const;
ASpell *Fwoosh::clone() const
{
    return (new Fwoosh());
}