#pragma once

#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
    private:
        std::string name;
        std::string title;
        SpellBook   map;
        // std::map<std::string, ASpell *> map;

        Warlock();
        Warlock(const Warlock &src);
        Warlock &operator=(const Warlock &src);
    public:
        ~Warlock();
        Warlock(const std::string &name, const std::string &title);

        const std::string &getName() const;
        const std::string &getTitle() const;

        void setTitle(const std::string &title);

        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string spell);
        void launchSpell(std::string name, ATarget &ref);
};
