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