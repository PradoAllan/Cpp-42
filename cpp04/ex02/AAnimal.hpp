#pragma once

# include <iostream>

class AAnimal
{
    protected:
        std::string _type;
    public:
        AAnimal(void); //canonical
        AAnimal(const AAnimal &src); //canonical

        virtual ~AAnimal(void); //canonical

        AAnimal &operator=(const AAnimal &src); //canonical

        virtual void    makeSound(void) const = 0;

        std::string     getType(void) const;
};