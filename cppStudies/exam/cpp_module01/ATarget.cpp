#include "ATarget.hpp"
#include "ASpell.hpp"

// ATarget(std::string type);
ATarget::ATarget(std::string type)
{
    this->type = type;
}
// ~ATarget(void);
ATarget::~ATarget(void) {}

// const std::string &getType(void) const;
const std::string &ATarget::getType(void) const
{
    return (this->type);
}

// void getHitBySpell(const ASpell &src);
void ATarget::getHitBySpell(ASpell const &src) const
{
    std::cout << this->getType() << " has been " << src.getEffects() << "!" << std::endl;
}