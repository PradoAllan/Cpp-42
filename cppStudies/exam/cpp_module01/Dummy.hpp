#pragma once

# include "ATarget.hpp"

class Dummy : public ATarget
{
    private:

    public:
        Dummy(void);
        ~Dummy(void);

        virtual ATarget *clone(void) const;
};