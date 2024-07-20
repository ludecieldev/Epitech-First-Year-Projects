/*
** EPITECH PROJECT, 2024
** N4S-Prod
** File description:
** main
*/

#include "n4s.h"

void init_n4s(n4s_t *n4s)
{
    n4s->str = NULL;
    n4s->fd = 0;
    n4s->lidar = NULL;
    n4s->speed = 0;
    n4s->direction = 0;
    n4s->speed_max = 0;
    n4s->speed_min = 0;
    n4s->simtime = 0;
}

int main(void)
{
    n4s_t n4s;
    int index = 0;

    init_n4s(&n4s);
    start_simulation(&n4s);
    while (1) {
        get_info_lidar(&n4s);
        lidar_interpreter(n4s.lidar, &n4s);
    }
    stop_simulation(&n4s);
    return 0;
}
