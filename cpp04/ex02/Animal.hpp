#pragma once

# include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        virtual void    makeSound(void) const = 0;
};