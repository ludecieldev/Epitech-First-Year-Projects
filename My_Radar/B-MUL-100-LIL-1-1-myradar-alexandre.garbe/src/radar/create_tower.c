/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-alexandre.garbe
** File description:
** create_tower.c
** Author:
** ludeciel
*/

#include "../../include/my_radar.h"

static char **tower_pars(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ')
            str[i] = '\n';
    }
    return my_str_to_word_array(str);
}

void create_tower(char *str, tower_t *tower)
{
    char **line = tower_pars(str);

    if (line[1] == NULL || line[2] == NULL || line[3] == NULL)
        return;
    tower->x = my_atoi(line[1]);
    tower->y = my_atoi(line[2]);
    tower->radius = my_atoi(line[3]);
}
