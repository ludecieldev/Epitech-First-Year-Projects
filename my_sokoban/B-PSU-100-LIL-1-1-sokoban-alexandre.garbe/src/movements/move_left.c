/*
** EPITECH PROJECT, 2023
** B_PSU_100_LIL_1_1_sokoban_alexandre_garbe
** File description:
** move_left.c
** Author:
** ludeciel
*/

#include "../../include/sokoban.h"

static int move_left_short(map_info_t *map_info, player_info_t *player)
{
    if (map_info->map[player->y][player->x - 1] == '#')
        return 0;
    if (map_info->map[player->y][player->x - 1] == 'X' &&
        map_info->map[player->y][player->x - 2] == '#')
        return 0;
    if (map_info->map[player->y][player->x - 1] == ' ') {
        replace_storage(map_info, player);
        map_info->map[player->y][player->x - 1] = 'P';
        player->x--;
        return 0;
    }
    return 1;
}

static int move_left_short_two(map_info_t *map_info, player_info_t *player)
{
    if (map_info->map[player->y][player->x - 1] == 'X' &&
        map_info->map[player->y][player->x - 2] == ' ') {
        replace_storage(map_info, player);
        map_info->map[player->y][player->x - 1] = 'P';
        map_info->map[player->y][player->x - 2] = 'X';
        player->x--;
        return 0;
    }
    if (map_info->map[player->y][player->x - 1] == 'X' &&
        map_info->map[player->y][player->x - 2] == 'O') {
        replace_storage(map_info, player);
        map_info->map[player->y][player->x - 1] = 'P';
        map_info->map[player->y][player->x - 2] = 'X';
        player->x--;
        return 0;
    }
    return 1;
}

static int move_left_short_three(map_info_t *map_info, player_info_t *player)
{
    if (map_info->map[player->y][player->x - 1] == 'O') {
        replace_storage(map_info, player);
        map_info->map[player->y][player->x - 1] = 'P';
        player->x--;
        return 0;
    }
    if (map_info->map[player->y][player->x - 1] == 'X' &&
        map_info->map[player->y][player->x - 2] == 'O') {
        map_info->map[player->y][player->x - 2] = 'X';
        map_info->map[player->y][player->x - 1] = 'P';
        replace_storage(map_info, player);
        player->x--;
        return 0;
    }
    if (map_info->map[player->y][player->x - 1] == 'X' &&
        map_info->map[player->y][player->x - 2] == 'X')
        return 0;
    return 1;
}

static int move_left_space_stor(map_info_t *map_info, player_info_t *player)
{
    if (map_info->map[player->y][player->x - 1] == ' ' &&
        map_info->map[player->y][player->x - 2] == 'O') {
        map_info->map[player->y][player->x - 1] = 'P';
        replace_storage(map_info, player);
        player->x--;
        return 0;
    }
    return 1;
}

void move_left(map_info_t *map_info, player_info_t *player)
{
    if (move_left_space_stor(map_info, player) == 0)
        return;
    if (move_left_short(map_info, player) == 0)
        return;
    if (move_left_short_two(map_info, player) == 0)
        return;
    if (move_left_short_three(map_info, player) == 0)
        return;
}
