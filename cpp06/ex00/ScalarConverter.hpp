#pragma once

# include <iostream>
# include <string>
# include <cstdlib>
# include <cerrno>
# include <cstring>
# include <limits>
# include <cmath>
# include <iomanip>
# include <cfloat>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &src);
        ~ScalarConverter(void);
        ScalarConverter &operator=(const ScalarConverter &src);

    public:
        static void convert(std::string &s);
};