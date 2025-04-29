#pragma once

#include "ATarget.hpp"

class BrickWall: public ATarget
{
    private:

    public:
        BrickWall();
        ~BrickWall();

        virtual ATarget *clone() const;
};