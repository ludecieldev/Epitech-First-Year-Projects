/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-alexandre.garbe
** File description:
** create_plane.c
** Author:
** ludeciel
*/

#include "../../include/my_radar.h"

static char **plane_pars(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ')
            str[i] = '\n';
    }
    return my_str_to_word_array(str);
}

void create_plane(int i, char *str, global_t *global)
{
    char **line = plane_pars(str);

    if (line[1] == NULL || line[2] == NULL || line[3] == NULL
    || line[4] == NULL || line[5] == NULL || line[6] == NULL)
        return;
    global->plane->x_start = my_atoi(line[1]);
    global->plane->y_start = my_atoi(line[2]);
    global->plane->x_end = my_atoi(line[3]);
    global->plane->y_end = my_atoi(line[4]);
    global->plane->speed = my_atoi(line[5]);
    global->plane->delay = my_atoi(line[6]);
}
