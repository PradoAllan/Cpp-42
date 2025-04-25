#pragma once

# include <string>
# include <iostream>
# include "ATarget.hpp"
# include "ASpell.hpp"
# include <map>

class Warlock
{
    private:
        std::string name;
        std::string title;
        std::map<std::string, ASpell *> arr;

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

        void learnSpell(ASpell *src);
        void forgetSpell(std::string spellsName);
        void launchSpell(std::string spellsName, ATarget &target);
};