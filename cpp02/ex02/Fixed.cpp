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

Fixed &Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        setRawBits(rhs.getRawBits());
    //this->_fixedValue = rhs.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream & o, Fixed const & i)
{
    o << i.toFloat();
    return (o);
}

//Ternary syntax: variable = (condition) ? expressionTrue : expressionFalse;
// Fixed &operator>(Fixed const & rhs);
bool Fixed::operator>(Fixed const & rhs) const
{
    // if (getRawBits() > rhs.getRawBits())
    //     return (true);
    // return (false);
    return ((getRawBits() > rhs.getRawBits()) ? true : false);
    //return ((getRawBits() > rhs.getRawBits()));
}

// Fixed &operator<(Fixed const & rhs);
bool Fixed::operator<(Fixed const & rhs) const
{
    // if (getRawBits() < rhs.getRawBits())
    //     return (true);
    // return (false);
    return ((getRawBits() < rhs.getRawBits()) ? true : false);
    //return ((getRawBits() < rhs.getRawBits()));
}

// Fixed &operator<=(Fixed const & rhs);
bool Fixed::operator<=(Fixed const & rhs) const
{
    // if (getRawBits() <= rhs.getRawBits())
    //     return (true);
    // return (false);
    return ((getRawBits() <= rhs.getRawBits()) ? true : false);
    //return ((getRawBits() <= rhs.getRawBits()));
}

// Fixed &operator>=(Fixed const & rhs);
bool Fixed::operator>=(Fixed const & rhs) const
{
    // if (getRawBits() >= rhs.getRawBits())
    //     return (true);
    // return (false);
    return ((getRawBits() >= rhs.getRawBits()) ? true : false);
    //return ((getRawBits() >= rhs.getRawBits()));
}

// Fixed &operator==(Fixed const & rhs);
bool Fixed::operator==(Fixed const & rhs) const
{
    // if (getRawBits() == rhs.getRawBits())
    //     return (true);
    // return (false);
    return ((getRawBits() == rhs.getRawBits()) ? true : false);
    //return ((getRawBits() == rhs.getRawBits()));
}

// Fixed &operator!=(Fixed const & rhs);
bool Fixed::operator!=(Fixed const & rhs) const
{
    // if (getRawBits() != rhs.getRawBits())
    //     return (true);
    // return (false);
    return ((getRawBits() != rhs.getRawBits()) ? true : false);
   // return ((getRawBits() != rhs.getRawBits()));
}


// Fixed &operator+(Fixed const & rhs);
Fixed &Fixed::operator+(Fixed const & rhs)
{
    Fixed new = Fixed(getRawBits() + rhs.getRawBits())
    return (&new);
}

// Fixed &operator-(Fixed const & rhs);
Fixed &Fixed::operator-(Fixed const & rhs)
{
    Fixed new = Fixed(getRawBits() - rhs.getRawBits())
    return (&new);
}

// Fixed &operator*(Fixed const & rhs);
Fixed &Fixed::operator*(Fixed const & rhs)
{
    Fixed new = Fixed(getRawBits() * rhs.getRawBits())
    return (&new);
}

// Fixed &operator/(Fixed const & rhs);
Fixed &Fixed::operator/(Fixed const & rhs)
{
    Fixed new = Fixed(getRawBits() / rhs.getRawBits())
    return (&new);
}


// }

// Fixed Fixed::operator+(const Fixed &fixed) const
// {
// 	return (Fixed(this->toFloat() + fixed.toFloat()));
// }

// Fixed Fixed::operator-(const Fixed &fixed) const
// {
// 	return (Fixed(this->toFloat() - fixed.toFloat()));
// }

// Fixed Fixed::operator*(const Fixed &fixed) const
// {
// 	return (Fixed(this->toFloat() * fixed.toFloat()));
// }

// Fixed Fixed::operator/(const Fixed &fixed) const
// {
// 	return (Fixed(this->toFloat() / fixed.toFloat()));
// }

// Fixed &Fixed::operator++()
// {
// 	this->_value++;
// 	return (*this);
// }

// Fixed Fixed::operator++(int)
// {
// 	Fixed tmp(*this);
// 	operator++();
// 	return (tmp);
// }

// Fixed &Fixed::operator--()
// {
// 	this->_value--;
// 	return (*this);
// }

// Fixed Fixed::operator--(int)
// {
// 	Fixed tmp(*this);
// 	operator--();
// 	return (tmp);
// }

// Fixed &Fixed::min(Fixed &a, Fixed &b)
// {
// 	return (a < b ? a : b);
// }

// const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
// {
// 	return (a < b ? a : b);
// }

// Fixed &Fixed::max(Fixed &a, Fixed &b)
// {
// 	return (a > b ? a : b);
// }

// const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
// {
// 	return (a > b ? a : b);
// }

// std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
// {
//         out << fixed.toFloat();
//         return (out);
// }