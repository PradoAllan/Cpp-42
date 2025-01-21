#pragma once

# include <iostream>

class Sample
{
    private:
        const float     _pi;
        int             _age;
    public:
        Sample(float pi);
        Sample(float pi, int age);
        ~Sample(void);

        void    setAge(int age);
        void    setAge(void);

        float   getPi(void) const;
        int     getAge(void) const;
};