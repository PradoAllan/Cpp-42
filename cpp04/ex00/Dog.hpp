#pragma once

# include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog(void); //canonical
        Dog(const Dog &src); //canonical

        ~Dog(void); //canonical

        Dog &operator=(const Dog &src); //canonical

        void    makeSound(void) const;
};