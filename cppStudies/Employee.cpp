#include "Employee.hpp"

Employee::Employee()
{
    std::cout << "Constructor was called..." << std::endl;
}

Employee::~Employee()
{
    std::cout << "Destructor was called..." << std::endl;
}

void    Employee::set_name(std::string name)
{
    this->name = name;
}

void    Employee::set_position(std::string position)
{
    this->position = position;
}

void    Employee::set_salary(float salary)
{
    this->salary = salary;
}

void    Employee::set_age(int age)
{
    this->age = age;
}

std::string Employee::get_name()
{
    return (this->name);
}

std::string Employee::get_position()
{
    return (this->position);
}

float   Employee::get_salary()
{
    return(this->salary);
}

int     Employee::get_age()
{
    return (this->age);
}