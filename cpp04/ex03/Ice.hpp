#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
    private:

    public:
        Ice(void);
        Ice(const Ice &src);
        ~Ice(void);

        Ice &operator=(const Ice &src);

        virtual AMateria* clone() const;
};