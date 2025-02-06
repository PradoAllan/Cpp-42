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
    std::cout << "Copy assignment operator called" << std::endl;
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
    // if (getRawBits() > rhs.getRawBits())
    //     return (true);
    // return (false);
    return ((getRawBits() > rhs.getRawBits()) ? true : false);
    //return ((getRawBits() > rhs.getRawBits()));
}

bool Fixed::operator<(const Fixed & rhs) const
{
    // if (getRawBits() < rhs.getRawBits())
    //     return (true);
    // return (false);
    return ((getRawBits() < rhs.getRawBits()) ? true : false);
    //return ((getRawBits() < rhs.getRawBits()));
}

bool Fixed::operator<=(const Fixed & rhs) const
{
    // if (getRawBits() <= rhs.getRawBits())
    //     return (true);
    // return (false);
    return ((getRawBits() <= rhs.getRawBits()) ? true : false);
    //return ((getRawBits() <= rhs.getRawBits()));
}

bool Fixed::operator>=(const Fixed & rhs) const
{
    // if (getRawBits() >= rhs.getRawBits())
    //     return (true);
    // return (false);
    return ((getRawBits() >= rhs.getRawBits()) ? true : false);
    //return ((getRawBits() >= rhs.getRawBits()));
}

bool Fixed::operator==(const Fixed & rhs) const
{
    // if (getRawBits() == rhs.getRawBits())
    //     return (true);
    // return (false);
    return ((getRawBits() == rhs.getRawBits()) ? true : false);
    //return ((getRawBits() == rhs.getRawBits()));
}

bool Fixed::operator!=(const Fixed & rhs) const
{
    // if (getRawBits() != rhs.getRawBits())
    //     return (true);
    // return (false);
    return ((getRawBits() != rhs.getRawBits()) ? true : false);
   // return ((getRawBits() != rhs.getRawBits()));
}


Fixed Fixed::operator+(const Fixed & rhs)
{
    // float   value = toFloat() + rhs.toFloat();
    // Fixed new = Fixed(this->toFloat() + rhs.toFloat());
    // return (new);
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



// Fixed& Fixed::operator++(void) {
// 	++this->rawBits;
// 	return (*this);
// }
// Fixed Fixed::operator++(int) {
// 	Fixed dummy(*this);
// 	operator++();
// 	return (dummy);
// }
// Fixed& Fixed::operator--(void) {
// 	--this->rawBits;
// 	return (*this);
// }
// Fixed Fixed::operator--(int) {
// 	Fixed dummy(*this);
// 	operator--();
// 	return (dummy);
// }

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

// const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2) {
// 	return (n1.getRawBits() >= n2.getRawBits()) ? n1 : n2;
// }
// const Fixed& Fixed::max(Fixed& n1, Fixed& n2) {
// 	return (n1.getRawBits() >= n2.getRawBits()) ? n1 : n2;
// }
// const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2) {
// 	return (n1.getRawBits() <= n2.getRawBits()) ? n1 : n2;
// }
// const Fixed& Fixed::min(Fixed& n1, Fixed& n2) {
// 	return (n1.getRawBits() <= n2.getRawBits()) ? n1 : n2;
// }

const Fixed &Fixed::min(Fixed &src1, Fixed &src2)
{
    return ((src1.getRawBits() <= src2.getRawBits()) ? src1 : src2);
    //return (src1 < src2 ? src1 : src2);
}

const Fixed &Fixed::min(const Fixed &src1, const Fixed &src2)
{
    return ((src1.getRawBits() <= src2.getRawBits()) ? src1 : src2);
    //return (src1 < src2 ? src1 : src2);
}

const Fixed &Fixed::max(Fixed &src1, Fixed &src2)
{
    return ((src1.getRawBits() >= src2.getRawBits()) ? src1 : src2);
    //return (src1 > src2 ? src1 : src2);
}

const Fixed &Fixed::max(const Fixed &src1, const Fixed &src2)
{
    return ((src1.getRawBits() >= src2.getRawBits()) ? src1 : src2);
    //return (src1 > src2 ? src1 : src2);
}



// Fixed::Fixed()
// 	: rawBits(0) {
// 	std::cout << "Default constructor called" << std::endl;
// }

// Fixed::Fixed(int num)
// 	: rawBits(num << fractionalBits) {
// 	std::cout << "Int constructor called" << std::endl;
// }

// Fixed::Fixed(float num)
// 	: rawBits(std::roundf(num * (1 << fractionalBits))) {
// 	std::cout << "Float constructor called" << std::endl;
// }

// Fixed::Fixed(const Fixed& other) {
// 	std::cout << "Copy constructor called" << std::endl;

// 	*this = other;
// }

// Fixed& Fixed::operator=(const Fixed& other) {
// 	if (this != &other) {
// 		std::cout << "Copy assignment operator called" << std::endl;
// 		this->rawBits = other.rawBits;
// 	}

// 	return (*this);
// }

// int Fixed::getRawBits(void) const {
// 	return (this->rawBits);
// }

// Fixed::~Fixed() {
// 	std::cout << "Destructor called" << std::endl;
// }

// int Fixed::toInt(void) const {
// 	return (this->rawBits >> fractionalBits);
// }

// float Fixed::toFloat(void) const {
// 	return (static_cast<float>(rawBits) / (1 << fractionalBits));
// }

// Fixed Fixed::operator+(const Fixed& other) {
// 	Fixed dummy;

// 	dummy.rawBits = (this->rawBits + other.rawBits);
// 	return (dummy);
// }

// Fixed Fixed::operator-(const Fixed& other) {
// 	Fixed dummy;

// 	dummy = (this->rawBits - other.rawBits);
// 	return (dummy);
// }

// Fixed Fixed::operator*(const Fixed& other) {
// 	Fixed dummy;

// 	dummy.rawBits = (this->rawBits * other.rawBits >> fractionalBits);
// 	return (dummy);
// }

// Fixed Fixed::operator/(const Fixed& other) {
// 	Fixed dummy;

// 	if (other.rawBits == 0) {
// 		std::cerr << "Error: Division by zero." << std::endl;

// 		return (0);
// 	}

// 	dummy.rawBits = ((this->rawBits << fractionalBits) / other.rawBits);
// 	return (dummy);
// }

// bool Fixed::operator<(const Fixed &other) const {
// 	return (this->rawBits < other.rawBits);
// }

// bool Fixed::operator>(const Fixed &other) const {
// 	return (this->rawBits > other.rawBits);
// }

// bool Fixed::operator<=(const Fixed &other) const {
// 	return (this->rawBits <= other.rawBits);
// }

// bool Fixed::operator>=(const Fixed &other) const {
// 	return (this->rawBits >= other.rawBits);
// }

// bool Fixed::operator==(const Fixed& other) const {
// 	return (this->rawBits == other.rawBits);
// }

// bool Fixed::operator!=(const Fixed& other) const {
// 	return (this->rawBits != other.rawBits);
// }


// Fixed& Fixed::operator++(void) {
// 	++this->rawBits;
// 	return (*this);
// }

// Fixed Fixed::operator++(int) {
// 	Fixed dummy(*this);
// 	operator++();
// 	return (dummy);
// }

// Fixed& Fixed::operator--(void) {
// 	--this->rawBits;
// 	return (*this);
// }

// Fixed Fixed::operator--(int) {
// 	Fixed dummy(*this);
// 	operator--();
// 	return (dummy);
// }

// std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
//     os << fixed.toFloat();
//     return (os);
// }