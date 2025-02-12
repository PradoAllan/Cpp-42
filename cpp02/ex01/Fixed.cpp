#include "Fixed.hpp"

Fixed::Fixed(void): _fixedValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const num)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedValue = num << this->_bits;
}

Fixed::Fixed(float const num)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedValue = roundf(num * (1 << this->_bits));
}

//fixed to float
//((float)(a) / 32768.0)
float   Fixed::toFloat(void) const
{
    //return (((float)(this->_fixedValue)) / 32768.0);
    //return (((float)(this->_fixedValue)) / 65536.0);
    //return ((float)(this->_fixedValue) / 16384.0);
    //return ((float)(this->_fixedValue) / 1073741824.0);
    return ((float)this->_fixedValue / (1 << this->_bits));
}

//fixed to int
//((int))((a >> 15))
//o 15 pode ser alterado de acordo com as necessidades
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

Fixed &Fixed::operator=(const Fixed & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        setRawBits(rhs.getRawBits());
    //this->_fixedValue = rhs.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream & o, const Fixed & i)
{
    o << i.toFloat();
    return (o);
}
