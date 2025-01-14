#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " got destroyed..." << std::endl;
}

void    Zombie::set_name()
{
    std::string name;

    std::cout << "Type the zombie name: ";
    std::cin >> name;
    this->name = name;
}

void    Zombie::set_name(std::string name)
{
    this->name = name;   
}

std::string Zombie::get_name()
{
    return (this->name);
}

void    Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}