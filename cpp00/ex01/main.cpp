#include <iostream>
#include "PhoneBook.hpp"

int	main(void)
{
	Sample test;

	test.foo = 42;
	std::cout << test.foo << std::endl;
	test.bar();
	return (1);
}
