#include "ASpell.hpp"

// ASpell(void);
ASpell::ASpell(void) {}
// ASpell(const ASpell &src);
ASpell::ASpell(const ASpell &src)
{
    *this = src;
}
// ASpell(const std::string &name, const std::string &effects);
ASpell::ASpell(const std::string &name, const std::string &effects)
{
    this->name = name;
    this->effects = effects;
}
// virtual ~ASpell(void);
ASpell::~ASpell(void) {}

// ASpell &operator=(const ASpell &src);
ASpell &ASpell::operator=(const ASpell &src)
{
    this->name = src.name;
    this->effects = src.effects;
    return (*this);
}

// std::string getName(void) const;
std::string ASpell::getName(void) const
{
    return (this->name);
}

// std::string getEffects(void) const;
std::string ASpell::getEffects(void) const
{
    return (this->effects);
}

// void launch(const ATarget &target);
void ASpell::launch(const ATarget &target) const
{
    target.getHitBySpell(*this);
}