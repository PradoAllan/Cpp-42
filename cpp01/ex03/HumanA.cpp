#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon &ref): name(name), weapon(ref) {}
/* {
    setName(name);
    this->weapon = &ref;
} */

HumanA::~HumanA(void)
{

}

void    HumanA::setName(std::string name)
{
    this->name = name;
}

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}