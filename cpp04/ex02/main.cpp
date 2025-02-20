#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
    // Nesse caso, se quisermos usar as classes derivadas de Animal, como a Cat e Dog, não vai funcionar.
    // Pois o array sera criado chamando o construtor de Animal(). Então não conseguiremos ter um objeto
    // de Dog ou Cat dentro desse array. Porque um Cat/Dog é um Animal, mas o contrário não...
    // Animal *array = new Animal[20];
    // delete[] array;

    Animal *array[10];

    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            array[i] = new Cat();
        else
            array[i] = new Dog();
    }

    std::cout << std::endl;

	Cat *cat = new Cat();
	Cat *newCat = new Cat(*cat);

	delete cat;
	delete newCat;

	std::cout << std::endl;

    for (int i = 0; i < 10; i++)
        array[i]->makeSound();

    for (int i = 0; i < 10; i++)
        delete array[i];

    return (1);
}