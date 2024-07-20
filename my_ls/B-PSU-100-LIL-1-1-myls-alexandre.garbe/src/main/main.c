/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-myls-alexandre.garbe
** File description:
** main
*/

#include "../../lib/my/my.h"

int main(int ac, char **av)
{
    if (errorcase(ac, av) == 84)
        return 84;
    flag_identifier(ac, av);
    return 0;
}
