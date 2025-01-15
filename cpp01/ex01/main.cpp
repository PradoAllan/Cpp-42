#include "Zombie.hpp"

int main(void)
{
    int     qtd = 10;
    Zombie  *horde = NULL;

    horde = zombieHorde(qtd, "allan");
    for (int i = 0; i < qtd; i++)
        horde[i].announce();
    delete[] horde;
    return (1);
}