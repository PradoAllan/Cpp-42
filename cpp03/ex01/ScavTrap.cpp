#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
    //ClapTrap();
    this->_attackDamage = 20;
    this->_energyPoints = 50;
    this->_hitPoints = 100;
    std::cout << "New robot got created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    //ClapTrap(name);
    this->_attackDamage = 20;
    this->_energyPoints = 50;
    this->_hitPoints = 100;
    std::cout << "New robot called " << name << " got created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
    *this = src;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "Robot got a virus and died..." << std::endl;
    //ClapTrap::~ClapTrap();
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    std::cout << "ScavTrap operator = got called." << std::endl;
    if (this != &src)
    {
        ClapTrap::operator=(src);
        //Nesse caso o operator do ClavTrap faz exatamente isso:
        // this->_attackDamage = src.getAttackDamage();
        // this->_energyPoints = src.getEnergyPoints();
        // this->_hitPoints = src.getHitPoints();
    }
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
    if (getEnergyPoints() > 0 && getHitPoints() > 0)
        std::cout << getName() << " is in Gate Keeper mode..." << std::endl;
    else
        std::cout << "Robot ScavTrap " << getName() << " has no Energy or Hit Points left..." << std::endl;
}