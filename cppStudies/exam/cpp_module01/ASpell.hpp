#pragma once

#include <string>
#include <iostream>

class ATarget;

class ASpell
{
    private:
        std::string name;
        std::string effects;

    public:
        ASpell(std::string name, std::string effects);
        virtual ~ASpell(void);

        const std::string &getName(void) const;
        const std::string &getEffects(void) const;

        virtual ASpell *clone(void) const = 0;

        void launch(ATarget const &src) const;
};

#include "ATarget.hpp"