/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

#include "lib.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    if (s1[i] == s2[i])
        return 0;
    if (s1[i] < s2[i])
        return s1[i] - s2[i];
    return s1[i] - s2[i];
}
