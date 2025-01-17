#include "Harl.hpp"

int main(void)
{
    Harl test;

    test.complain("info");
    test.complain("debug");
    test.complain("WARNING");
    test.complain("ERROR");
    test.complain("error");
    test.complain("");
    return (1);
}