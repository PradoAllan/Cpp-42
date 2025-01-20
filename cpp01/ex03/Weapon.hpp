#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string.h>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon(void);
        Weapon(std::string type);
        ~Weapon(void);

        void    setType(std::string name);
        std::string   getType(void) const;
};

#endif