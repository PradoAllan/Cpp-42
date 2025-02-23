#pragma once

# include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        const std::string   _name;
        AMateria            *_inventory;
        int                 _i;

    public:
        Character(void);
        Character(const Character &src);
        ~Character(void);

        Character &operator=(const Character &src);

        // Métodos virtuais da interface.
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};