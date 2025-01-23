#include "Sample.hpp"

int main(void)
{
    Sample  teste = Sample("Allan");
    Sample  teste2;
    Sample  teste3 = Sample(teste);

    std::cout << teste << std::endl;
    std::cout << teste2 << std::endl;
    std::cout << teste3 << std::endl;

    teste3 = teste2;
    std::cout << teste3 << std::endl;

    return (1);
}