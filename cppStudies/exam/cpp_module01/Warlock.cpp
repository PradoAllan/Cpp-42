#include "Warlock.hpp"

// Warlock(void);
Warlock::Warlock(void) {}

// Warlock(const Warlock &src);
Warlock::Warlock(const Warlock &src)
{
    *this = src;
}
// Warlock &operator=(const Warlock &src);
Warlock &Warlock::operator=(const Warlock &src)
{
    this->name = src.getName();
    this->title = src.getTitle();
    return (*this);    
}


// Warlock(std::string name, std::string title);
Warlock::Warlock(std::string name, std::string title)
{
    this->name = name;
    this->title = title;
    std::cout << this->getName() << ": This looks like another boring day." << std::endl;
}

// ~Warlock(void);
Warlock::~Warlock(void)
{
    std::cout << this->getName() << ": My job here is done!" << std::endl;
}

// std::string getName(void);
const std::string &Warlock::getName(void) const {return (this->name);}

// std::string getTitle(void);
const std::string &Warlock::getTitle(void) const {return (this->title);}

// void setTitle(const std::string &title);
void Warlock::setTitle(const std::string &title)
{
    this->title = title;
}

//<NAME>: I am <NAME>, <TITLE>!
// void introduce(void) const;
void Warlock::introduce(void) const
{
    std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}

// void learnSpell(ASpell *src);
void Warlock::learnSpell(ASpell *src)
{
    if (src)
        this->arr[src->getName()] = src->clone();
}

// void forgetSpell(std::string spellsName);
void Warlock::forgetSpell(std::string spellsName)
{
    if (spellsName.empty())
        return ;
    std::map<std::string, ASpell *>::iterator it = this->arr.begin();
    for(;it != this->arr.end(); it++)
    {
        if (it->first == spellsName)
        {
            delete it->second;
            this->arr.erase(spellsName);
            return ;
        }
    }
}

// void launchSpell(std::string spellsName, ATarget &target);
void Warlock::launchSpell(std::string spellsName, ATarget &target)
{
    if (spellsName.empty())
        return ;
    ASpell *spell = this->arr[spellsName];
    if (spell)
        spell->launch(target);
}