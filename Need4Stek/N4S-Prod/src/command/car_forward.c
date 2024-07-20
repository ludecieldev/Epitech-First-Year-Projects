/*
** EPITECH PROJECT, 2024
** N4S-Prod
** File description:
** car_forward
*/

#include "n4s.h"

void car_forward(float speed, n4s_t *n4s)
{
    char *str = NULL;

    dprintf(1, "CAR_FORWARD:%.2f\n", speed);
    fprintf(stderr, "Car forward at speed %.2f\n", speed);
    str = get_next_line(0);
    if (str == NULL)
        exit(84);
    n4s->str = str;
}
