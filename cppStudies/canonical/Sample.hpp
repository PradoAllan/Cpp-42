#pragma once

# include <iostream>

class Sample
{
    private:
        const std::string   _name;
        int                 _age;
    public:
        Sample(void);                               // Canonical
        Sample(Sample const & src);                 // Canonical
        Sample(std::string name);       
        ~Sample(void);                              // Canonical

        Sample & operator=(Sample const & rhs);     // Canonical

        std::string getName(void) const;
        int         getAge(void) const;
};

std::ostream &  operator<<(std::ostream & o, Sample const & i);