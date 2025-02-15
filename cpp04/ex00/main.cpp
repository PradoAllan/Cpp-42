#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Dog *test = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << test->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    test->makeSound();

    // ... need to implement the WrongCat and WrongAnimal to ensure that I undestand the exercice
    std::cout << "___--- Testing the WRONG ONES ---___" << std::endl;
    std::cout << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();

    std::cout << wrongI->getType() << " " << std::endl;
    std::cout << wrongMeta->getType() << " " << std::endl;

    wrongI->makeSound(); //will output the cat sound!
    wrongMeta->makeSound();

    std::cout << "___--- DELETING EVERYTHING ---___" << std::endl;
    std::cout << std::endl;

    delete meta;
    delete i;
    delete test;
    delete j;
    delete wrongMeta;
    delete wrongI;

    return 0;
}