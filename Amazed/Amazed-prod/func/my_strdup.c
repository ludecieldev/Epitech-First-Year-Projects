/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** my_strdup.c
** Author:
** ludeciel
*/

#include "amazed.h"

char *my_strdup(char *str)
{
    char *new_string = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    if (new_string == NULL)
        return NULL;
    for (i = 0; str[i] != '\0'; i++)
        new_string[i] = str[i];
    new_string[i] = '\0';
    return new_string;
}
