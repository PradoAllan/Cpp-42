#pragma once

# include <map>
# include <string>
# include <fstream>
# include <exception>

# define OPEN_FILE_ERROR "Could not open the files..."

class BitcoinExchange
{
    private:
        std::map<std::string, float>    _data;
        std::ifstream                   _csvFile;
        std::ifstream                   _inputFile;

    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange(const std::string inputFile);
        ~BitcoinExchange(void);

        BitcoinExchange &operator=(const BitcoinExchange &src);

        void    populateData(void);

        class OpenFileError : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};