#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon      weapon;
    public:
        HumanA(void);
        HumanA(std::string name, Weapon &ref);
        ~HumanA(void);

        void    setName(std::string name);


        void    attack(void);

};

#endif
