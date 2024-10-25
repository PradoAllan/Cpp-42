#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
    Contact me;

    me.showAttributes();
    me.set_name("Allan");
    me.set_lastName("Prado");
    me.set_phoneNumber("996470211");
    me.showAttributes();
//
//	Sample test;
//
//	test.foo = 42;
//	std::cout << test.foo << std::endl;
//	test.bar();
	return (1);
}
