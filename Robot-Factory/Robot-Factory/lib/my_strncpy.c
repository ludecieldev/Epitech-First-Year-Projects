/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

#include "lib.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    i = 0;
    while (i < my_strlen(src) && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
