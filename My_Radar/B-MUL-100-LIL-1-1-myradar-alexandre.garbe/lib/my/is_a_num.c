/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-alexandre.garbe
** File description:
** is_a_num.c
** Author:
** ludeciel
*/

#include "../../include/my_radar.h"

int is_a_num(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    return 1;
}
