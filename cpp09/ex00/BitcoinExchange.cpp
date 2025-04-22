#include "BitcoinExchange.hpp"
#include <iostream>

// BitcoinExchange(void);
BitcoinExchange::BitcoinExchange(void) {}

// BitcoinExchange(const BitcoinExchange &src);
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

// BitcoinExchange(const std::string inputFile);
BitcoinExchange::BitcoinExchange(const std::string inputFile)
{
    this->_csvFile.open("data.csv", std::ifstream::in);
    this->_inputFile.open(inputFile, std::ifstream::in);
    if (!this->_csvFile.is_open() || !this->_inputFile.is_open())
        throw (OpenFileError());
}

// ~BitcoinExchange(void);
BitcoinExchange::~BitcoinExchange(void)
{
    this->_csvFile.close();
    this->_inputFile.close();
}

// BitcoinExchange &operator=(const BitcoinExchange &src);
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
        this->_data = src._data;
    return (*this);
}

// void    populateData(void);
void BitcoinExchange::populateData(void)
{
    std::string s;

    while (getline(this->_csvFile, s))
    {
        std::cout << s << std::endl;
    }
}

// virtual const char *what() const throw();
const char *BitcoinExchange::OpenFileError::what() const throw()
{
    return (OPEN_FILE_ERROR);
}