#pragma once

# include <string>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &src);
        ~ScalarConverter(void);
        ScalarConverter &operator=(const ScalarConverter &src);

        static void execChar(std::string &s);
        static void execInt(std::string &s);
        static void execFloat(std::string &s);
        static void execDouble(std::string &s);

        int checkDataType(std::string &s);

    public:
        static void convert(std::string &s);
};