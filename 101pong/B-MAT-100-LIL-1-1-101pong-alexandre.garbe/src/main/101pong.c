/*
** EPITECH PROJECT, 2023
** 101pong
** File description:
** 101pong
*/

#include "../../lib/my/my.h"

int pong101(int ac, char **av)
{
    char *endptr1, *endptr2, *endptr3, *endptr4, *endptr5, *endptr6;
    coords_t time_a = {.x = strtof(av[1], &endptr1),
                       .y = strtof(av[2], &endptr2),
                       .z = strtof(av[3], &endptr3)};
    coords_t time_b = {.x = strtof(av[4], &endptr4),
                       .y = strtof(av[5], &endptr5),
                       .z = strtof(av[6], &endptr6)};
    for (int i = 0; av[7][i] != '\0'; i++) {
        if (!(av[7][i] <= '9' && av[7][i] >= '0'))
            return 84;
    }
    int n = atoi(av[7]);
    speed_vector(time_a, time_b, n);
    return 0;
}
