/*
** EPITECH PROJECT, 2024
** navy
** File description:
** map_manager.c
** Author:
** ludeciel
*/

#include "../../include/navy.h"

static void printer(boat_t **boats, char **map, int i)
{
    if (boats[i]->let1 == boats[i]->let2) {
        for (int j = boats[i]->num1; j <= boats[i]->num2; j++) {
            map[boats[i]->let1][j - 1] = boats[i]->size + 48;
        }
    } else {
        for (int j = boats[i]->let1; j <= boats[i]->let2; j++) {
            map[j][boats[i]->num1 - 1] = boats[i]->size + 48;
        }
    }
}

char **map_placer(boat_t **boats)
{
    char **map = create_blank_map();

    for (int i = 0; boats[i]; i++) {
        printer(boats, map, i);
    }
    return (map);
}
