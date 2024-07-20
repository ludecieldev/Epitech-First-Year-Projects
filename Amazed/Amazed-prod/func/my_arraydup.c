/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_arraydup.c
** Author:
** ludeciel
*/

#include "amazed.h"

char **my_arraydup(char **array)
{
    int i = 0;
    char **newarray = malloc(sizeof(char *) * (my_arraylen(array) + 1));

    while (array[i]) {
        newarray[i] = my_strdup(array[i]);
        i++;
    }
    newarray[i] = NULL;
    return newarray;
}
