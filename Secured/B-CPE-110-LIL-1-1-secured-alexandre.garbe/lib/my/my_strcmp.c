/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-organized-alexandre.garbe
** File description:
** my_strcmp.c
** Author:
** ludeciel
*/

#include "../../include/secured.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (; s1[i] != '\0'; i++);
    for (; s2[j] != '\0'; j++);
    if (i != j)
        return (1);
    for (; s1[k] != '\0'; k++) {
        if (s1[k] != s2[k])
            return (1);
    }
    return (0);
}
