#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
    private:
        Brain *brain;
    public:
        Dog(void); //canonical
        Dog(const Dog &src); //canonical

        ~Dog(void); //canonical

        Dog &operator=(const Dog &src); //canonical

        void    makeSound(void) const;
};