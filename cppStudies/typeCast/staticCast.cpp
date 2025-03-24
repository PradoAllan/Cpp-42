#include <iostream>

// int main(void)
// {
//     int a = 42;

//     double b = a;
//     int c = b;
//     int d = static_cast<int>(b);
    
//     return (0);
// }

class Parent {};
class Child1 : public Parent {};
class Child2 : public Parent {};
class Unrelated {};

int main(void)
{
    Child1 a;

    Parent *b = &a;
    Child1 *c = b;
    Child2 *d = static_cast<Child2 *>(b);

    Unrelated *e = static_cast<Unrelated *>(&a); // -> não funciona pois as classes não possuem nenhum tipo de relação. 

    return (0);
}
