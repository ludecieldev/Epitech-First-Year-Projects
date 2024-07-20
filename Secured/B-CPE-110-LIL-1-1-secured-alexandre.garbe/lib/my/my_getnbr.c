/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-organized-alexandre.garbe
** File description:
** my_getnbr.c
** Author:
** ludeciel
*/

#include "../../include/secured.h"

int my_getnbr(char *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    if (str == NULL)
        return (0);
    for (; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            neg = neg * -1;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        nb = nb * 10;
        nb = nb + (str[i] - 48);
    }
    return (nb * neg);
}
