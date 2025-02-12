#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "A new FragTrap was created!" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "A new FragTrap named " << name << " was created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
    std::cout << "A new FragTrap was created with the copy constructor!" << std::endl;
    *this = src;
}

FragTrap::~FragTrap(void)
{
    std::cout << getName() << " FragTrap got destroyed..." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    if (this != &src)
        ClapTrap::operator=(src);
    return (*this);
}

void    FragTrap::highFivesGuys(void) const
{
    std::cout << "Hi i'm FragTrap " << getName() << " give me a HighFive!!!" << std::endl;
}