#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
    this->_attackDamage = 20;
    this->_energyPoints = 50;
    this->_hitPoints = 100;
    std::cout << "New robot got created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->_attackDamage = 20;
    this->_energyPoints = 50;
    this->_hitPoints = 100;
    std::cout << "New robot called " << name << " got created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
    std::cout << "New robot got created by the copy constructor!" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "Robot got a virus and died..." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    std::cout << "ScavTrap operator = got called." << std::endl;
    if (this != &src)
        ClapTrap::operator=(src);
    return (*this);
}

void    ScavTrap::attack(const std::string &target)
{
    if (getEnergyPoints() > 0 && getHitPoints() > 0)
    {
        std::cout << "Robot ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    else
        std::cout << "Robot ScavTrap " << getName() << " has no Energy or Hit Points left..." << std::endl;
}

void    ScavTrap::guardGate(void) const
{
    if (getHitPoints() > 0)
        std::cout << getName() << " is in Gate Keeper mode..." << std::endl;
    else
        std::cout << "Robot ScavTrap " << getName() << " has no Energy or Hit Points left..." << std::endl;
}
