/*
** EPITECH PROJECT, 2024
** N4S-Prod
** File description:
** stop_simulation
*/

#include "n4s.h"

void stop_simulation(n4s_t *n4s)
{
    dprintf(1, "STOP_SIMULATION\n");
    fprintf(stderr, "Simulation stopped\n");
    free(n4s->str);
    free(n4s->lidar);
    exit(0);
}
