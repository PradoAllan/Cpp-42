#pragma once

# include <iostream>

class Sample
{
    private:
        const float pi;
        int         test;
    public:
        Sample(const float pi, int test);
        //Sample(void);
        //Sample(float pi);
        Sample(const float pi);
        ~Sample(void);
};