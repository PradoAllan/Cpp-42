#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain *brain;
    public:
        Cat(void); //canonical
        Cat(const Cat &src); //canonical

        ~Cat(void); //canonical

        Cat &operator=(const Cat &src); //canonical

        void    makeSound(void) const;
};