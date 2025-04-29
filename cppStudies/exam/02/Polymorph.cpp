#include "Polymorph.hpp"

// Polymorph();
Polymorph::Polymorph(): ASpell("Polymorph", "turned into a critter") {}

// ~Polymorph();
Polymorph::~Polymorph() {}

// virtual ASpell *clone() const;
ASpell *Polymorph::clone() const
{
    return (new Polymorph());
}