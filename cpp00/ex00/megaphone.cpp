#include <iostream>

void    upperString(char *s)
{
    if (!s)
        return ;
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = toupper(s[i]);
}

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < ac; i++)
        {
            upperString(av[i]);
            std::cout << av[i];
        }
    }
    std::cout << std::endl;
    return (1);
}
