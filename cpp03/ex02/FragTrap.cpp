#include "FragTrap.hpp"

//  Hit points (100), represent the health of the ClapTrap
// • Energy points (100)
// • Attack damage (30)

// FragTrap(void); //canonical
FragTrap::FragTrap(void): ClapTrap()
{
    std::cout << "A new FragTrap was created!" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

// FragTrap(const FragTrap &src); //canonical
FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
    std::cout << "A new FragTrap was created with the copy constructor!" << std::endl;
    *this = src;
}

// FragTrap(std::string name);
FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    
}

// ~FragTrap(void); //canonical

// FragTrap    &operator=(const FragTrap &src); //canonical
// void        highFivesGuys(void) const;