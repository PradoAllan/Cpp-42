#include "ScalarConverter.hpp"
#include "dataTypes.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    *this = src;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    if (this != &src)
    *this = src;
    return (*this);
}

static void	ignoreLastF(std::string& str)
{
	if (str.length() < 2)
		return ;
	if (str == "+inf" || str == "-inf" || str == "inf")
		return ;
	if (str.at(str.length() - 1) == 'f')
		str = str.substr(0, str.length() - 1);
}

static void	printChar(double d)
{
	if (d < 0 || d > 127 || std::isnan(d) || std::isinf(d))
		std::cout << "char:\timpossible" << std::endl;
	else if (d < 33 || d > 126)
		std::cout << "char:\tNon displayable" << std::endl;
	else
	{
		char	c = static_cast<char>(d);
		std::cout << "char:\t'" << c << "'"<< std::endl;
	}
}

static void	printInt(double d)
{
	if (d > std::numeric_limits<int>::max()
		|| d < std::numeric_limits<int>::min()
		|| std::isnan(d) || std::isinf(d))
		std::cout << "int:\timpossible" << std::endl;
	else
	{
		int	i = static_cast<int>(d);
		std::cout << "int:\t" << i << std::endl;
	}
}

static void	printFloat(double d)
{
	if ((d > std::numeric_limits<float>::max()
		|| d < -(std::numeric_limits<float>::max()))
		&& !std::isnan(d) && !std::isinf(d))
		std::cout << "float:\timpossible" << std::endl;
	else
	{
		float	f = static_cast<float>(d);
		std::cout << "float:\t" << f << "f" << std::endl;
	}
}

void	ScalarConverter::convert(std::string& literal)
{
	double	d;
	char	*endptr;

	ignoreLastF(literal);
	d = std::strtod(literal.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0' || literal.empty()) {
		std::cout << "char:\timpossible" << std::endl;
		std::cout << "int:\timpossible" << std::endl;
		std::cout << "float:\timpossible" << std::endl;
		std::cout << "double:\timpossible" << std::endl;
	} else {
		printChar(d);
		printInt(d);
		std::cout << std::fixed << std::setprecision(1);
		printFloat(d);
		std::cout << "double:\t" << d <<std::endl;
	}
}






// int checkPseudoLiterals(std::string &s)
// {
//     if (s == "nanf" || s == "+inff" || s == "-inff")
//         return (FLOAT);
//     else if (s == "nan" || s == "+inf" || s == "-inf")
//         return (DOUBLE);
//     return (-1);
// }

// void ScalarConverter::execChar(std::string &s)
// {
//     std::cout << "EXECCHAR()" << std::endl;
//     const char *value;
    
//     value = s.c_str();
//     std::cout << "Casting value to Char: " << static_cast<char>(value[0]) << std::endl;
//     std::cout << "Casting value to Int: " << static_cast<int>(value[0]) << std::endl;
//     std::cout << "Casting value to Float: " << static_cast<float>(value[0]) << std::endl;
//     std::cout << "Casting value to Double: " << static_cast<double>(value[0]) << std::endl;
// }

// static bool CharLimit(char value)
// {
//     if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
// 	{
//         std::cout << "Casting value to Char: impossible" << std::endl;
// 		return (1);
// 	}
// 	return (0);
// }

// void ScalarConverter::execInt(std::string &s)
// {
//     std::cout << "EXECINT()" << std::endl;
//     int value;

//     value = atoi(s.c_str());
//     if (!CharLimit(value))
//     {
//         if (isprint(value))
//             std::cout << "Casting value to Char: " << static_cast<char>(value) << std::endl;
//         else
//             std::cout << "Casting value to Char: Not printable" << std::endl;
//     }
//     std::cout << "Casting value to Int: " << value << std::endl;
//     std::cout << "Casting value to Float: " << static_cast<float>(value) << "f" << std::endl;
//     std::cout << "Casting value to Double: " << static_cast<double>(value) << std::endl;
// }

// static bool IntLimit(int value)
// {
//     if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
// 	{
//         std::cout << "Casting value to Int: impossible" << std::endl;
// 		return (1);
// 	}
// 	return (0);
// }

// void ScalarConverter::execFloat(std::string &s)
// {
//     std::cout << "EXECFLOAT()" << std::endl;
//     float value;
    
