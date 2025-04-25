#include "ASpell.hpp"

// ASpell(std::string name, std::string effects);
ASpell::ASpell(std::string name, std::string effects)
{
    this->name = name;
    this->effects = effects;
}

// virtual ~ASpell(void);
ASpell::~ASpell(void) {}

// std::string getName(void);
const std::string &ASpell::getName(void) const {return (this->name);}

// std::string getEffects(void);
const std::string &ASpell::getEffects(void) const {return (this->effects);}

// void launch(const ATarget &src) const;
void ASpell::launch(ATarget const &src) const
{
    src.getHitBySpell(*this);
}