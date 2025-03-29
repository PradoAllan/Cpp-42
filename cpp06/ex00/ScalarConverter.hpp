#pragma once

# include <string>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &src);
        ~ScalarConverter(void);
        ScalarConverter &operator=(const ScalarConverter &src);

        static void execChar(char value);
        static void execInt(int value);
        static void execFloat(float value);
        static void execDouble(double value);

        int checkDataType(std::string &s);

    public:
        static void convert(std::string &s);
};