//     if (checkPseudoLiterals(s) == FLOAT)
//     {
//         // execute
//         // static void execForScience(std::string &s);
//         std::cout << "For science..." << std::endl;
//         return ;
//     }
//     value = atof(s.c_str());
//     if (!CharLimit(value))
//     {
//         if (isprint(static_cast<char>(value)))
//             std::cout << "Casting value to Char: " << static_cast<char>(value) << std::endl;
//         else
//             std::cout << "Casting value to Char: Not printable" << std::endl;
//     }
//     if (!IntLimit(value))
//         std::cout << "Casting value to Int: " << static_cast<int>(value) << std::endl;
//     std::cout << "Casting value to Float: " << value << "f" << std::endl;
//     std::cout << "Casting value to Double: " << static_cast<double>(value) << std::endl;
// }

// static bool FloatLimit(float value)
// {
//     if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
// 	{
// 		std::cout << "Casting value to Float: impossible" << std::endl;
// 		return (1);
// 	}
// 	return (0);
// }

// void ScalarConverter::execDouble(std::string &s)
// {
//     std::cout << "EXECDOUBLE()" << std::endl;
//     double value;

//     if (checkPseudoLiterals(s) == DOUBLE)
//     {
//         // execute
//         // static void execForFun(std::string &s);
//         std::cout << "For fun..." << std::endl;
//         return ;
//     }
//     value = atof(s.c_str());
//     if (!CharLimit(value))
//     {
//         if (isprint(static_cast<char>(value)))
//             std::cout << "Casting value to Char: " << static_cast<char>(value) << std::endl;
//         else
//             std::cout << "Casting value to Char: Not printable" << std::endl;
//     }
//     if (!IntLimit(value))
//         std::cout << "Casting value to Int: " << static_cast<int>(value) << std::endl;
//     if (!FloatLimit(value))
//         std::cout << "Casting value to Float: " << static_cast<float>(value) << "f" << std::endl;
//     std::cout << "Casting value to Double: " << value << std::endl;
// }

// // void	        execScienceOrFun(std::string &s, int type);
// void    ScalarConverter::execScienceOrFun(std::string &s, int type)
// {
// 	std::cout << "Casting value to Char: impossible" << std::endl;
// 	std::cout << "Casting value to Int: impossible" << std::endl;
// 	if (doubleff(literal) || literal == "nanf")
// 		std::cout << "float: " << literal << std::endl;
// 	else
// 		std::cout << "float: " << literal << "f" << std::endl;
// 	std::cout << "double: ";
// 	if (literal[0] == '+' || literal[0] == '-')
// 		std::cout.write(literal.c_str(), 4) << std::endl;
// 	else
// 		std::cout.write(literal.c_str(), 3) << std::endl;
// }

// bool	ScalarConverter::isDecimalNumeric(std::string &s)
// {
// 	size_t  i;
//     bool dots = false;

//     i = 0;
//     if (s[i] == '+' || s[i] == '-')
//         i++;
//     while (s[i] != '\0') {
//         if (!isdigit(s[i])) {
//             if (s[i] == '.' && !dots)
//                 dots = true;
//             else if (s[i] == 'f' && s[i + 1] == '\0')
//                 return true;
//             else
//                 return false;
//         }
//         i++;
//     }
//     return true;
// }


// int ScalarConverter::checkDataType(std::string &s)
// {
//     const char      *aux;
//     int             pseudo;
//     size_t          size;

//     if (s.empty())
//         return (ERROR);
//     pseudo = checkPseudoLiterals(s);
//     aux = s.c_str();
//     size = s.size();
//     if (size == 1 && !isdigit(aux[0]))
//         return (CHAR);
//     else if (!isDecimalNumeric(s) && pseudo == -1)
//         return (ERROR);
//     else if (s.find('.', 0) < size || pseudo != -1)
//     {
//         if (aux[size - 1] == 'f' || pseudo == FLOAT)
//             return (FLOAT);
//         else
//             return (DOUBLE);
//     }
//     return (INT);
// }

// void ScalarConverter::convert(std::string &s)
// {
//     ScalarConverter aux;

//     switch (aux.checkDataType(s))
//     {
//     case CHAR:
//         aux.execChar(s);
//         break;
//     case INT:
//         aux.execInt(s);
//         break;
//     case FLOAT:
//         aux.execFloat(s);
//         break;
//     case DOUBLE:
//         aux.execDouble(s);
//         break;
//     default:
//         std::cout << "Casting value to Char: not possible" << std::endl;
//         std::cout << "Casting value to Int: not possible" << std::endl;
//         std::cout << "Casting value to Float: not possible" << std::endl;
//         std::cout << "Casting value to Double: not possible" << std::endl;
//         break;
//     }
// }
