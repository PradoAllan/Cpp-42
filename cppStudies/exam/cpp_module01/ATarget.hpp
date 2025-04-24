#pragma once

# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
    private:
    std::string type;
    
    public:
    ATarget(void);
    ATarget(const ATarget &src);
    ATarget(const std::string &type);
    virtual ~ATarget(void);
    
    ATarget &operator=(const ATarget &src);
    
    const std::string &getType(void) const;
    
    virtual ATarget *clone(void) const = 0;
    
    void getHitBySpell(const ASpell &target) const;
};