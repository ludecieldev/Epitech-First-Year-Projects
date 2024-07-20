/*
** EPITECH PROJECT, 2023
** B_PSU_100_LIL_1_1_sokoban_alexandre_garbe
** File description:
** move_player.c
** Author:
** ludeciel
*/

#include "../../include/sokoban.h"

void pl_mv(party_info_t *pty_info, player_info_t  *pl, map_info_t *map_info)
{
    switch (pty_info->ch){
        case KEY_UP:
            move_up(map_info, pl);
            break;
        case KEY_DOWN:
            move_down(map_info, pl);
            break;
        case KEY_LEFT:
            move_left(map_info, pl);
            break;
        case KEY_RIGHT:
            move_right(map_info, pl);
            break;
        case ' ':
            reset_map(map_info, pl);
            break;
    }
}
