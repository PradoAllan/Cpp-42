#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie  stackZombie;

    stackZombie.set_name(name);
    stackZombie.announce();
}
