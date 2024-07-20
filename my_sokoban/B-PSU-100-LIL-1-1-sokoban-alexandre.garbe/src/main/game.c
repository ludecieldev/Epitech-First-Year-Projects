/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-alexandre.garbe
** File description:
** game.c
** Author:
** ludeciel
*/

#include "../../include/sokoban.h"

void display_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        printw("%s", map[i]);
    }
}

void game(map_info_t *map, player_info_t *player, party_info_t *party_info)
{
    initscr();
    keypad(stdscr, true);
    display_map(map->map);
    noecho();
    party_info->ch = '\0';
    find_player(map, player);
    while (party_info->GameIsOver != true) {
        party_info->ch = getch();
        pl_mv(party_info, player, map);
        clear();
        display_map(map->map);
        refresh();
    }
    endwin();
}
