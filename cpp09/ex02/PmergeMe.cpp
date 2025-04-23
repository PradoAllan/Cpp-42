#include "PmergeMe.hpp"
#include <iostream>

// bool    _validateInput(int ac, char **av);
bool PmergeMe::_validateInput(int ac, char **av)
{
    double temp;

    for (int i = 1; i < ac; i++)
    {
        temp = std::strtod(av[i], NULL);
        if (temp < 0 || temp > 2147483647)
            return (false);
        this->_v.push_back(static_cast<unsigned int>(temp));
        this->_d.push_back(static_cast<unsigned int>(temp));
    }
    return (true);
}

// PmergeMe(void);
PmergeMe::PmergeMe(void) {}

// PmergeMe(const PmergeMe &src);
PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

// PmergeMe(int ac, char **av);
PmergeMe::PmergeMe(int ac, char **av)
{
    if (!_validateInput(ac, av))
        throw(InvalidInput());
    
    
    std::cout << "Vector: " << std::endl;
    for (size_t i = 0; i < this->_v.size(); i++)
        std::cout << " " << this->_v[i];
    std::cout << std::endl;
    std::cout << "Deque: " << std::endl;
    for (size_t i = 0; i < this->_d.size(); i++)
        std::cout << " " << this->_d[i];
}

// ~PmergeMe(void);
PmergeMe::~PmergeMe(void) {}

// PmergeMe operator=(const PmergeMe &src);
PmergeMe PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        this->_d = src._d;
        this->_v = src._v;   
    }
    return (*this);
}

// virtual const char *what() const throw();
const char *PmergeMe::InvalidInput::what() const throw()
{
    return ("Error: Invalid input.");
}