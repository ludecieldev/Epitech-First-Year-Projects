/*
** EPITECH PROJECT, 2021
** *.c
** File description:
** do stuff
*/

#include "../../include/secured.h"

int my_strlen(char const *str)
{
    int len = 0;

    if (str == NULL)
        return (0);
    while (str[len] != '\0') {
        len++;
    }
    return (len);
}
