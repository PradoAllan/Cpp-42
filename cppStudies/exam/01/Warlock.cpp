#include "Warlock.hpp"

Warlock::~Warlock()
{
    std::cout << getName() << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const std::string &name, const std::string &title)
{
    this->name = name;
    this->title = title;
    std::cout << getName() << ": This looks like another boring day." << std::endl;
}

const std::string &Warlock::getName() const {return (this->name);}

const std::string &Warlock::getTitle() const {return (this->title);}

void Warlock::setTitle(const std::string &title) {this->title = title;}

void Warlock::introduce() const
{
    std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

// void learnSpell(ASpell *spell);
void Warlock::learnSpell(ASpell *spell)
{
    if (spell)
        this->map[spell->getName()] = spell->clone();
}

// void forgetSpell(std::string spell);
void Warlock::forgetSpell(std::string spell)
{
    std::map<std::string, ASpell *>::iterator it = this->map.find(spell);
    if (it != this->map.end())
    {
        delete it->second;
        this->map.erase(spell);
    }
}

// void launchSpell(std::string name, ASpell &ref);
void Warlock::launchSpell(std::string name, ATarget &ref)
{
    if (name.empty())
        return ;
    ASpell *s = this->map[name];
    if (s)
        s->launch(ref);
}