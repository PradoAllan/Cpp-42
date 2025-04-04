#include "iter.hpp"
#include <string>

template <typename T>
void print(T &value)
{
    std::cout << "Printing value: " << value << std::endl;
}

int main(void)
{
    int         intArr[] = {42, 24, 10, 22, 80};
    double      doubleArr[] = {42.42, 10.5, 6.9};
    std::string stringArr[] = {"allan", "prado", "aprado"};

    myfunctions::iter(intArr, 5, myfunctions::showValues<int>);
    myfunctions::iter(doubleArr, 3, myfunctions::showValues<double>);
    myfunctions::iter(stringArr, 3, print<std::string>);
    return (0);
}