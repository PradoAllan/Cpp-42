#pragma once

# include <string>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain(void); //canonical
        Brain(const Brain &src); //canonical

        ~Brain(void); //canonical

        Brain &operator=(const Brain &src); //canonical
};