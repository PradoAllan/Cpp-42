#include "Zombie.hpp"

int main(void)
{
    Zombie me = Zombie("allan");
    //Zombie *newMe = Zombie::newZombie("prado");
    Zombie *newMe = newZombie("prado");

    std::cout << "Me is: " << me.get_name() << std::endl;
    me.announce();
    newMe->announce();
    delete(newMe);
    randomChump("silva");

    return (1);
}