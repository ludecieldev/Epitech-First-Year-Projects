/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-alexandre.garbe
** File description:
** array_travel.c
** Author:
** ludeciel
*/

#include "../../include/my_radar.h"

void array_travel(char **array, global_t *global)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (array[i][0] == TOWER)
            create_tower(array[i], global->tower);
        if (array[i][0] == PLANE)
            create_plane(i, array[i], global);
    }
}
