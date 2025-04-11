#pragma once

# include <exception>
# include <vector>
# include <algorithm>

class Span
{
    private:
        // const unsigned int  _N;
        // long                _counter;
        std::vector<int>    _arr;

        Span(void);
        Span(const Span &src);
        Span &operator=(const Span &src);
    public:
        Span(const unsigned int &N);
        ~Span(void);

        void            addNumber(unsigned int value);
        unsigned int    shortestSpan(void);
        unsigned int    longestSpan(void);
        void            showValues(void);

        template<typename Iterator>
	    void addRange(Iterator begin, Iterator end)
        {
            unsigned int distance = std::distance(begin, end);
            if (_arr.size() + distance > _arr.capacity())
                throw std::runtime_error("Não há espaço suficiente para adicionar todos os números");
            _arr.insert(_arr.end(), begin, end);
	    }

        class OutOfRoom : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class NoExistingElements : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};
