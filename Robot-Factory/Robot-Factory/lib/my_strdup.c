/*
** EPITECH PROJECT, 2023
** day08
** File description:
** Placeholder
*/

#include "lib.h"

char *my_strdup(char *src)
{
    char *str;
    int i = 0;

    str = malloc(sizeof(char) * (my_strlen(src)) + 1);
    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
