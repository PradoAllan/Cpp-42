#include "utils.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
        return (errorsDealer(WRONG_N_PARAMS), 0);
    if (!fileDealer(av))
        errorsDealer(FILE_OPEN_FAIL);
    return (1);
}