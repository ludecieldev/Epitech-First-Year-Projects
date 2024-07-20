/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-alexandre.garbe
** File description:
** my_strcmp.c
** Author:
** ludeciel
*/

#include "../../include/navy.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int k = 0;

    if (s1 == NULL || s2 == NULL)
        return 1;
    for (; s1[i]; i++);
    for (; s2[j]; j++);
    if (i != j)
        return (1);
    for (; s1[k] != '\0'; k++) {
        if (s1[k] != s2[k])
            return (1);
    }
    return (0);
}
