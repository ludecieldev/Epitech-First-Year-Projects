/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-myls-alexandre.garbe
** File description:
** errorcase
*/

#include "../../lib/my/my.h"

int errorcase(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == NULL)
        return 84;
    return 0;
}
