/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

#include "lib.h"

int is_upper(char c)
{
    return (c > 64 && c < 91);
}

int my_str_isupper(char const *str)
{
    int isupper;
    int i;

    i = 0;
    isupper = 1;
    while (str[i] != '\0') {
        if (!(is_upper(str[i])))
            isupper = 0;
        i++;
    }
    return isupper;
}
