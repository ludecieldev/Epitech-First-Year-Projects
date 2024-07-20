/*
** EPITECH PROJECT, 2024
** Robot-Factory
** File description:
** my_getnbr_plus.c
** Author:
** ludeciel
*/

#include "lib.h"

unsigned int my_getnbr_plus(char const *str)
{
    unsigned int result = 0;
    int i = 0;
    _Bool is_negative = 0;

    if (str[0] == '-') {
        str++;
        is_negative = 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + str[i] - '0';
        i++;
    }
    if (is_negative)
        result = 0xffffffff - result + 1;
    return result;
}
