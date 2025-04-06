#pragma once

# include <iostream>
# include <exception>

template <typename T>
class Array
{
    private:
        T               *_array;
        unsigned int    _size;

    public:
        Array(void);
        Array(const Array &src);
        Array(unsigned int n);
        ~Array(void);

        Array &operator=(const Array &src);
        T& operator[](unsigned int n);
        const T& operator[](unsigned int n) const;
        unsigned int getSize() const;
};

# include "Array.tpp"