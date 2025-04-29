#include "BrickWall.hpp"

// BrickWall();
BrickWall::BrickWall(): ATarget("Inconspicuous Red-brick Wall") {}

// ~BrickWall();
BrickWall::~BrickWall() {}

// virtual ATarget *clone() const;
ATarget *BrickWall::clone() const
{
    return (new BrickWall());
}