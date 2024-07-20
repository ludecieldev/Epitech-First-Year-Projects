/*
** EPITECH PROJECT, 2024
** N4S-Prod
** File description:
** start_simulation
*/

#include "n4s.h"

void start_simulation(n4s_t *n4s)
{
    char *str = NULL;

    dprintf(1, "START_SIMULATION\n");
    fprintf(stderr, "Simulation started\n");
    str = get_next_line(0);
    if (str == NULL)
        exit(84);
    n4s->str = str;
}
