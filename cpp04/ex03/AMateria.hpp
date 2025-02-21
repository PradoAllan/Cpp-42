#pragma once

# include <string>

class AMateria
{
    protected:
        std::string const type;
        //[...]
    public:
        AMateria(std::string const & type);
        AMateria(void);
        AMateria(const AMateria &src);

        ~AMateria(void);

        AMateria &operator=(const AMateria &src);
        //[...]
        std::string const & getType() const; //Returns the materia type
        
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};