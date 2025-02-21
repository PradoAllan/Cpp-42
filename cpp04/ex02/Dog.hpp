#pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
    private:
        Brain *brain;
    public:
        Dog(void); //canonical
        Dog(const Dog &src); //canonical

        ~Dog(void); //canonical

        Dog &operator=(const Dog &src); //canonical

        virtual void    makeSound(void) const;
};