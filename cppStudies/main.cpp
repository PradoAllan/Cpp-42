#include <iostream>
#include "Studying.hpp"

int	main(void)
{
	Studying	test;
	Studying	another;

	//test.foo = 42;
//	std::cout << test.foo << std::endl;
//	test.bar();

//	std::cout << "foo value before changing its value: " << another.foo << std::endl;
//	another.foo = 42;
//	std::cout << "foo value after changing its value: " << another.foo << std::endl;
//

	test.bar(99999999);
	another.bar(88888888);

	return (1);
}
