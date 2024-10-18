#include <iostream>
#include "PhoneBook.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor was called!" << std::endl;
}

Sample::~Sample(void)
{
	std::cout << "Destructor was called!" << std::endl;
}

void	Sample::bar(void)
{
	std::cout << "Method bar was called!" << std::endl;
}

/*
Car::Car(char brand[], char model[], int year)
{
	brand = brand;
	model = model;
	year = year;
}
*/
