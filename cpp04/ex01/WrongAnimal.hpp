#pragma once

# include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal(void); //canonical
        WrongAnimal(const WrongAnimal &src); //canonical

        ~WrongAnimal(void); //canonical

        WrongAnimal &operator=(const WrongAnimal &src); //canonical

        void    makeSound(void) const;

        std::string     getType(void) const;
};