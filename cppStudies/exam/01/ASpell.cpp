#include "ASpell.hpp"

// ASpell(const std::string &name, const std::string &effects);
ASpell::ASpell(const std::string &name, const std::string &effects)
{
    this->name = name;
    this->effects = effects;
}

// virtual ~ASpell();
ASpell::~ASpell() {}

// const std::string &getName() const;
const std::string &ASpell::getName() const {return (this->name);}

// const std::string &getEffects() const;
const std::string &ASpell::getEffects() const {return (this->effects);}

// void launch(const ATarget &ref);
void ASpell::launch(const ATarget &ref)
{
    ref.getHitBySpell(*this);
}