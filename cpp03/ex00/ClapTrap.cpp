#include "ClapTrap.hpp"

// ClapTrap(void);
// ClapTrap(const ClapTrap &src);
// ~ClapTrap(void);

// ClapTrap &operator=(const ClapTrap &src);

ClapTrap::ClapTrap(void): _name(" "), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Constructor got called." << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Constructor got called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    std::cout << "ClapTrap Constructor got called." << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor got called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    std::cout << "ClapTrap operator = got called." << std::endl;
    if (this != &src)
    {
        //this->_name = src._name;
        this->_hitPoints = src._hitPoints;
        this->_attackDamage = src._attackDamage;
        this->_energyPoints = src._energyPoints;
    }
    return (*this);
}

// void    attack(const std::string& target);
void    ClapTrap::attack(const std::string& target)
{
    if (getEnergyPoints() > 0 && getHitPoints() > 0)
    {
        std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    else
        std::cout << "ClapTrap " << getName() << " has no Energy or Hit Points left..." << std::endl;
}

// void    takeDamage(unsigned int amount);
void    ClapTrap::takeDamage(unsigned int amount)
{
    if (getHitPoints() > 0)
    {
        std::cout << "ClapTrap " << getName() << " got damaged. Lost " << amount << " points of helth." << std::endl;
        if (getHitPoints() > (int)amount)
            this->_hitPoints = amount;
        else
            this->_hitPoints = 0;
    }
    else
        std::cout << "Do not kick death ClapTraps..." << std::endl;
}

// void    beRepaired(unsigned int amount);
void    ClapTrap::beRepaired(unsigned int amount)
{
    if (getEnergyPoints() > 0 && getHitPoints() > 0)
    {
        std::cout << "ClapTrap " << getName() << " repaired itself with " << amount << " Hit points!" << std::endl;
        this->_hitPoints = amount;
        this->_energyPoints--;
    }
    else
        std::cout << "ClapTrap " << getName() << " has no Energy or Hit Points left..." << std::endl;
}

// GETTERS
//std::string getName(void) const;
std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

// int     getHitPoints(void) const;
int     ClapTrap::getHitPoints(void) const
{
    return (this->_hitPoints);
}

// int     getEnergyPoints(void) const;
int     ClapTrap::getEnergyPoints(void) const
{
    return (this->_energyPoints);
}

// int     getAttackDamage(void) const;
int     ClapTrap::getAttackDamage(void) const
{
    return (this->_attackDamage);
}
