/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-alexandre.garbe
** File description:
** victory_loss_management.c
** Author:
** ludeciel
*/

#include "../../include/sokoban.h"

static void vic_short(map_info_t *map_info, int i, int j, int *vic_count)
{
    if (map_info->map[i][j] == 'X' && map_info->map_origin[i][j] == 'O')
        vic_count += 1;
}

int check_victory(map_info_t *map_info)
{
    int vic_count = 0;

    for (int i = 0; map_info->map[i] != NULL; i++)
        for (int j = 0; map_info->map[i][j] != '\0'; j++)
            vic_short(map_info, i, j, &vic_count);
    if (vic_count == map_info->nb_storage) {
        return 0;
    }
    return 1;
}

int check_box_loss(map_info_t *map_info, int i, int j, int *box_check)
{
    if (map_info->map[i][j] == 'X') {
        if (map_info->map[i][j + 1] == '#' && map_info->map[i + 1][j] == '#') {
            *box_check += 1;
            return 1;
        }
        if (map_info->map[i][j - 1] == '#' && map_info->map[i + 1][j] == '#') {
            *box_check += 1;
            return 1;
        }
        if (map_info->map[i][j + 1] == '#' && map_info->map[i - 1][j] == '#') {
            *box_check += 1;
            return 1;
        }
        if (map_info->map[i][j - 1] == '#' && map_info->map[i - 1][j] == '#') {
            *box_check += 1;
            return 1;
        }
    }
    return 0;
}

int check_loss(map_info_t *map_info)
{
    int box_check = 0;

    for (int i = 0; map_info->map[i] != NULL; i++)
        for (int j = 0; map_info->map[i][j] != '\0'; j++)
            check_box_loss(map_info, i, j, &box_check);
    if (box_check == map_info->nb_boxes) {
        return 0;
    }
    return 1;
}

void victory_loss_management(map_info_t *map_info, party_info_t *party_info)
{
    if (check_victory(map_info) == 0) {
        party_info->GameIsOver = true;
        party_info->GameIsWon = true;
        printf("Victory !\n");
        endwin();
    }
    if (check_loss(map_info) == 0) {
        party_info->GameIsOver = true;
        party_info->GameIsWon = false;
        printf("Loss !\n");
        endwin();
    }
}
