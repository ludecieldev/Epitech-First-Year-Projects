/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
** File description:
** lens.c
*/

#include "../../include/my.h"

int my_listlen(char **list)
{
    int i = 0;

    for (; list[i]; i++);
    return i;
}

int my_tablen(char ***list)
{
    int i = 0;

    for (; list[i]; i++);
    return i;
}
