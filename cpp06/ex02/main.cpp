#include <iostream>
#include <cstdlib>
#include <exception>
#include <ctime>

class Base
{
    private:

    public:
        virtual ~Base(void) {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void)
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
    

    // A *a;
    // B *b;
    // C *c;

    // try
    // {
    //     a = dynamic_cast<A*>(p);
    //     if (a)
    //     {
    //         std::cout << "Found!!" << std::endl;
    //         std::cout << "The Base pointer is a instance of A." << std::endl;
    //     }
    //     else
    //         std::cout << "WRONG..." << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     try
    //     {
    //         b = dynamic_cast<B*>(p);
    //         std::cout << "Found!!" << std::endl;
    //         std::cout << "The Base pointer is a instance of B." << std::endl;
    //     }
    //     catch (std::exception &e)
    //     {
    //         try
    //         {
    //             c = dynamic_cast<C*>(p);
    //             std::cout << "Found!!" << std::endl;
    //             std::cout << "The Base pointer is a instance of C." << std::endl;
    //         }
    //         catch (std::exception &e)
    //         {
    //             std::cout << "Invalid data type." << std::endl;
    //         }
    //     }
    // }
}

// void identify(Base& p);

int main(void)
{
    Base *object;

    object = generate();
    identify(object);
    delete object;
    return (0);
}