#pragma once

#include "ASpell.hpp"

class Polymorph : public ASpell
{
    private:

    public:
        Polymorph();
        ~Polymorph();

        virtual ASpell *clone() const;
};