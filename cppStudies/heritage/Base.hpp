#pragma once

# include <iostream>

class Base
{
    private:
        int _x, _y;
    public:
        Base();
        Base(int x, int y);
        ~Base();

        void print(void);
};