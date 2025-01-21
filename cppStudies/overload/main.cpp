#include "Sample.hpp"

int     main(void)
{
    Sample  teste = Sample(3.14159);
    Sample  teste2 = Sample(3.14, 24);
    Sample  teste3 = Sample(teste);

    std::cout << teste.getPi() << " " << teste.getAge() << std::endl;
    std::cout << teste2.getPi() << " " << teste2.getAge() << std::endl;
    std::cout << teste3.getPi() << " " << teste3.getAge() << std::endl;
    return (1);
}