#include "utils.hpp"

void    replaceContent(std::string &s, char *s1, char *s2)
{
    std::string search = s1;
    std::string replace = s2;

    if (search == replace)
        return ;
}

int readFile(char **av)
{
    std::ifstream   file;
    std::string     s;
    std::string     newFileName = av[1]; newFileName += ".replace";
    std::ofstream   newFile;

    file.open(av[1], std::ifstream::in);
    if (!file.is_open())
        return (errorsDealer(FILE_OPEN_FAIL), 0);
    newFile.open(newFileName.c_str(), std::ofstream::out);
    if (!newFile.is_open())
        return (errorsDealer(FILE_OPEN_FAIL), 0);
    while (getline(file, s))
    {
        std::cout << s << std::endl;
        if (!s.empty())
            replaceContent(s, av[2], av[3]);
        newFile << s + '\n';
    }
    file.close();
    return (1);
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (errorsDealer(WRONG_N_PARAMS), 0);
    for (int i = 1; i < ac; i++)
        std::cout << av[i] << std::endl;
    if (!readFile(av))
        errorsDealer(FILE_OPEN_FAIL);
    return (1);
}