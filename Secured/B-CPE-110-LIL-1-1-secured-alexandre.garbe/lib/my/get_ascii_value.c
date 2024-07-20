/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-alexandre.garbe
** File description:
** get_ascii_value.c
** Author:
** ludeciel
*/

#include "../../include/secured.h"

int get_ascii_value(char *str)
{
    int i = 0;
    int ascii_value = 0;

    for (; str[i] != '\0'; i++)
        ascii_value += str[i];
    return (ascii_value);
}
