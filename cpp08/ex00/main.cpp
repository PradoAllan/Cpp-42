#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> v;

    v.push_back(4);
    v.push_back(42);
    v.push_back(5);
    v.push_back(56);
    v.push_back(10);
    std::cout << myfunction::easyfind<std::vector<int>>(v, 42) << std::endl;

    return (0);
}