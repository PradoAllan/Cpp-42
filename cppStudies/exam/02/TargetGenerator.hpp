#pragma once

#include <string>
#include <iostream>
#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
    private:
        std::map<std::string, ATarget *> map;

        TargetGenerator(const TargetGenerator &src);
        TargetGenerator &operator=(const TargetGenerator &src);
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget *target);
        void forgetTargetType(std::string const &name);
        ATarget* createTarget(std::string const &name);
};