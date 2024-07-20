/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

#include "lib.h"

char *my_strncpy_dumb(char *dest, char const *src, int n)
{
    int i;

    i = 0;
    while (i < n) {
        dest[i] = src[n - i - 1];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    i = 0;
    while (i < my_strlen(src) && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > my_strlen(src))
        dest[i] = '\0';
    return dest;
}
