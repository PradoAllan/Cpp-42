#include "Zombie.hpp"

int main(void)
{
    Zombie me;
    Zombie *newMe = newZombie("prado");

    me.set_name();
    std::cout << "Me is: " << me.get_name() << std::endl;
    me.announce();
    newMe->announce();
    delete(newMe);
    randomChump("silva");

    return (1);
}