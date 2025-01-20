#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name) {}

Zombie::~Zombie()
{
    std::cout << this->_name << " got destroyed..." << std::endl;
}

void    Zombie::set_name()
{
    std::string name;

    std::cout << "Type zombie name: ";
    std::cin >> name;
    this->_name = name;
}

void    Zombie::set_name(std::string name)
{
    this->_name = name;
}

std::string Zombie::get_name()
{
    return (this->_name);
}

void    Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}