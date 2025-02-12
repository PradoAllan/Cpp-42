#include "Base.hpp"

// base();
// base(int x, int y);
// ~base();

Base::Base(void): _x(0), _y(0) {}

Base::Base(int x, int y): _x(x), _y(y) {}

Base::~Base(void) {}

void Base::print(void)
{
    std::cout << this->_x << " " << this->_y << std::endl;
}