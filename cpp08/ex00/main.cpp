#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
    std::vector<int> v;

    v.push_back(4);
    v.push_back(42);
    v.push_back(5);
    v.push_back(56);
    v.push_back(10);
    std::cout << "Testing with container Vector..." << std::endl;
    std::cout << myfunction::easyfind<std::vector<int> >(v, 11) << std::endl;
    std::cout << std::endl;


    std::list<int> l;

    l.push_back(4);
    l.push_back(42);
    l.push_back(5);
    l.push_back(56);
    l.push_back(10);
    std::cout << "Testing with container List..." << std::endl;
    std::cout << myfunction::easyfind<std::list<int> >(l, 42) << std::endl;
    std::cout << std::endl;

    return (0);
}