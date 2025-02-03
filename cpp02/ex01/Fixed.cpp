#include "Fixed.hpp"

Fixed::Fixed(void): _fixedValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const num): _fixedValue(num)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const num): _fixedValue(num)
{
    std::cout << "Float constructor called" << std::endl;
}

//fixed to float
//((float)(a) / 32768.0)
float   Fixed::toFloat(void) const
{
    return ((float)(this->_fixedValue) / 32768.0);
}

//fixed to int
//((int))((a >> 15))
int Fixed::toInt(void) const
{
    return ((int)(this->_fixedValue >> this->_bits));
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
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        setRawBits(rhs.getRawBits());
    //this->_fixedValue = rhs.getRawBits();
    return (*this);
}