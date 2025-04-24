#pragma once

# include <iostream>
# include <string>
# include "ATarget.hpp"
# include "ASpell.hpp"
# include <map>

class Warlock
{
    private:
        std::string         _name;
        std::string         _title;
        std::map<std::string, ASpell*>    _spells;

        Warlock(void);
        Warlock(const Warlock &src);
        Warlock &operator=(const Warlock &src);
    public:
        Warlock(const std::string &name, const std::string &title);
        ~Warlock(void);

        const std::string &getName(void) const;
        const std::string &getTitle(void) const;

        void        setTitle(const std::string &title);

        void introduce(void) const;

        void learnSpell(ASpell *aspell);
        void forgetSpell(std::string spellName);
        void launchSpell(std::string spellName, ATarget &ref);
};
