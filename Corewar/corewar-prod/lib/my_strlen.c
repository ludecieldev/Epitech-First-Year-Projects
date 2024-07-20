/*
** EPITECH PROJECT, 2023
** Day_04
** File description:
** Placeholder
*/

#include "lib.h"

int my_strlen(char const *str)
{
    int count;
    char c;

    if (!str)
        return 0;
    count = 0;
    c = *str;
    while (c != '\0') {
        str++;
        c = *str;
        count ++;
    }
    return count;
}
