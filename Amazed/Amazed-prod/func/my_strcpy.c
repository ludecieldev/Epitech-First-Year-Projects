/*
** EPITECH PROJECT, 2024
** Amazed-prod
** File description:
** my_strcpy
*/

#include "amazed.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
