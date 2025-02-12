#pragma once

# include <iostream>

class ClapTrap
{
    // private:
    //     const std::string   _name;
    //     int                 _hitPoints;
    //     int                 _energyPoints;
    //     int                 _attackDamage;
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

// It will be called ClapTrap and will have the following private attributes initialized
// to the values specified in brackets:
// • Name, which is passed as parameter to a constructor
// • Hit points (10), represent the health of the ClapTrap
// • Energy points (10)
// • Attack damage (0)
// Add the following public member functions so the ClapTrap looks more realistic:
// • void attack(const std::string& target);
// • void takeDamage(unsigned int amount);
// • void beRepaired(unsigned int amount);