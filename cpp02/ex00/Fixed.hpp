#pragma once

# include <iostream>

class   Fixed
{
    private:
        int                 _fixed;
        static const int    _literal = 8;
    public:
        Fixed(void);                            //Canonical
        Fixed(Fixed const & src);               //Canonical
        ~Fixed(void);                           //Canonical

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        Fixed &operator=(Fixed const & rhs);    //Canonical
};