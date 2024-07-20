/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-alexandre.garbe
** File description:
** my_arg_to_int.c
** Author:
** ludeciel
*/

#include "../../include/my_radar.h"

int my_atoi(char *str)
{
    int nb = 0;

    if (str == NULL)
        return 0;
    if (str[0] == '\0')
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != '\n' && str[i] != '\0' && str[i] != ' ')
            nb = nb * 10 + (str[i] - 48);
    return nb;
}
