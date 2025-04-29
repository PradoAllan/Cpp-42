#pragma once

#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook
{
    private:
        std::map<std::string, ASpell *> map;

        SpellBook(const SpellBook &src);
        SpellBook &operator=(const SpellBook &src);
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string const &name);
        ASpell* createSpell(std::string const &name);
};