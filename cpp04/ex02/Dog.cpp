#include "Dog.hpp"

Dog::Dog(void): AAnimal()
{
    this->_type = "DOG";
    this->brain = new Brain();
    std::cout << "A new dog type " << this->_type << " got created by the constructor." << std::endl;
}

Dog::Dog(const Dog &src): AAnimal(src)
{
    this->_type = "DOG";
    std::cout << "A new dog type " << this->_type << " got created by the copy constructor." << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "A dog type " << this->_type << " was destructed by the destructor." << std::endl;
    delete this->brain;
}

Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Assignment operator from the DOG class got called!" << std::endl;
    if (this != &src)
        AAnimal::operator=(src);
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "AuAuAu!!" << std::endl;
}