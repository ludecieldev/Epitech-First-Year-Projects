/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-alexandre.garbe
** File description:
** count_words.c
** Author:
** ludeciel
*/

#include "../../include/my_radar.h"

int count_words(char *str, char delim)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == delim)
            count++;
    return count + 1;
}
