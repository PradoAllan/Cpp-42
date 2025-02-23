#include "Character.hpp"

// Character(void);
Character::Character(void) {}

// Character(const Character &src);
Character::Character(const Character &src)
{
    *this = src;
}

// ~Character(void);
Character::~Character(void) {}

// Character &operator=(const Character &src);
Character &Character::operator=(const Character &src)
{
    if (this != &src)
        // setter(getter());
    return (*this);
}

// Métodos virtuais da interface.
// virtual std::string const & getName() const = 0;
// virtual void equip(AMateria* m) = 0;
// virtual void unequip(int idx) = 0;
// virtual void use(int idx, ICharacter& target) = 0;