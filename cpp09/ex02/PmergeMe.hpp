#pragma once

# include <vector>
# include <deque>
# include <exception>
# include <algorithm>
# include <ctime>
# include <cstdlib>

class PmergeMe
{
    private:
        std::vector<int> _v;
        std::deque<int> _d;
        
        bool    _validateInput(int ac, char **av);
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe &src);
        PmergeMe(int ac, char **av);
        ~PmergeMe(void);

        PmergeMe operator=(const PmergeMe &src);

        void    sortVector(void);
        void    sortDeque(void);
        template <typename T>
        void    showResults(const T &container);

        class InvalidInput : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};