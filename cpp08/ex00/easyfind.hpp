#pragma once

# include <algorithm>
# include <iostream>

namespace myfunction
{
    template <typename T>
    bool easyfind(T container, const int &value)
    {
        std::iterator<T> it;
        
        it = find(container.begin(), container.end(), value);
        if (it != container.end())
        {
            std::cout << "Element found in the container" << *it << std::endl;
            return (true);
        }
        std::cout << "Element not found in the container" << std::endl;
        return (false);
        // return (find(container.begin(), container.end(), value) ? true : false );
    }
};

// std::vector<int>::iterator it;

// it = find (myvector.begin(), myvector.end(), 30);
// if (it != myvector.end())
//   std::cout << "Element found in myvector: " << *it << '\n';
// else
//   std::cout << "Element not found in myvector\n";