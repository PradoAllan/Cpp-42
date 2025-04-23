#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>

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
    this->_inputFile.open(inputFile.c_str(), std::ifstream::in);
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
    std::string date;
    std::string value;
    std::string s;

    while (getline(this->_csvFile, s))
    {
        date = s.substr(0, 10);
        value = s.substr(11, -1);
        this->_data[date] = std::atof(value.c_str()); 
    }
    //this->_csvFile.close();
}

static bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static bool isValidDate(const std::string& line)
{
    if (line.length() < 10)
        return (false);
    std::string date = line.substr(0, 10);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12)
        return (false);
    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (isLeapYear(year))
        daysInMonth[1] = 29;
    if (day < 1 || day > daysInMonth[month - 1])
        return (false);
    return true;
}

// double  getCorrectValue(std::string target);
double BitcoinExchange::getCorrectValue(std::string target)
{
    std::map<std::string, float>::iterator first = this->_data.begin();
	for (; first != this->_data.end(); first++)
		if (first->first == target) 
			return (first->second);
	first = this->_data.lower_bound(target); //searches for the next greater key (date)
	if (first == this->_data.begin()) 
		return (-1.0);
	first--; //we want the smaller one, so the one before the next greater one --> decrement
	return (first->second);
}

// void    readExecInput(void);
void BitcoinExchange::readExecInput(void)
{
    std::string s;
    std::string date;
    std::string delim;
    std::string value;
    double      convertedValue;
    char        *ptr;

    getline(this->_inputFile, s);
    if (s != "date | value")
    {
        std::cerr << "Error: Wrong input format." << std::endl;
        return ;
    }
    while (getline(this->_inputFile, s))
    {
        if (s.empty())
        {
            std::cerr << "Error: Line is empty." << std::endl;
            continue;
        }
        if (s.size() < 14)
        {
            std::cerr << "Error: bad input => " << s << std::endl;
            continue;
        }
        date = s.substr(0, 10);
		delim = s.substr(10, 3);
		value = s.substr(13);
        convertedValue = std::strtod(value.c_str(), &ptr);
        if (delim != " | " || !isValidDate(date) || *ptr != '\0')
            std::cerr << "Error: bad input => " << s << std::endl;
        else if (convertedValue < 0)
            std::cerr << "Error: not a positive number." << std::endl;
        else if (convertedValue > 1000)
            std::cerr << "Error: too large number." << std::endl;
        else
        {
            double targetValue = this->getCorrectValue(date);
            if (targetValue == -1)
			{
				std::cout << "Error: date too early => " << date << std::endl;
				continue;
			}
            std::cout << date << " => " << convertedValue << " = " << convertedValue * targetValue << std::endl;
        }
    }
}

// virtual const char *what() const throw();
const char *BitcoinExchange::OpenFileError::what() const throw()
{
    return (OPEN_FILE_ERROR);
}