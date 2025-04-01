#include <iostream>
#include <cstdlib>
#include <exception>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    std::srand(std::time(NULL));
    switch (std::rand() % 3)
    {
        case 0:
            std::cout << "Instance of A was created." << std::endl;
            return (new A());
        case 1:
            std::cout << "Instance of B was created." << std::endl;
            return (new B());
        case 2:
            std::cout << "Instance of C was created." << std::endl;
            return (new C());
        default:
            return (NULL);
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "The Base pointer is a instance of A." << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "The Base pointer is a instance of B." << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "The Base pointer is a instance of C." << std::endl;
    else
        std::cout << "Could not identify..." << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "Found!!" << std::endl;
        std::cout << "The Base pointer is a instance of A." << std::endl;
        (void)a;
    }
    catch (std::exception &e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            std::cout << "Found!!" << std::endl;
            std::cout << "The Base pointer is a instance of B." << std::endl;
            (void)b;
        }
        catch (std::exception &e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                std::cout << "Found!!" << std::endl;
                std::cout << "The Base pointer is a instance of C." << std::endl;
                (void)c;
            }
            catch (std::exception &e)
            {
                std::cout << "Invalid data type." << std::endl;
            }
        }
    }
}

int main(void)
{
    Base *object;

    object = generate();
    std::cout << "Pointer param" << std::endl;
    identify(object);
    std::cout << "Reference param" << std::endl;
    identify(object);
    delete object;
    return (0);
}