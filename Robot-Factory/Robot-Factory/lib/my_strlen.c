/*
** EPITECH PROJECT, 2023
** Day_04
** File description:
** Placeholder
*/

#include "lib.h"

int my_strlen(char const *str)
{
    int count = 0;

    if (!str)
        return 0;
    for (; str[count]; count++);
    return count;
}
