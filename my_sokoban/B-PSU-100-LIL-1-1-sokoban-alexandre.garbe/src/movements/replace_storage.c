/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-alexandre.garbe
** File description:
** replace_storage.c
** Author:
** ludeciel
*/

#include "../../include/sokoban.h"

void replace_storage(map_info_t *map_info, player_info_t *player)
{
    if (map_info->map_origin[player->y][player->x] == 'O')
        map_info->map[player->y][player->x] = 'O';
    else
        map_info->map[player->y][player->x] = ' ';
}
