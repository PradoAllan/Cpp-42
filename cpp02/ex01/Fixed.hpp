#pragma once

class Fixed
{
    private:
        int                 _fixedValue;
        static const int    _bits = 8;
    public:
        Fixed(void);                            //canonical
        Fixed(Fixed const & src);               //canonical
        ~Fixed(void);                           //canonical
        Fixed(int const num);
        Fixed(float const num);

        float   toFloat(void) const;
        int     toInt(void) const;
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        Fixed &operator=(Fixed const & rhs);    //canonical
};

//An overload of the insertion («) operator that inserts a floating-point representation
//of the fixed-point number into the output stream object passed as parameter