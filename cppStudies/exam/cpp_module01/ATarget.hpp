#pragma once

#include <string>
#include <iostream>

class ASpell;

class ATarget
{
    private:
        std::string type;

    public:
        ATarget(std::string type);
        virtual ~ATarget(void);
        const std::string &getType(void) const;

        void getHitBySpell(ASpell const &src) const;

        virtual ATarget *clone(void) const = 0;
};

#include "ASpell.hpp"