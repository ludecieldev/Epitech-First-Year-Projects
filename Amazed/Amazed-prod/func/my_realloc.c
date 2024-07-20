/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_realloc.c
** Author:
** ludeciel
*/

#include "amazed.h"

char *my_realloc(char *str, int size)
{
    char *new = malloc(sizeof(char) * size);
    int i = 0;

    for (; str[i] != '\0'; i++)
        new[i] = str[i];
    new[i] = '\0';
    free(str);
    return (new);
}
