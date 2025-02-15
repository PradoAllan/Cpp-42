#pragma once

# include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal(void); //canonical
        Animal(const Animal &src); //canonical

        virtual ~Animal(void); //canonical

        Animal &operator=(const Animal &src); //canonical

        virtual void    makeSound(void) const;

        std::string     getType(void) const;
};