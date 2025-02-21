#include "AMateria.hpp"

// AMateria(void);
AMateria::AMateria(void): type("Abstract") {}

// AMateria(const AMateria &src);
AMateria::AMateria(const AMateria &src)
{
    *this = src;
}

// AMateria(std::string const & type);
AMateria::AMateria(std::string const & type): type(type) {}

// ~AMateria(void);
AMateria::~AMateria(void) {}

// AMateria &operator=(const AMateria &src);
AMateria &AMateria::operator=(const AMateria &src)
{
    // if (this != &src)
    //     this->atributo = src.atributo;
    return (*this);
}

// std::string const & getType() const; //Returns the materia type
std::string const &AMateria::getType() const
{
    return (this->type);
}

// virtual AMateria* clone() const = 0;
// Não implementamos pois deixamos isso com as classes que derivam dessa interface

// virtual void use(ICharacter& target);