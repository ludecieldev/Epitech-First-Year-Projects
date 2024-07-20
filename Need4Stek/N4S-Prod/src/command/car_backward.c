/*
** EPITECH PROJECT, 2024
** N4S-Prod
** File description:
** car_backward
*/

#include "n4s.h"

void car_backward(float speed, n4s_t *n4s)
{
    char *str = NULL;

    dprintf(1, "CAR_BACKWARDS:%.2f\n", speed);
    fprintf(stderr, "Car backward at speed %.2f\n", speed);
    str = get_next_line(0);
    if (str == NULL)
        exit(84);
    n4s->str = str;
}
