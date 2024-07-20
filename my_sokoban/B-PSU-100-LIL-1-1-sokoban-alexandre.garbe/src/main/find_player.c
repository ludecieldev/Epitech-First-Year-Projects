/*
** EPITECH PROJECT, 2023
** B_PSU_100_LIL_1_1_sokoban_alexandre_garbe
** File description:
** find_player.c
** Author:
** ludeciel
*/

#include "../../include/sokoban.h"

void cond_break(map_info_t *mapInfo, int i, int j, player_info_t *player)
{
    if (mapInfo->map[i][j] == 'P') {
        player->x = j;
        player->y = i;
        player->x_origin = j;
        player->y_origin = i;
    }
}

void find_player(map_info_t *mapInfo, player_info_t *player)
{
    for (int i = 0; mapInfo->map[i] != NULL; i++) {
        for (int j = 0; mapInfo->map[i][j] != '\0'; j++) {
            cond_break(mapInfo, i, j, player);
        }
    }
}
