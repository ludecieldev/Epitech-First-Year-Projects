/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-alexandre.garbe
** File description:
** find_map_info.c
** Author:
** ludeciel
*/

#include "../../include/sokoban.h"

static int find_rows(char *map)
{
    int rows = 0;

    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == '\n')
            rows++;
    return (rows);
}

static int find_cols(char *map)
{
    int cols = 0;

    for (int i = 0; map[i] != '\n'; i++)
        cols++;
    return (cols);
}

static int find_boxes(char *map)
{
    int boxes = 0;

    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == 'X')
            boxes++;
    return (boxes);
}

static int find_storage(char *map)
{
    int storage = 0;

    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == 'O')
            storage++;
    return (storage);
}

static int find_nb_player(char *map)
{
    int player = 0;

    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == 'P')
            player++;
    return (player);
}

int error_handling(char *map, map_info_t *map_info)
{
    if (map_info->nb_boxes != map_info->nb_storage)
        return (84);
    if (map_info->nb_player != 1)
        return (84);
    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] != ' ' && map[i] != '#' && map[i] != 'X' && map[i] != 'O'
        && map[i] != 'P' && map[i] != '\n')
            return (84);
    return (0);
}

int get_info(char *map, map_info_t *map_info)
{
    map_info->nb_rows = find_rows(map);
    map_info->nb_cols = find_cols(map);
    map_info->nb_boxes = find_boxes(map);
    map_info->nb_storage = find_storage(map);
    map_info->nb_player = find_nb_player(map);
    if (error_handling(map, map_info) == 84)
        return (84);
    return (0);
}
