/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

#include "lib.h"

int is_num(char c)
{
    return (c > 47 && c < 58) || c == '-';
}

int my_str_isnum(char const *str)
{
    int isnum;
    int i;

    i = 0;
    isnum = 1;
    while (str[i] != '\0') {
        if (!(is_num(str[i])))
            isnum = 0;
        i++;
    }
    return isnum;
}
