/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** my_strcat.c
** Author:
** ludeciel
*/

#include "amazed.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *new = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (; dest[i] != '\0'; i++)
        new[i] = dest[i];
    for (; src[j] != '\0'; j++)
        new[i + j] = src[j];
    new[i + j] = '\0';
    return (new);
}
