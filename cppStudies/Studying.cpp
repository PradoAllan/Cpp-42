#include <iostream>
#include "Studying.hpp"

Studying::Studying(void)
{
	std::cout << "Constructor was called!" << std::endl;
	this->foo = 2024; //Usado para referenciar o proprio objeto
	this->bar(42); //Chamando o metodo usando a referencia do objeto chamador

	return ;
}

Studying::~Studying(void)
{
	std::cout << "Destructor was called!" << std::endl;

	return ;
}

void	Studying::bar(int n)
{
	std::cout << "Method bar was called!" << std::endl;
	std::cout << "Method bar is showing foo value: " << this->foo << std::endl;
	std::cout << "Method bar is changind the foo value..." << std::endl;
	this->foo = n;
	std::cout << "Method bar is showing the new foo value: " << this->foo << std::endl;
	// Nesse caso, a referencia do this nao e perdida. Sempre faz referencia
	// ao objeto chamador!!!
	return ;
}

/*
Car::Car(char brand[], char model[], int year)
{
	brand = brand;
	model = model;
	year = year;
}
*/
