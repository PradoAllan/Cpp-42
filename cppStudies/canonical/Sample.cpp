#include "Sample.hpp"

Sample::Sample(void): _name(""), _age(0)
{
    std::cout << "Default constructor got called." << std::endl;
}

Sample::Sample(std::string name): _name(name)
{
    std::cout << "Parametric constructor got called." << std::endl;
}

Sample::Sample(Sample const & src)
{
    std::cout << "Copy constructor got called." << std::endl;

    *this = src;
}

Sample::~Sample(void)
{
    std::cout << "Destructor got called." << std::endl;
}

int Sample::getAge(void) const
{
    return (this->_age);
}

std::string Sample::getName(void) const
{
    return (this->_name);
}

Sample &    Sample::operator=(Sample const & rhs)
{
    std::cout << "operator = method got called." << std::endl;

    if (this != &rhs)
        this->_age = rhs.getAge();
    return (*this);
}

std::ostream & operator<<(std::ostream & o, Sample const & i)
{
    o << "The value of _age is: " << i.getAge();

    return (o);
}