#include <iostream>

void    to_upper(int strnum, char **av)
{
    for (int i = 0; i < strnum; i++)
    {
        for (int j = 0; av[i][j]; j++)
            std::cout << (char)toupper(av[i][j]);
        std::cout << "\n";
    }
    std::cout << tolower('A');
}

int main(int ac, char **av)
{
    if (ac > 1)
        to_upper(ac - 1, av+1);
    return 0;
}