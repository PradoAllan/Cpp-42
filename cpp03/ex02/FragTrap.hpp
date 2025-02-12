#pragma once

#include "ClapTrap.hpp"

class   FragTrap: public ClapTrap
{
    public:
        FragTrap(void); //canonical
        FragTrap(const FragTrap &src); //canonical
        FragTrap(std::string name);

        ~FragTrap(void); //canonical

        FragTrap    &operator=(const FragTrap &src); //canonical
        void        highFivesGuys(void) const;
};