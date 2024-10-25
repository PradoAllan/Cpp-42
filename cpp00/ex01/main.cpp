#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
    //Contact me;
    PhoneBook test;

    test.addNewContact("Allan", "Prado", "aprado", "Sou lindo", "996470211");
    test.addNewContact("Marcelo", "Mota", "mmota", "Sou lindo", "996470211");
    test.addNewContact("Jane", "Batista", "jbatista", "Sou lindo", "996470211");
    test.addNewContact("Rodrigo", "Prado", "rprado", "Sou lindo", "996470211");
    test.addNewContact("Raylane", "Prado", "rayprado", "Sou lindo", "996470211");
    test.addNewContact("Marcos", "Prado", "mprado", "Sou lindo", "996470211");
    test.addNewContact("Sandro", "Prado", "sprado", "Sou lindo", "996470211");
    test.addNewContact("Lucia", "Batista", "lbatista", "Sou lindo", "996470211");
    test.showAllContacts();
    //std::cout << test.get_counter() << std::endl;
    test.addNewContact("Marcos", "Mota", "marmota", "Sou lindo", "996470211");
    test.showAllContacts();
    //std::cout << test.get_counter() << std::endl;
    test.addNewContact("Allan", "Prado", "aprado", "Sou lindo", "996470211");
    test.showAllContacts();

    // me.showAttributes();
    // me.set_name("Allan");
    // me.set_lastName("Prado");
    // me.set_phoneNumber("996470211");
    // me.showAttributes();
//
//	Sample test;
//
//	test.foo = 42;
//	std::cout << test.foo << std::endl;
//	test.bar();
	return (1);
}
