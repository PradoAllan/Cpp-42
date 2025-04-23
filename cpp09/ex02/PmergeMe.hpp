#pragma once

# include <vector>
# include <deque>
# include <exception>

class PmergeMe
{
    private:
        std::vector<unsigned int> _v;
        std::deque<unsigned int> _d;
        
        bool    _validateInput(int ac, char **av);
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe &src);
        PmergeMe(int ac, char **av);
        ~PmergeMe(void);

        PmergeMe operator=(const PmergeMe &src);

        void    sortVector(void);
        void    sortDeque(void);
        void    showResults(void);

        class InvalidInput : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};