#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon      *weapon;
    public:
        HumanB(void);
        HumanB(std::string name);
        ~HumanB(void);

        void    setName(std::string name);
        void    setWeapon(Weapon &ref);

        void    attack(void);

};

#endif