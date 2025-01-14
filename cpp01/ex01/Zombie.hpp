#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class   Zombie
{
    private:
        std::string name;

    public:
        Zombie(void);
        ~Zombie(void);

        void    set_name(void);
        void    set_name(std::string name);

        std::string get_name(void);

        void    announce(void);

};

Zombie* zombieHorde(int N, std::string name);

#endif