#include "PmergeMe.hpp"
#include <iostream>

bool PmergeMe::_validateInput(int ac, char **av)
{
    double temp;
    
    for (int i = 1; i < ac; i++)
    {
        temp = std::strtod(av[i], NULL);
        if (temp < 0 || temp > 2147483647)
        return (false);
        this->_v.push_back(static_cast<int>(temp));
        this->_d.push_back(static_cast<int>(temp));
    }
    return (true);
}

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe::PmergeMe(int ac, char **av)
{
    if (!_validateInput(ac, av))
    throw(InvalidInput());
    
    srand(time(NULL));
    std::cout << "Before: ";
    showResults(this->_v);

    clock_t start1 = clock();
    sortDeque();
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

    clock_t start2 = clock();
    sortVector();
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    showResults(this->_d);
    std::cout << "Time to process a range of " << this->_d.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << this->_v.size() << " elements with std::vector container: " << time2 << " us" << std::endl;
    if (this->_d == std::deque<int>(this->_v.begin(), this->_v.end()))
        std::cout << "The sorted sequences are equal." << std::endl;
    else
        std::cout << "The sorted sequences are not equal." << std::endl;
}

PmergeMe::~PmergeMe(void) {}

PmergeMe PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        this->_d = src._d;
        this->_v = src._v;   
    }
    return (*this);
}

template <typename T>
void PmergeMe::showResults(const T& container)
{
    typename T::const_iterator it = container.begin();
    for (; it != container.end(); it++)
    std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::sortDeque(void)
{
    if (this->_d.size() <= 1)
    return;
    
    std::deque<std::pair<int, int> > pairs;
    int unpaired = -1;
    
    if (this->_d.size() % 2 != 0) {
        unpaired = this->_d.back();
        this->_d.pop_back();
    }
    
    for (size_t i = 0; i < this->_d.size(); i += 2) {
        if (i + 1 < this->_d.size()) {
            if (this->_d[i] < this->_d[i + 1])
            pairs.push_back(std::make_pair(this->_d[i + 1], this->_d[i]));
            else
            pairs.push_back(std::make_pair(this->_d[i], this->_d[i + 1]));
        }
    }
    
    std::deque<std::pair<int, int> > sortedPairs = pairs;
    std::sort(sortedPairs.begin(), sortedPairs.end());
    
    std::deque<int> mainChain;
    std::deque<int> pendChain;
    
    for (size_t i = 0; i < sortedPairs.size(); ++i) {
        mainChain.push_back(sortedPairs[i].first);
        pendChain.push_back(sortedPairs[i].second);
    }
    
    std::deque<int> result;
    if (!mainChain.empty())
    result.push_back(mainChain[0]);
    
    for (size_t i = 1; i < mainChain.size(); ++i) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), mainChain[i]);
        result.insert(pos, mainChain[i]);
    }
    
    for (size_t i = 0; i < pendChain.size(); ++i) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[i]);
        result.insert(pos, pendChain[i]);
    }
    
    if (unpaired != -1) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), unpaired);
        result.insert(pos, unpaired);
    }
    
    this->_d = result;    
}

void PmergeMe::sortVector(void)
{
    if (this->_v.size() <= 1)
    return;
    
    std::vector<std::pair<int, int> > pairs;
    int unpaired = -1;
    
    if (this->_v.size() % 2 != 0) {
        unpaired = this->_v.back();
        this->_v.pop_back();
    }
    
    for (size_t i = 0; i < this->_v.size(); i += 2) {
        if (i + 1 < this->_v.size()) {
            if (this->_v[i] < this->_v[i + 1])
            pairs.push_back(std::make_pair(this->_v[i + 1], this->_v[i]));
            else
            pairs.push_back(std::make_pair(this->_v[i], this->_v[i + 1]));
        }
    }
    
    std::vector<std::pair<int, int> > sortedPairs = pairs;
    std::sort(sortedPairs.begin(), sortedPairs.end());
    
    std::vector<int> mainChain;
    std::vector<int> pendChain;
    
    for (size_t i = 0; i < sortedPairs.size(); ++i) {
        mainChain.push_back(sortedPairs[i].first);
        pendChain.push_back(sortedPairs[i].second);
    }
    
    std::vector<int> result;
    if (!mainChain.empty())
    result.push_back(mainChain[0]);
    
    for (size_t i = 1; i < mainChain.size(); ++i) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), mainChain[i]);
        result.insert(pos, mainChain[i]);
    }
    
    for (size_t i = 0; i < pendChain.size(); ++i) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendChain[i]);
        result.insert(pos, pendChain[i]);
    }
    
    if (unpaired != -1) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), unpaired);
        result.insert(pos, unpaired);
    }
    
    this->_v = result;    
}

const char *PmergeMe::InvalidInput::what() const throw()
{
    return ("Error: Invalid input.");
}