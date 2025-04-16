#include "Span.hpp"
#include <iostream>

Span::Span(void) {}

Span::Span(const Span &src)
{
    *this = src;
}

Span::Span(const unsigned int &N)
{
    _arr.reserve(N);
    std::cout << "Created a Span with this capacity: " << _arr.capacity() << std::endl;
}

Span::~Span(void) {}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
        *this = src;
    return (*this);
}

void Span::addNumber(unsigned int value)
{
    if (this->_arr.capacity() == this->_arr.size())
        throw Span::OutOfRoom();
    this->_arr.push_back(value);
    std::sort(this->_arr.begin(), this->_arr.end());
}

unsigned int Span::shortestSpan(void)
{
    if (!this->_arr.size())
        throw Span::NoExistingElements();
    return (this->_arr.front());
}

unsigned int Span::longestSpan(void)
{
    if (!this->_arr.size())
        throw Span::NoExistingElements();
    return (this->_arr.back());
}

void Span::showValues(void)
{
    for (size_t i = 0; i < this->_arr.size(); i++)
    {
        std::cout << this->_arr.at(i) << std::endl;
    }
}

const char * Span::OutOfRoom::what() const throw()
{
    return ("No space left in the container...");
}

const char * Span::NoExistingElements::what() const throw()
{
    return ("There are no elements to search for...");
}