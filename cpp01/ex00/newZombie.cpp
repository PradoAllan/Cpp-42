#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
    Zombie  *anotherZombie = new Zombie();

    anotherZombie->set_name(name);
    //set_name(name);
    return (anotherZombie);
}