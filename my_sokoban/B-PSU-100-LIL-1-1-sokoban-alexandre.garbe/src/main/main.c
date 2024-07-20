/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-alexandre.garbe
** File description:
** main.c
** Author:
** ludeciel
*/

#include "../../include/sokoban.h"

int init_map_info(char **av, map_info_t *map_info)
{
    map_info->map = map_load(av[1], map_info);
    map_info->map_origin = map_load(av[1], map_info);
    map_info->nb_cols = 0;
    map_info->nb_rows = 0;
    map_info->nb_boxes = 0;
    map_info->nb_storage = 0;
    if (map_info->map == NULL)
        return (84);
    return (0);
}

void init_game(party_info_t *party_info)
{
    party_info->GameIsOver = false;
    party_info->nb_moves = 0;
}

void init_player(player_info_t *player)
{
    player->x = 0;
    player->y = 0;
}

int main(int ac, char **av)
{
    map_info_t map_info;
    party_info_t party_info;
    player_info_t player;

    init_map_info(av, &map_info);
    init_game(&party_info);
    init_player(&player);
    if (ac != 2)
        return (84);
    if (init_map_info(av, &map_info) == 84)
        return (84);
    find_player(&map_info, &player);
    game(&map_info, &player, &party_info);
}
