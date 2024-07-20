/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myhunter-alexandre.garbe
** File description:
** my_revstr.c
** Author:
** ludeciel
*/

#include "my_hunter.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char *str2 = malloc(sizeof(char) * my_strlen(str));

    while (str[i] != '\0') {
        str2[i] = str[i];
        i++;
    }
    i--;
    while (i >= 0) {
        str[j] = str2[i];
        i--;
        j++;
    }
    return (str);
}
