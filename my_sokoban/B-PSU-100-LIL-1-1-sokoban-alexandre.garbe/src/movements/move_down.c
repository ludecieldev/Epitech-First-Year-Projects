/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-alexandre.garbe
** File description:
** move_down.c
** Author:
** ludeciel
*/

#include "../../include/sokoban.h"

static int move_down_short(map_info_t *map_info, player_info_t *player)
{
    if (map_info->map[player->y + 1][player->x] == '#')
        return 0;
    if (map_info->map[player->y + 1][player->x] == 'X' &&
        map_info->map[player->y + 2][player->x] == '#')
        return 0;
    if (map_info->map[player->y + 1][player->x] == ' ') {
        replace_storage(map_info, player);
        map_info->map[player->y + 1][player->x] = 'P';
        player->y++;
        return 0;
    }
    return 1;
}

static int move_down_short_two(map_info_t *map_info, player_info_t *player)
{
    if (map_info->map[player->y + 1][player->x] == 'X' &&
        map_info->map[player->y + 2][player->x] == ' ') {
        replace_storage(map_info, player);
        map_info->map[player->y + 1][player->x] = 'P';
        map_info->map[player->y + 2][player->x] = 'X';
        player->y++;
        return 0;
    }
    if (map_info->map[player->y + 1][player->x] == 'X' &&
        map_info->map[player->y + 2][player->x] == 'O') {
        replace_storage(map_info, player);
        map_info->map[player->y + 1][player->x] = 'P';
        map_info->map[player->y + 2][player->x] = 'X';
        player->y++;
        return 0;
    }
    return 1;
}

static int move_down_short_three(map_info_t *map_info, player_info_t *player)
{
    if (map_info->map[player->y + 1][player->x] == 'O') {
        replace_storage(map_info, player);
        map_info->map[player->y + 1][player->x] = 'P';
        player->y++;
        return 0;
    }
    if (map_info->map[player->y + 1][player->x] == 'X' &&
        map_info->map[player->y + 2][player->x] == 'O') {
        map_info->map[player->y + 2][player->x] = 'X';
        map_info->map[player->y + 1][player->x] = 'P';
        replace_storage(map_info, player);
        player->y++;
        return 0;
    }
    if (map_info->map[player->y + 1][player->x] == 'X' &&
        map_info->map[player->y + 2][player->x] == 'X')
        return 0;
    return 1;
}

static int move_down_space_stor(map_info_t *map_info, player_info_t *player)
{
    if (map_info->map[player->y + 1][player->x] == ' ' &&
        map_info->map[player->y + 2][player->x] == 'O') {
        map_info->map[player->y + 1][player->x] = 'P';
        replace_storage(map_info, player);
        player->y++;
        return 0;
    }
    return 1;
}

void move_down(map_info_t *map_info, player_info_t *player)
{
    if (move_down_space_stor(map_info, player) == 0)
        return;
    if (move_down_short(map_info, player) == 0)
        return;
    if (move_down_short_two(map_info, player) == 0)
        return;
    if (move_down_short_three(map_info, player) == 0)
        return;
}
