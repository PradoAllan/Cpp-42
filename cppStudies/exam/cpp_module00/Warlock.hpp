#pragma once

# include <string>
# include <iostream>

class Warlock
{
    private:
        std::string name;
        std::string title;

        Warlock(void);
        Warlock(const Warlock &src);
        Warlock &operator=(const Warlock &src);
    public:
        Warlock(std::string name, std::string title);
        ~Warlock(void);

        const std::string &getName(void) const;
        const std::string &getTitle(void) const;

        void setTitle(const std::string &title);

        void introduce(void) const;
};