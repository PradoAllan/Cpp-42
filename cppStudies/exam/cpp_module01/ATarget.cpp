#include "ATarget.hpp"

// ATarget(void);
ATarget::ATarget(void) {}

// ATarget(const ATarget &src);
ATarget::ATarget(const ATarget &src) {*this = src;}

// ATarget(const std::string &type);
ATarget::ATarget(const std::string &type): type(type) {}

// virtual ~ATarget(void);
ATarget::~ATarget(void) {}

// ATarget &operator=(const ATarget &src);
ATarget &ATarget::operator=(const ATarget &src)
{
    this->type = src.type;
    return (*this);
}

// const std::string &getType(void) const;
const std::string &ATarget::getType(void) const
{
    return (this->type);
}

// void getHitBySpell(const ASpell &target);
void ATarget::getHitBySpell(const ASpell &target) const
{
    std::cout << this->getType() << " has been " << target.getEffects() << "!" << std::endl;
}
