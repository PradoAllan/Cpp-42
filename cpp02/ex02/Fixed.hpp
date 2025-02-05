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
        Fixed(Fixed const & src);               //canonical
        ~Fixed(void);                           //canonical
        Fixed(int const num);
        Fixed(float const num);

        float   toFloat(void) const;            //converts the fixed-point value to a floating-point value.
        int     toInt(void) const;              //converts the fixed-point value to an integer value.
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        Fixed &operator=(Fixed const & rhs);    //canonical

        bool operator>(Fixed const & rhs) const;
        bool operator<(Fixed const & rhs) const;
        bool operator<=(Fixed const & rhs) const;
        bool operator>=(Fixed const & rhs) const;
        bool operator==(Fixed const & rhs) const;
        bool operator!=(Fixed const & rhs) const;

        Fixed &operator+(Fixed const & rhs);
        Fixed &operator-(Fixed const & rhs);
        Fixed &operator*(Fixed const & rhs);
        Fixed &operator/(Fixed const & rhs);


};

// The 6 comparison operators: >, <, >=, <=, == and !=.
// The 4 arithmetic operators: +, -, *, and /.
// The 4 increment/decrement ++x x++ --i i--
// int x = 5;
// int y = ++x;  // Pré-incremento: x se torna 6 antes da atribuição, então y recebe 6.
// int z = x++;  // Pós-incremento: z recebe o valor atual de x (6), depois x se torna 7.

// int x = 5;
// int y = --x;  // Pré-decremento: x se torna 4 antes da atribuição, então y recebe 4.
// int z = x--;  // Pós-decremento: z recebe o valor atual de x (4), depois x se torna 3.

// ++x (pré-incremento)	Incrementa antes de usar
// x++ (pós-incremento)	Usa o valor atual e depois incrementa
// --x (pré-decremento)	Decrementa antes de usar
// x-- (pós-decremento)	Usa o valor atual e depois decrementa

std::ostream &  operator<<(std::ostream & o, Fixed const & i);