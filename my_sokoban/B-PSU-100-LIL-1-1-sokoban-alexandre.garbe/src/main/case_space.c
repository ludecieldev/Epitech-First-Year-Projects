/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-alexandre.garbe
** File description:
** case_space.c
** Author:
** ludeciel
*/

#include "../../include/sokoban.h"

void reset_map(map_info_t *mapinfo, player_info_t *player)
{
    for (int i = 0; mapinfo->map[i] != NULL; i++)
        for (int j = 0; mapinfo->map[i][j] != '\0'; j++)
            mapinfo->map[i][j] = mapinfo->map_origin[i][j];
    player->x = player->x_origin;
    player->y = player->y_origin;
}
