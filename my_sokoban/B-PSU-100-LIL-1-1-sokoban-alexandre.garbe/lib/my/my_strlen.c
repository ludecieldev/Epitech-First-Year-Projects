/*
** EPITECH PROJECT, 2021
** *.c
** File description:
** do stuff
*/

#include "../../include/sokoban.h"

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return (len);
}
