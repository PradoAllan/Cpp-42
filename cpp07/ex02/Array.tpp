#include "Array.hpp"

// Array(void);
template <typename T>
Array<T>::Array(void): _arr(NULL), _size(0) {}

// Array(unsigned int n);
template <typename T>
Array<T>::Array(unsigned int n): _arr(new T[n]), _size(n) {}

// Array(const Array &src);
template <typename T>
Array<T>::Array(const Array &src): _arr(NULL), _size(0)
{
    *this = src;
}

// ~Array(void);
template <typename T>
Array<T>::~Array(void)
{
    if (this->_arr)
        delete[] this->_arr;
}

// Array &operator=(const Array &src);
template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
    if (this == &src)
        return *this;
    if (!this->_arr)
        throw EmptyArray();
    delete[] this->_arr;

    this->_size = src._size;
    this->_arr = new T[this->_size];
    for (std::size_t i = 0; i < this->_size; ++i)
        this->_arr[i] = src._arr[i];

    return *this;
}

// T &operator[](std::size_t n);
template <typename T>
T &Array<T>::operator[](std::size_t n)
{
    if (!this->_arr)
        throw EmptyArray();
    if (this->_size <= n)
        throw OutOfBounds();
    return (this->_arr[n]);
}

// const T &operator[](std::size_t n) const;
template <typename T>
const T &Array<T>::operator[](std::size_t n) const
{
    if (!this->_arr)
        throw EmptyArray();
    if (this->_size <= n)
        throw OutOfBounds();
    return (this->_arr[n]);
}

// std::size_t size(void) const;
template <typename T>
std::size_t Array<T>::size(void) const
{
    return (this->_size);
}