/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-organized-alexandre.garbe
** File description:
** my_strdup.c
** Author:
** ludeciel
*/

#include "../../include/secured.h"

char *my_strdup(char *str)
{
    char *cpy = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    if (str == NULL || cpy == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++)
        cpy[i] = str[i];
    cpy[i] = '\0';
    return (cpy);
}
