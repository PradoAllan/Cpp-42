#include <iostream>
#include "Span.hpp"

int main(void)
{
    // Span sp = Span(5);
    Span sp(6);

    try
    {
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    sp.showValues();
    std::cout << std::endl;

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\nTeste com 10000 números:" << std::endl;
    Span bigSpan(10000);
    std::vector<int> numbers;
    std::srand(std::time(NULL));
    
    for (int i = 0; i < 10000; ++i) {
        numbers.push_back(std::rand());
    }
    
    bigSpan.addRange(numbers.begin(), numbers.end());
    std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    return 0;
}