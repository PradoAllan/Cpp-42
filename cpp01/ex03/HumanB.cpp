#include "HumanB.hpp"

HumanB::HumanB(void)
{

}

HumanB::HumanB(std::string name)
{
    setName(name);
}

HumanB::~HumanB(void)
{

}

void    HumanB::setName(std::string name)
{
    this->name = name;
}

void    HumanB::setWeapon(Weapon &ref)
{
    this->weapon = &ref;
}

void    HumanB::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}