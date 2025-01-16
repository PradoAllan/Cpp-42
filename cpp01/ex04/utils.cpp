#include "utils.hpp"

void    errorsDealer(std::string message)
{
    if (message.empty())
        std::cerr << NO_MESSAGE << std::endl;
    else
        std::cerr << message << std::endl;
}

void    replaceContent(std::string &s, char *s1, char *s2)
{
    std::string search = s1;
    std::string replace = s2;
    std::string temp;
    int         i = 0;

    while (true)
    {
        i = s.find(s1, i);
        if (i == -1)
            return ;
        s.erase(i, search.length());
        s.insert(i, replace);
    }
}

int fileDealer(char **av)
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
        if (!s.empty())
            replaceContent(s, av[2], av[3]);
        newFile << s + '\n';
    }
    file.close();
    newFile.close();
    return (1);
}