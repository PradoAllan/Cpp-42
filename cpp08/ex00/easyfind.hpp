#pragma once

# include <algorithm>
# include <iostream>

namespace myfunction
{
    template <typename T>
    bool easyfind(T container, const int &value)
    {
        typename T::iterator it;

        it = find(container.begin(), container.end(), value);
        if (it != container.end())
        {
            std::cout << "Element found in the container" << *it << std::endl;
            return (true);
        }
        std::cout << "Element not found in the container" << std::endl;
        return (false);
    }
};