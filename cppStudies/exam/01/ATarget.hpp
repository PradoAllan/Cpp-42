#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    private:
        std::string type;
    public:
        ATarget(const std::string &type);
        virtual ~ATarget();
        const std::string &getType() const;

        virtual ATarget *clone() const = 0;
        void getHitBySpell(const ASpell &ref) const;
};