#include "Warlock.hpp"

Warlock::Warlock(void) {}
Warlock::Warlock(const Warlock &src)
{
    *this = src;
}
Warlock &Warlock::operator=(const Warlock &src)
{
    if (this != &src)
    {
        this->_name = src.getName();
        this->_title = src.getTitle();   
    }
    return (*this);
}

Warlock::Warlock(const std::string &name, const std::string &title):
    _name(name),
    _title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
    std::cout << this->getName() << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName(void) const
{
    return (this->_name);
}

const std::string &Warlock::getTitle(void) const
{
    return (this->_title);
}

void Warlock::setTitle(const std::string &title)
{
    this->_title = title;
}

void Warlock::introduce(void) const
{
    std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}

// void learnSpell(ASpell *aspell);
void Warlock::learnSpell(ASpell *aspell)
{
    if (aspell)
        this->_spells[aspell->getName()] = aspell->clone();
}

// void forgetSpell(std::string spellName);
void Warlock::forgetSpell(std::string spellName)
{
    // if (spellName.empty())
    //     return ;
    std::map<std::string, ASpell*>::iterator it = this->_spells.begin();
    for(;it != this->_spells.end(); it++)
    {
        if (it->first == spellName)
        {
            delete it->second;
            this->_spells.erase(spellName);
            return ;
        }
    }

    // std::map<std::string, ASpell *>::iterator it = _spells.find(spellName);
    // if (it != _spells.end())
    //     delete it->second;
    // _spells.erase(spellName);
}

// void launchSpell(std::string spellName, ATarget &ref);
void Warlock::launchSpell(std::string spellName, ATarget &ref)
{
    ASpell *spell = this->_spells[spellName];
    if (spell)
        spell->launch(ref);
}