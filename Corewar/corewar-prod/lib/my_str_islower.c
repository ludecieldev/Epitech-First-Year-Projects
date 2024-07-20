/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

#include "lib.h"

int is_lower(char c)
{
    return (c > 96 && c < 123);
}

int my_str_islower(char const *str)
{
    int islower;
    int i;

    i = 0;
    islower = 1;
    while (str[i] != '\0') {
        if (!(is_lower(str[i])))
            islower = 0;
        i++;
    }
    return islower;
}
