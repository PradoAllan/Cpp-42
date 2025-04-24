#pragma once

# include <iostream>
# include <string>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
    protected:
    std::string name;
    std::string effects;
    
    public:
    ASpell(void);
    ASpell(const ASpell &src);
    ASpell(const std::string &name, const std::string &effects);
    virtual ~ASpell(void);
    
    ASpell &operator=(const ASpell &src);
    
    std::string getName(void) const;
    std::string getEffects(void) const;
    
    virtual ASpell *clone(void) const = 0;
    
    void launch(const ATarget &target) const;
};