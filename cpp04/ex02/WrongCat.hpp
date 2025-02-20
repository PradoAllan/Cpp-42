#pragma once

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat(void); //canonical
        WrongCat(const WrongCat &src); //canonical

        ~WrongCat(void); //canonical

        WrongCat &operator=(const WrongCat &src); //canonical

        void    makeSound(void) const;
};