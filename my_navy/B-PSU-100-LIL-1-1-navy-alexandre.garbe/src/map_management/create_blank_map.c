/*
** EPITECH PROJECT, 2024
** navy
** File description:
** create_blank_map.c
** Author:
** ludeciel
*/

#include "../../include/navy.h"

char **create_blank_map(void)
{
    char **map = malloc(sizeof(char *) * 9);
    int i = 0;
    int j = 0;

    while (i < 8) {
        map[i] = malloc(sizeof(char) * 9);
        while (j < 8) {
            map[i][j] = '.';
            j++;
        }
        map[i][j] = '\0';
        j = 0;
        i++;
    }
    map[i] = NULL;
    return (map);
}
