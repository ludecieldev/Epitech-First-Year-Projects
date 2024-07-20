/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** my_arraylen.c
** Author:
** ludeciel
*/

#include "amazed.h"

int my_arraylen(char **array)
{
    int i = 0;

    for (i = 0; array[i] != NULL; i++);
    return i;
}
