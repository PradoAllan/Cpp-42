#include "Sample.hpp"

Sample::Sample(float pi): _pi(pi) {}

Sample::Sample(float pi, int age): _pi(pi), _age(age) {}

Sample::~Sample(void)
{

}

void    Sample::setAge(int age)
{
    this->_age = age;
}

void    Sample::setAge(void)
{
    this->_age = 42;
}

float   Sample::getPi(void) const
{
    return (this->_pi);
}

int     Sample::getAge(void) const
{
    return (this->_age);
}