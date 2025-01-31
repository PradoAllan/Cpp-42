#include "Fixed.hpp"

// Fixed(void);                            
// Fixed(Fixed const & src);               
// ~Fixed(void);                           

// int     getRawBits(void) const;
// void    setRawBits(int const raw);

// Fixed &operator=(Fixed const & rhs); 

Fixed::Fixed(void): _fixedValue(0) {}

Fixed::Fixed(Fixed const & src)
{
    *this = src;
}

Fixed::~Fixed(void)
{

}

int Fixed::getRawBits(void) const
{
    return (this->_fixedValue);
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixedValue = raw;
}

Fixed &Fixed::operator=(Fixed const & rhs)
{
    if (this != &rhs)
        setRawBits(rhs.getRawBits());
    //this->_fixedValue = rhs.getRawBits();
    return (*this);
}