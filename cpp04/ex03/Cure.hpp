#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
    private:

    public:
        Cure(void);
        Cure(const Cure &src);
        ~Cure(void);

        Cure &operator=(const Cure &src);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};