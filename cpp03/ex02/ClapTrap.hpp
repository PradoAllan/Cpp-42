#pragma once

# include <iostream>

class ClapTrap
{
    protected:
        const std::string   _name;
        int                 _hitPoints;
        int                 _energyPoints;
        int                 _attackDamage;
    public:
        ClapTrap(void); // cannonical
        ClapTrap(const ClapTrap &src); // cannonical
        ClapTrap(std::string name);
        ~ClapTrap(void); // cannonical

        ClapTrap &operator=(const ClapTrap &src); // cannonical

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        // getters
        std::string getName(void) const;
        int         getHitPoints(void) const;
        int         getEnergyPoints(void) const;
        int         getAttackDamage(void) const;
};