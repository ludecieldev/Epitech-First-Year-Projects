/*
** EPITECH PROJECT, 2023
** 101pong
** File description:
** main
*/

#include "../../lib/my/my.h"

int main(int ac, char **av)
{
    if (errorcase(ac, av) == 84)
        return 84;
    if (pong101(ac, av) == 84)
        return 84;
    return 0;
}
