/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_realloc_array.c
** Author:
** ludeciel
*/

#include "amazed.h"

char **my_realloc_array(char **array, char *str)
{
    int i = 0;
    char **new = malloc(sizeof(char *) * (my_arraylen(array) + 2));

    for (i = 0; array[i] != NULL; i++)
        new[i] = my_strdup(array[i]);
    new[i] = my_strdup(str);
    new[i + 1] = NULL;
    free(array);
    return (new);
}
