#pragma once

# include <iostream>

namespace myfunctions
{

    template <typename T>
    void showValues(T &value)
    {
        std::cout << "value: " << value << std::endl;
    };

    template <typename T, typename F>
    void iter(T *arr, int lenght, F func)
    {
        for (int i = 0; i < lenght; i++)
        {
            func(arr[i]);
        }
    };
}