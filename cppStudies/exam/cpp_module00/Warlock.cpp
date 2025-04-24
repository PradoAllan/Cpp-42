#include "Warlock.hpp"

// Warlock(void);
Warlock::Warlock(void) {}
// Warlock(const Warlock &src);
Warlock::Warlock(const Warlock &src)
{
    *this = src;
}
// Warlock operator=(const Warlock &src);
Warlock &Warlock::operator=(const Warlock &src)
{
    if (this != &src)
    {
        this->_name = src.getName();
        this->_title = src.getTitle();   
    }
    return (*this);
}

// Warlock(std::string &name, std::string &title);
Warlock::Warlock(const std::string &name, const std::string &title):
    _name(name),
    _title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}
// Warlock::Warlock(const std::string &name, const std::string &title)
// {
//     this->_name = name;
//     this->_title = title;
//     std::cout << this->getName() << ": This looks like another boring day." << std::endl;
// }


// ~Warlock(void);
Warlock::~Warlock(void)
{
    std::cout << this->getName() << ": My job here is done!" << std::endl;
}

// std::string getName(void) const;
const std::string &Warlock::getName(void) const
{
    return (this->_name);
}

// std::string getTitle(void) const;
const std::string &Warlock::getTitle(void) const
{
    return (this->_title);
}

// void        setTitle(std::string &title);
void Warlock::setTitle(const std::string &title)
{
    this->_title = title;
}

// void introduce(void) const;
void Warlock::introduce(void) const
{
    std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}