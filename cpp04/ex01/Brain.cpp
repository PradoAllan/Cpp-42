#include "Brain.hpp"
#include <iostream>

std::string populateIdeas(int i)
{
    if (i < 20)
        return ("Hungry");
    else if (i < 40)
        return ("Pop");
    else if (i < 60)
        return ("Pee");
    else if (i < 80)
        return ("Walk");
    else
        return ("Sleep");
}

Brain::Brain(void)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = populateIdeas(i);
    std::cout << "A new Brain was created by the constructor." << std::endl;
}

Brain::Brain(const Brain &src)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
    std::cout << "A new Brain was created by the copy constructor." << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "A Brain got destroyed by the destructor." << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
    if (this != &src)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = src.ideas[i];
    }
    return (*this);
}
