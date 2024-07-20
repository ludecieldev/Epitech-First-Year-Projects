/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-myls-alexandre.garbe
** File description:
** flag_checker
*/

#include "../../lib/my/my.h"

char *pathfinder(int ac, char **av)
{
    char *path;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-') {
            path = av[i];
            break;
        }
    }
    if (path == NULL)
        path = "./";
    return path;
}

void flag_checker(char **av, int *i, char const *path, int *bo)
{
    for (int j = 0; j <= 7; j++) {
        if (flags[j].flag == av[*i][1]){
            flags[j].p(path);
            *i += 1;
            *bo = 1;
            break;
        }
    }
}

char *flag_identifier(int ac, char **av)
{
    char *path;
    int bo = 0;

    if (ac == 1) {
        my_ls("./");
        return 0;
    }
    path = pathfinder(ac, av);
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-')
            flag_checker(av, &i, path, &bo);
    }
    if (bo == 0)
        my_ls(path);
    return 0;
}
