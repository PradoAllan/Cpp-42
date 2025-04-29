#include "Fireball.hpp"

// Fireball();
Fireball::Fireball(): ASpell("Fireball", "burnt to a crisp") {}
// ~Fireball();
Fireball::~Fireball() {}

// virtual ASpell *clone() const;
ASpell *Fireball::clone() const
{
    return (new Fireball());
}