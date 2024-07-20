/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

#include "lib.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    i = 0;
    if (n == 0)
        return 0;
    if (n < 0)
        n = 999999;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i != n - 1)
        i++;
    if (s1[i] == s2[i])
        return 0;
    if (s1[i] < s2[i])
        return s1[i] - s2[i];
    return s1[i] - s2[i];
}
