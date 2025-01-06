#include "Zombie.hpp"

int main(void)
{
    Zombie  allan;
    Zombie *z1 = allan.newZombie("z1"); // forma possivel.
    Zombie *z2 = Zombie::newZombie("z2"); // nao pode
    Zombie  *z3 = allan.randomChump("adaad"); // nao pode

    allan.set_name("Allan lindo");
    allan.announce();
    return (1);
}