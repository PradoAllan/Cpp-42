#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
    this->_type = "WRONG CAT";
    std::cout << "A new Wrongcat type " << this->_type << " got created by the constructor." << std::endl;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src)
{
    this->_type = "WRONG CAT";
    std::cout << "A new Wrongcat type " << this->_type << " got created by the copy constructor." << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "A Wrongcat type " << this->_type << " was destructed by the destructor." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
    std::cout << "Assignment operator from the CAT class got called!" << std::endl;
    if (this != &src)
        WrongAnimal::operator=(src);
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "Wrong MeowMeow!!" << std::endl;
}