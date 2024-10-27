#include "Zombie.hpp"

void    Zombie::randomChump(std::string name)
{
    Zombie  *anotherZombie = new Zombie();

    anotherZombie->set_name(name);
    anotherZombie->announce();
    delete(anotherZombie);
}