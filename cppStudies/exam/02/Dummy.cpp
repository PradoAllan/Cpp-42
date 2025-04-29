#include "Dummy.hpp"

// Dummy();
Dummy::Dummy(): ATarget("Target Practice Dummy") {}

// ~Dummy();
Dummy::~Dummy() {}

// virtual ATarget *clone() const;
ATarget *Dummy::clone() const
{
    return (new Dummy());
}