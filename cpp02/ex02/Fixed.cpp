#include "Fixed.hpp"

Fixed::Fixed(void): _fixedValue(0)
{
}

Fixed::Fixed(const Fixed & src)
{
    *this = src;
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(int const num)
{
    this->_fixedValue = num << this->_bits;
}

Fixed::Fixed(float const num)
{
    this->_fixedValue = roundf(num * (1 << this->_bits));
}

float   Fixed::toFloat(void) const
{
    //return (((float)(this->_fixedValue)) / 32768.0);
    //return (((float)(this->_fixedValue)) / 65536.0);
    //return ((float)(this->_fixedValue) / 16384.0);
    //return ((float)(this->_fixedValue) / 1073741824.0);
    return ((float)this->_fixedValue / (1 << this->_bits));
}

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
    if (this != &rhs)
        setRawBits(rhs.getRawBits());
    return (*this);
}

std::ostream &operator<<(std::ostream & o, const Fixed & i)
{
    o << i.toFloat();
    return (o);
}

//Ternary syntax: variable = (condition) ? expressionTrue : expressionFalse;
bool Fixed::operator>(const Fixed & rhs) const
{
    return ((getRawBits() > rhs.getRawBits()) ? true : false);
}

bool Fixed::operator<(const Fixed & rhs) const
{
    return ((getRawBits() < rhs.getRawBits()) ? true : false);
}

bool Fixed::operator<=(const Fixed & rhs) const
{
    return ((getRawBits() <= rhs.getRawBits()) ? true : false);
}

bool Fixed::operator>=(const Fixed & rhs) const
{
    return ((getRawBits() >= rhs.getRawBits()) ? true : false);
}

bool Fixed::operator==(const Fixed & rhs) const
{
    return ((getRawBits() == rhs.getRawBits()) ? true : false);
}

bool Fixed::operator!=(const Fixed & rhs) const
{
    return ((getRawBits() != rhs.getRawBits()) ? true : false);
}


Fixed Fixed::operator+(const Fixed & rhs)
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed & rhs)
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed & rhs)
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed & rhs)
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++(void)
{
    this->_fixedValue++;
 	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->_fixedValue--;
	return (*this);   
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp); 
}

Fixed &Fixed::min(Fixed &src1, Fixed &src2)
{
    return ((src1.getRawBits() <= src2.getRawBits()) ? src1 : src2);
}

const Fixed &Fixed::min(const Fixed &src1, const Fixed &src2)
{
    return ((src1.getRawBits() <= src2.getRawBits()) ? src1 : src2);
}

Fixed &Fixed::max(Fixed &src1, Fixed &src2)
{
    return ((src1.getRawBits() >= src2.getRawBits()) ? src1 : src2);
}

const Fixed &Fixed::max(const Fixed &src1, const Fixed &src2)
{
    return ((src1.getRawBits() >= src2.getRawBits()) ? src1 : src2);
}