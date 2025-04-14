#pragma once

# include <exception>
# include <iostream>

template <typename T>
class Array
{
    private:
        T              *_arr;
        std::size_t     _size;

    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array &src);
        ~Array(void);
        
        Array &operator=(const Array &src);
        T &operator[](std::size_t n);
        const T &operator[](std::size_t n) const;

        std::size_t size(void) const;

        class OutOfBounds: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Index out of bounds.");
                }
        };

        class EmptyArray: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("The array is empty.");
                }
        };
};

# include "Array.tpp"