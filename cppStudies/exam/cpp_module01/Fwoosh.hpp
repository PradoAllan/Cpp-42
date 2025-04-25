#pragma once

# include "ASpell.hpp"

class Fwoosh : public ASpell
{
    private:

    public:
        Fwoosh(void);
        ~Fwoosh(void);

        virtual ASpell *clone(void) const;
};