#pragma once

# include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat(void); //canonical
        Cat(const Cat &src); //canonical

        ~Cat(void); //canonical

        Cat &operator=(const Cat &src); //canonical

        void    makeSound(void) const;
};