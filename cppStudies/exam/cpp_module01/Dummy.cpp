#include "Dummy.hpp"

// Dummy(void);
Dummy::Dummy(void): ATarget("Target Practice Dummy") {}

// ~Dummy(void);
Dummy::~Dummy(void) {}

// virtual ATarget *clone(void) const;
ATarget *Dummy::clone(void) const
{
    return (new Dummy());
}