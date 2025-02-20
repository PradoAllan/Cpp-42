#include "Cat.hpp"

Cat::Cat(void): Animal()
{
    this->_type = "CAT";
    this->brain = new Brain();
    std::cout << "A new cat type " << this->_type << " got created by the constructor." << std::endl;
}

Cat::Cat(const Cat &src): Animal(src)
{
    this->_type = "CAT";
    std::cout << "A new cat type " << this->_type << " got created by the copy constructor." << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "A cat type " << this->_type << " was destructed by the destructor." << std::endl;
    delete this->brain;
}

Cat &Cat::operator=(const Cat &src)
{
    std::cout << "Assignment operator from the CAT class got called!" << std::endl;
    if (this != &src)
        Animal::operator=(src);
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "MeowMeow!!" << std::endl;
}