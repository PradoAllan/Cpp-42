#pragma once

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                 _fixedValue;
        static const int    _bits = 8;
    public:
        Fixed(void);                            //canonical
        Fixed(const Fixed & src);               //canonical
        ~Fixed(void);                           //canonical
        Fixed(int const num);
        Fixed(float const num);

        float   toFloat(void) const;            //converts the fixed-point value to a floating-point value.
        int     toInt(void) const;              //converts the fixed-point value to an integer value.
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        Fixed &operator=(const Fixed & rhs);    //canonical

        bool operator>(const Fixed & rhs) const;
        bool operator<(const Fixed & rhs) const;
        bool operator<=(const Fixed & rhs) const;
        bool operator>=(const Fixed & rhs) const;
        bool operator==(const Fixed & rhs) const;
        bool operator!=(const Fixed & rhs) const;

        Fixed operator+(const Fixed & rhs);
        Fixed operator-(const Fixed & rhs);
        Fixed operator*(const Fixed & rhs);
        Fixed operator/(const Fixed & rhs);

        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);

        static const Fixed &min(Fixed &src1, Fixed &src2);
        static const Fixed &min(const Fixed &src1, const Fixed &src2);
        static const Fixed &max(Fixed &src1, Fixed &src2);
        static const Fixed &max(const Fixed &src1, const Fixed &src2);

};

std::ostream &  operator<<(std::ostream & o, const Fixed & i);