/*
** EPITECH PROJECT, 2024
** N4S-Prod
** File description:
** wheel_dir
*/

#include "n4s.h"

void wheel_dir(n4s_t *n4s, float direction)
{
    char *str = NULL;

    dprintf(1, "WHEELS_DIR:%.2f\n", direction);
    fprintf(stderr, "Wheels direction set to %.2f\n", direction);
    str = get_next_line(0);
    if (str == NULL)
        exit(84);
    n4s->str = str;
}
