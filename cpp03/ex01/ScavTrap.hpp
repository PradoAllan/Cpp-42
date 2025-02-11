#pragma once

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    private:

    public:
        ScavTrap(void); // canonical
        ScavTrap(const ScavTrap &src); // canonical
        ScavTrap(std::string name);
        ~ScavTrap(void); // canonical

        ScavTrap &operator=(const ScavTrap &src); // canonical
        
        void    attack(const std::string &target);
        void    guardGate(void) const;
};