#include "SpellBook.hpp"

// SpellBook(const SpellBook &src);
SpellBook::SpellBook(const SpellBook &src)
{
    *this = src;
}

// SpellBook &operator=(const SpellBook &src);
SpellBook &SpellBook::operator=(const SpellBook &src)
{
    this->map = src.map;
    return (*this);
}

// SpellBook();
SpellBook::SpellBook() {}

// ~SpellBook();
SpellBook::~SpellBook() {}

// void learnSpell(ASpell *spell);
void SpellBook::learnSpell(ASpell *spell)
{
    if (spell)
        this->map[spell->getName()] = spell->clone();
}

// void forgetSpell(std::string const &name);
void SpellBook::forgetSpell(std::string const &name)
{
    if (!name.empty())
        return ;
    std::map<std::string, ASpell *>::iterator it = this->map.find(name);
    if (it != this->map.end())
    {
        delete it->second;
        this->map.erase(name);
    }
}

// ASpell* createSpell(std::string const &name);
ASpell *SpellBook::createSpell(std::string const &name)
{
    std::map<std::string, ASpell *>::iterator it = this->map.find(name);
    if (it != this->map.end())
        return (this->map[name]);
    return (NULL);
    // ASpell *s = this->map[name];
    // if (s)
    //     return (s->clone());
    // return (NULL);
}