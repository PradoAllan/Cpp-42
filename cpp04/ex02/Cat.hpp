#pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
    private:
        Brain *brain;
    public:
        Cat(void); //canonical
        Cat(const Cat &src); //canonical

        ~Cat(void); //canonical

        Cat &operator=(const Cat &src); //canonical

        virtual void    makeSound(void) const;
};