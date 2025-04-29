#include "TargetGenerator.hpp"

// TargetGenerator(const TargetGenerator &src);
TargetGenerator::TargetGenerator(const TargetGenerator &src)
{
    *this = src;
}

// TargetGenerator &operator=(const TargetGenerator &src);
TargetGenerator &TargetGenerator::operator=(const TargetGenerator &src)
{
    this->map = src.map;
    return (*this);
}

// TargetGenerator();
TargetGenerator::TargetGenerator() {}

// ~TargetGenerator();
TargetGenerator::~TargetGenerator() {}

// void learnTargetType(ATarget *target);
void TargetGenerator::learnTargetType(ATarget *target)
{
    if (target)
        this->map[target->getType()] = target->clone();
}

// void forgetTargetType(std::string const &name);
void TargetGenerator::forgetTargetType(std::string const &name)
{
    std::map<std::string, ATarget *>::iterator it = this->map.find(name);
    if (it != this->map.end())
    {
        delete it->second;
        this->map.erase(name);
    }
}

// ATarget* createTarget(std::string const &name);
ATarget *TargetGenerator::createTarget(std::string const &name)
{
    std::map<std::string, ATarget *>::iterator it = this->map.find(name);
    if (it != this->map.end())
        return (this->map[name]);
    return (NULL);
    // ATarget *t = this->map[name];
    // if (t)
    //     return (t->clone());
    // return (NULL);
}