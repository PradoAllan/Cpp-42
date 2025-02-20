#include <iostream>

class Foo
{
    public:
        virtual void print(void) const = 0;
};

class Bar: public Foo
{
    public:
        virtual void print(void) const {std::cout << "Hello from Bar!" << std::endl;}
};

class Spam: public Foo
{
    public:
        virtual void print(void) const {std::cout << "Hello from Spam!" << std::endl;}
};

class Eggs: public Foo
{
    public:

};

class Bacon: public Eggs
{
    public:
        virtual void print(void) const {std::cout << "Hello from Bacon!" << std::endl;}
};

int main(void)
{
    //Foo test;
    Bar teste;
    Spam test;
    //Eggs egg;
    Bacon bacon;

    test.print();
    teste.print();
    bacon.print();

    return (0);
}