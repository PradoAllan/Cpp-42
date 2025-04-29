#include "ATarget.hpp"

// ATarget(const std::string &type);
ATarget::ATarget(const std::string &type)
{
    this->type = type;
}

// virtual ~ATarget();
ATarget::~ATarget() {}

// const std::string &getType() const;
const std::string &ATarget::getType() const {return (this->type);}

// void getHitBySpell(const ASpell &ref);
void ATarget::getHitBySpell(const ASpell &ref) const
{
    std::cout << getType() << " has been " << ref.getEffects() << "!" << std::endl;
}